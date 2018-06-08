#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "icg.h"

int lvalue;
int returnFlag;
int assignFlag;
FILE * file;

SymbolTable* currentTable;
FlowTable* flowTable;

void emit0(char *opcode){
	fprintf(file, "           %s\n", opcode);
}

void emit1(char *opcode, int operand) {
	fprintf(file, "           %-7s %d\n", opcode, operand);
}

void emit2(char *opcode, int operand1, int operand2) {
	fprintf(file, "           %-7s %-7d %d\n", opcode, operand1, operand2);
}

void emitJump(char *opcode, char *operand) {
	fprintf(file, "           %-7s %s\n", opcode, operand);
}

void emitSym(char *opcode, int base, int offset, int size) {
	fprintf(file, "           %-7s %-7d %-7d %d\n", opcode, base, offset, size);
}

void emitProc(char *label, int proc1, int proc2, int proc3) {
	fprintf(file, "%-10s %-7s %-7d %-7d %d\n", label, "proc", proc1, proc2, proc3);
}

void emitLabel(char *label) {
	fprintf(file, "%-10s nop\n", label);
}


void rv_emit(SymbolTable *table, Node *ptr) {
	int stIndex;
	SymbolTable *stTable = table;

	if(ptr->token.number == NUMBER)
		emit1("ldc", atoi(ptr->token.value));
	
	else {
		lookupSymbol(ptr->token.value, &stTable, &stIndex);

		if(stIndex == -1) return;

		SymbolInfo *found = &(stTable->symbols[stIndex]);
		
		if( found->qual == CONST_QUAL ) 
            emit1("ldc", found->initialValue);
		else if( found->width > 1 ) 
            emit2("lda", stTable->base, stTable->symbols[stIndex].offset);
		else 
            emit2("lod", stTable->base, stTable->symbols[stIndex].offset);
	}
}

void processSimpleVariable(SymbolTable *table, Node *ptr, typeSpecifier spec, typeQualifier qual) {
	int sign = 1;

	Node *p = ptr->son;
	Node *q = ptr->brother;

	if(ptr->token.number != SIMPLE_VAR)
		printf("error in SIMPLE_VAR\n");
	
	if(qual == CONST_QUAL){
		int init;

		if(q == NULL){
			printf("%s must have a constant value\n", ptr->token.value);
			return;
		}

		if(q->token.number == UNARY_MINUS){
			sign = -1;
			q = q->son;
		}

		init = sign * atoi(q->token.value);
		insertSymbol(table, qual, spec, p->token.value, 0, init);
	}
	else 
        insertSymbol(table, qual, spec, p->token.value, 1, 0);
}

void processArrayVariable(SymbolTable *table, Node *ptr, typeSpecifier spec, typeQualifier qual) {
	Node *p = ptr->son;
	int size;

	if(ptr->token.number != ARRAY_VAR) {
		fprintf(file, "error in ARRAY_VAR\n");
		return;
	}

	if(p->brother == NULL) {
		fprintf(file, "array size must be specified\n");
		return;
	}
	else
		size = atoi(p->brother->token.value);

	insertSymbol(table, qual, spec, p->token.value, size, 0);
}

void processDeclaration(SymbolTable *table, Node *ptr) {
	typeSpecifier spec;
	typeQualifier qual;
	Node *p, *q;

	if(ptr->token.number != DCL_SPEC) {
		fprintf(file,"Declaration error!\n");
		return;
	}

	spec = INT_SPEC;
	qual = VAR_QUAL;

	p = ptr->son;
	while(p) {
		if(p->token.number == INT_TYPE)
			spec = INT_SPEC;
		else if(p->token.number == CONST_TYPE)
			qual = CONST_QUAL;
		else {
			fprintf(file, "type Error\n");
			return;
		}
		p = p->brother;
	}
	p = ptr->brother;

	if(p->token.number != DCL_ITEM) {
		fprintf(file, "Declaration error! : DCL_ITEM\n");
		return;
	}

	while(p) {
		q = p->son;
		switch(q->token.number) {
			case SIMPLE_VAR:
				processSimpleVariable(table,q,spec,qual);
			    break;
			case ARRAY_VAR:
				processArrayVariable(table,q,spec,qual);
			    break;
			default:
				fprintf(file,"Declaration error! : SIMPLE VAR or ARRAY_VAR\n");
			    break;
		}
		p = p->brother;
	}
}

void processFuncHeader(SymbolTable *table, Node *ptr) {
	typeSpecifier returnType;
	int noArguments;
	Node *p;

	if(ptr->son->token.number != FUNC_HEAD) {
		fprintf(file, "error in processFuncHeader\n");
		return;
	}

	p = ptr->son->son->son;
	while (p) {
		if(p->token.number == INT_TYPE)
			returnType = INT_SPEC;
		else if(p->token.number == VOID_TYPE)
			returnType = VOID_SPEC;
		else {
			fprintf(file, "processFuncHeader error! : returnType\n");
		}
		p = p->brother;
	}
	p = ptr->son->son->brother->brother;
	p = p->son;

	noArguments = 0;

	while(p) {
		noArguments++;
		p = p->brother;
	}
	insertSymbol(table, FUNC_QUAL, returnType, ptr->son->son->brother->token.value,noArguments,0);
}

void processFunction(SymbolTable *table, Node *ptr) { 
	Node *p;

	SymbolTable * newTable = createSymbolTable(table, table->base+1);
	//parameter 처리
	if(ptr->son->son->brother->brother->son) {
		for(p = ptr->son->son->brother->brother->son; p; p = p->brother) {
			if(p->token.number == PARAM_DCL)
				processDeclaration(newTable, p->son);
			else {
				fprintf(file,"error! in processfunction\n");
				return;
			}
		}
	}

	for(p = ptr->son->brother->son->son; p ; p = p->brother) {
		if(p->token.number == DCL)
			processDeclaration(newTable, p->son);
		else {
			fprintf(file,"error! in processfunction2\n");
			return;
		}
	}
	emitProc(ptr->son->son->brother->token.value, newTable->offset-1, newTable->base, 2);

	//지역변수 	
	for(int i = 0; i < newTable->count; i++)
		emitSym("sym", newTable->base, newTable->symbols[i].offset, newTable->symbols[i].width);
	
	for(p = ptr->son; p; p = p->brother) {
		if(p->token.number == COMPOUND_ST)
			processStatement(newTable,p);
	}

	if(!returnFlag) emit0("ret");
	emit0("end");

	free(newTable);
}

void processOperator(SymbolTable *table, Node *ptr) {
	int stIndex;
	
	switch(ptr->token.number) {
		case ASSIGN_OP: 
        {
			Node *lhs = ptr->son, *rhs = ptr->son->brother;

			if(lhs->noderep == nonterm) {
				lvalue = 1;
				processOperator(table, lhs);
				lvalue = 0;
			}

			if(rhs->noderep == nonterm) {
				assignFlag = 1;
				processOperator(table, rhs);
				assignFlag = 0;
			}
			else
				rv_emit(table, rhs);

			if(lhs->noderep == terminal) {
				SymbolTable * stTable = table;
				lookupSymbol(lhs->token.value, &stTable, &stIndex);
				if(stIndex == -1) {
					printf("undefined variable: %s\n", lhs->token.value);
					return;
				}
				emit2("str",stTable->base, stTable->symbols[stIndex].offset);
			}
			else
				emit0("sti");
			break;
		}
		case ADD_ASSIGN: case SUB_ASSIGN: case MUL_ASSIGN:
		case DIV_ASSIGN: case MOD_ASSIGN: 
        {
			Node *lhs = ptr->son, *rhs = ptr->son->brother;
			int nodeNum = ptr->token.number;
			ptr->token.number = ASSIGN_OP;

			if(lhs->noderep == nonterm) {
				lvalue = 1;
				processOperator(table, lhs);
				lvalue = 0;
			}

			ptr->token.number = nodeNum;

			if(lhs->noderep == nonterm)
				processOperator(table, lhs);
			else
				rv_emit(table,lhs);

			if(rhs->noderep == nonterm)
				processOperator(table, rhs);
			else
				rv_emit(table, rhs);

			switch(ptr->token.number) {
				case ADD_ASSIGN: emit0("add"); break;
				case SUB_ASSIGN: emit0("sub"); break;
				case MUL_ASSIGN: emit0("mult"); break;
				case DIV_ASSIGN: emit0("div"); break;
				case MOD_ASSIGN: emit0("mod"); break;
			}

			if(lhs->noderep == terminal) {
				SymbolTable * findTable = table;
				lookupSymbol(lhs->token.value, &findTable, &stIndex);
				if(stIndex == -1) {
					printf("undefined variable: %s\n", lhs->token.value);
					return;
				}
				emit2("str", findTable->base , findTable->symbols[stIndex].offset);
			}
			else
				emit0("sti");
			break;
		}

		case ADD:	case SUB:	case MUL:	case DIV:	case REMAINDER:
		case EQ:	case NE:	case GT:	case LT:	case GE:
		case LE:	case LOGICAL_AND: case LOGICAL_OR:
		{
			Node *lhs = ptr->son, *rhs = ptr->son->brother;

			if(lhs->noderep == nonterm)
				processOperator(table, lhs);
			else
				rv_emit(table, lhs);

			if(rhs->noderep == nonterm)
				processOperator(table, rhs);
			else
				rv_emit(table, rhs);

			switch(ptr->token.number) {
				case ADD:		emit0("add");		break;
				case SUB:		emit0("sub");		break;
				case MUL:		emit0("mult");		break;
				case DIV:		emit0("div");		break;
				case REMAINDER:	emit0("mod");		break;
				case EQ:		emit0("eq");		break;
				case NE:		emit0("ne");		break;
				case GT:		emit0("gt");		break;
				case LT:		emit0("lt");		break;
				case GE:		emit0("ge");		break;
				case LE:		emit0("le");		break;
				case LOGICAL_AND:	emit0("and");	break;
				case LOGICAL_OR:	emit0("or");	break;
			}
			break;
		}
		case UNARY_MINUS:	case LOGICAL_NOT:
		{
			Node *p = ptr->son;
			if(p->noderep == nonterm)
				processOperator(table, p);
			else
				rv_emit(table, p);
			
			switch(ptr->token.number) {
				case UNARY_MINUS:	emit0("neg");	break;
				case LOGICAL_NOT:	emit0("not");	break;
			}
			break;
		}
		case INDEX:
		{
			Node *indexExp = ptr->son->brother;

			if(indexExp->noderep == nonterm)
				processOperator(table, indexExp);
			else
				rv_emit(table,indexExp);

			SymbolTable * findTable = table;
			lookupSymbol(ptr->son->token.value, &findTable, &stIndex);

			if(stIndex == -1) {
				printf("undefined variable: %s\n", ptr->son->token.value);
				return;
			}

			emit2("lda", findTable->base, findTable->symbols[stIndex].offset);
			emit0("add");
			if(!lvalue)
				emit0("ldi");
			break;
		}
		case PRE_INC:	case PRE_DEC:	case POST_INC:	case POST_DEC:
		{
			Node *p = ptr->son;
			Node *q;
			int stIndex;
			SymbolTable *findTable = table;

			if(p->noderep == nonterm)
				processOperator(table, p);
			else
				rv_emit(table, p);

			q = p;
			while(q->noderep != terminal)
				q = q->son;

			if(!q || (q->token.number != IDENT)) {
				fprintf(file,"increment/decrement operators can not be applied in expression\n");
				return;
			}

			lookupSymbol(q->token.value, &findTable, &stIndex);
            if(stIndex == -1) return;
			
			if((assignFlag == 1) && (ptr->token.number == POST_INC || ptr->token.number == POST_DEC))
				emit0("dup");

			switch(ptr->token.number) {
				case PRE_INC:	emit0("inc");	break;
				case PRE_DEC:	emit0("dec");	break;
				case POST_INC:	emit0("inc");	break;
				case POST_DEC:	emit0("dec");	break;
			}

			if((assignFlag == 1)&&(ptr->token.number == PRE_INC || ptr->token.number == PRE_DEC))
				emit0("dup");

			if(p->noderep == terminal) {
				findTable = table;
				lookupSymbol(p->token.value, &findTable, &stIndex);
				if(stIndex == -1)
					return;

				emit2("str", findTable->base , findTable->symbols[stIndex].offset);
			} else if(p->token.number == INDEX) {
				lvalue = 1;
				processOperator(table, p);
				lvalue = 0;
				emit0("swp");
				emit0("sti");
			}
            else printf("error increase/decrease operators\n");
			break;
		}
		case CALL:
		{
			Node *p = ptr->son;
			char *functionName;
			int stIndex;
			int noArguments;

			SymbolTable * findTable = table;
            if(checkPredefined(table,p)) break;
			
            functionName = p->token.value;
			lookupSymbol(functionName, &findTable, &stIndex);
			
			if(stIndex == -1) {
				printf("%s: undefined function\n",functionName);
				break;
			}
			noArguments = findTable->symbols[stIndex].width;
			
			emit0("ldp");
			p = p->brother->son;

			while(p) {
				if(p->noderep == nonterm)
					processOperator(table, p);
				else
					rv_emit(table, p);

				noArguments --;
				p = p->brother;
			}

			if(noArguments > 0) 
				printf("%s: too few actual arguments\n", functionName);
			if(noArguments < 0) 
				printf("%s: too many actual arguments\n", functionName);

			emitJump("call", ptr->son->token.value);
			break;
		}		
	}
}

void processStatement(SymbolTable *table, Node *ptr) {
	Node *p, *q;
	char *startLabel, *endLabel;

	switch(ptr->token.number) {
		case COMPOUND_ST:
			p = ptr->son->brother;
			p = p->son;
			while (p) {
				processStatement(table, p);
				p = p->brother;
			}
			break;
		case EXP_ST:
			if(ptr->son != NULL) processOperator(table, ptr->son);
			break;
		case RETURN_ST:
			if (ptr->son != NULL) {
				p = ptr->son;
				if(p->noderep == nonterm)
					processOperator(table, p);
				else
					rv_emit(table, p);
				emit0("retv");
			}
			else
				emit0("ret");
			returnFlag = 1;
			break;
		case CONTINUE_ST:
			findFlow(flowTable,LOOP_QUAL, &startLabel, &endLabel);
			if(startLabel == 0) {
				printf("continue Error!");
				return;
			}
			emitJump("ujp",startLabel);
			break;
		case BREAK_ST:
			topFlow(flowTable, &startLabel, &endLabel);
			if(startLabel == 0) {
				printf("break error!");
				return;
			}
			emitJump("ujp",endLabel);
			break;
		case IF_ST:
		{
			char label[LABEL_SIZE];

			genLabel(label);
			processCondition(table, ptr->son);
			emitJump("fjp", label);
			processStatement(table, ptr->son->brother);
			emitLabel(label);
		}
		break;
		case IF_ELSE_ST:
		{
			char label1[LABEL_SIZE], label2[LABEL_SIZE]; 
			genLabel(label1);
			genLabel(label2);
			processCondition(table, ptr->son);
			emitJump("fjp", label1);
			processStatement(table,ptr->son->brother);
			emitJump("ujp", label2);
			emitLabel(label1);
			processStatement(table, ptr->son->brother->brother);
			emitLabel(label2);
		}
		break;
		case SWITCH_ST:
		{
			char label1[LABEL_SIZE], label2[LABEL_SIZE], label3[LABEL_SIZE];

			genLabel(label2);
			for(p = ptr->son->brother; p; p = p->brother) {
				switch(p->token.number) {
					case CASE_LST:
						genLabel(label1);
						pushFlow(flowTable, SWITCH_QUAL, label1, label2);
						for(q = p->son; q; q = q->brother) {
							switch(q->token.number) {
								case CASE_ST:
									processCondition(table, ptr->son->son->son);
									emit1("ldc", atoi(q->son->token.value));
									emit0("eq");
									emitJump("tjp",label1);
								break;
								case DEFAULT_ST:
									emitJump("ujp",label1);
								break;
							}
						}
						genLabel(label3);
						emitJump("ujp",label3);
					break;
					case CASE_EXP:
						emitLabel(label1);
						for(q = p->son; q; q=q->brother) 
							processStatement(table,q);
						popFlow(flowTable);
						emitLabel(label3);
					break;
				}
			}
			emitLabel(label2);
		}
		break;
		case FOR_ST:
		{
			char label1[LABEL_SIZE], label2[LABEL_SIZE];

			for(p = ptr->son->son; p; p = p->brother) 
				processOperator(table, p);
			genLabel(label1);
			genLabel(label2);
			pushFlow(flowTable, LOOP_QUAL, label1, label2);
			emitLabel(label1);
			processCondition(table, ptr->son->brother->son);
			emitJump("fjp", label2);
			processStatement(table,ptr->son->brother->brother->brother);
			for(p = ptr->son->brother->brother->son; p; p= p->brother)
				processOperator(table,p);
			emitJump("ujp",label1);
			emitLabel(label2);
			popFlow(flowTable);
		}
		break;
		case WHILE_ST:
		{
			char label1[LABEL_SIZE], label2[LABEL_SIZE];

			genLabel(label1);
			genLabel(label2);
			pushFlow(flowTable, LOOP_QUAL, label1, label2);
			emitLabel(label1);
			processCondition(table, ptr->son);
			emitJump("fjp", label2);
			processStatement(table, ptr->son->brother);
			emitJump("ujp", label1);
			emitLabel(label2);
			popFlow(flowTable);
		}
		break;
		default:
			printf("not yet implements(statement)\n");
			break;
	}
}
void processCondition(SymbolTable *table, Node *ptr) {
	if(ptr->noderep == nonterm)
		processOperator(table, ptr);
	else
		rv_emit(table,ptr);
}

int checkPredefined(SymbolTable *table, Node *ptr) {
	Node *p = ptr;
	char *functionName;
	int noArguments;
	int stIndex;
	SymbolTable* findTable;
	functionName = p->token.value;

	if(strcmp(functionName,"read") == 0) {
		noArguments = 1;
		emit0("ldp");
		p = p->brother->son;
		while(p) {
			if(p->noderep == nonterm)
				processOperator(table, p);
			else {
				findTable = table;
				lookupSymbol(p->token.value, &findTable, &stIndex);
				if(stIndex == -1)
					return 0;
				emit2("lda", findTable->base, findTable->symbols[stIndex].offset);
			}
			noArguments--;
			p = p->brother;
		}

		if(noArguments > 0) printf("%s: too few actual arguments\n", functionName);
		else if(noArguments < 0) printf("%s: too many actual arguments\n", functionName);

		emitJump("call", functionName);
		return 1;
	}
	else if(strcmp(functionName, "write") == 0) {
		noArguments = 1;
		emit0("ldp");
		p = p->brother->son;
		while(p) {
			if(p->noderep == nonterm)
				processOperator(table, p);
			else {
				findTable = table;
				lookupSymbol(p->token.value, &findTable, &stIndex);
				if(stIndex == -1)
					return 0;
				emit2("lod", findTable->base, findTable->symbols[stIndex].offset);
			}
			noArguments--;
			p = p->brother;
		}

		if(noArguments > 0) printf("%s: too few actual arguments\n", functionName);
		else if(noArguments < 0) printf("%s: too many actual arguments\n", functionName);

		emitJump("call", functionName);
		return 1;

	}
	else if( strcmp(functionName,"lf") == 0 ) {
		emitJump("call",functionName);
		return 1;
	}
	
	return 0;
}

void genLabel(char *label) {
	static int labelNum = 0;
	sprintf(label, "$$%d", labelNum++);
}

void codeGen(Node *root, FILE *ucoFile) {
	Node *p = root;
	int i;
	file = ucoFile;
	SymbolTable *globalTable = initSymbolTable();
	flowTable = initFlowTable();

	for(p = root->son; p; p = p->brother) {
		if(p->token.number == DCL)
			processDeclaration(globalTable, p->son);
		else if(p->token.number == FUNC_DEF)
			processFuncHeader(globalTable, p);
	}
	
	for(i = 0 ; i < globalTable->count; i++) 
		if( globalTable->symbols[i].qual == VAR_QUAL || globalTable->symbols[i].qual == CONST_QUAL )
			emitSym("sym",globalTable->base, globalTable->symbols[i].offset, globalTable->symbols[i].width);
	
	for( p = root->son; p; p = p->brother ) 
    	if(p->token.number == FUNC_DEF)
			processFunction(globalTable,p);
	
	emit1("bgn", globalTable->offset - 1);
	emit0("ldp");
	emitJump("call","main");
	emit0("end");
}