#include "Parser.h"

char *nodeName[] = {
	"ACTUAL_PARAM", "ADD", "ADD_ASSIGN", "ARRAY_VAR", "ASSIGN_OP",
	"CALL", "COMPOUND_ST", "CONST_NODE", "DCL", "DCL_ITEM",
	"DCL_LIST", "DCL_SPEC", "DIV", "DIV_ASSIGN", "EQ",
	"ERROR_NODE", "EXP_ST", "FORMAL_PARA", "FUNC_DEF", "FUNC_HEAD",
	"GE", "GT", "IDENT", "IF_ELSE_ST", "IF_ST",
	"INDEX", "INT_NODE", "LE", "LOGICAL_AND", "LOGICAL_NOT",
	"LOGICAL_OR", "LT", "MOD", "MOD_ASSIGN", "MUL",
	"MUL_ASSIGN", "NE", "NUMBER", "PARAM_DCL", "POST_DEC",
	"POST_INC", "PRE_DEC", "PRE_INC", "PROGRAM", "RETURN_ST",
	"SIMPLE_VAR", "STAT_LIST", "SUB", "SUB_ASSIGN", "UNARY_MINUS",
	"VOID_NODE", "WHILE_ST"
};

int ruleName[] = {
	/*	0			1			2			3			4		*/
	0, PROGRAM, 0, 0, 0,
	/*	5			6			7			8			9		*/
	0, FUNC_DEF, FUNC_HEAD, DCL_SPEC, 0,
	/*	10			11			12			13			14		*/
	0, 0, 0, CONST_NODE, INT_NODE,
	/*	15			16			17			18			19		*/
	VOID_NODE, 0, FORMAL_PARA, 0, 0,
	/*	20			21			22			23			24		*/
	0, 0, PARAM_DCL, COMPOUND_ST, DCL_LIST,
	/*	25			26			27			28			29		*/
	DCL_LIST, 0, 0, DCL, 0,
	/*	30			31			32			33			34		*/
	0, DCL_ITEM, DCL_ITEM, SIMPLE_VAR, ARRAY_VAR,
	/*	35			36			37			38			39		*/
	0, 0, STAT_LIST, 0, 0,
	/*	40			41			42			43			44		*/
	0, 0, 0, 0, 0,
	/*	45			46			47			48			49		*/
	0, EXP_ST, 0, 0, IF_ST,
	/*	50			51			52			53			54		*/
	IF_ELSE_ST, WHILE_ST, RETURN_ST, 0, 0,
	/*	55			56			57			58			59		*/
	ASSIGN_OP, ADD_ASSIGN, SUB_ASSIGN, MUL_ASSIGN, DIV_ASSIGN,
	/*	60			61			62			63			64		*/
	MOD_ASSIGN, 0, LOGICAL_OR, 0, LOGICAL_AND,
	/*	65			66			67			68			69		*/
	0, EQ, NE, 0, GT,
	/*	70			71			72			73			74		*/
	LT, GE, LE, 0, ADD,
	/*	75			76			77			78			79		*/
	SUB, 0, MUL, DIV, MOD,
	/*	80			81			82			83			84		*/
	0, UNARY_MINUS, LOGICAL_NOT, PRE_INC, PRE_DEC,
	/*	85			86			87			88			89		*/
	0, INDEX, CALL, POST_INC, POST_DEC,
	/*	90			91			92			93			94		*/
	0, 0, ACTUAL_PARAM, 0, 0,
	/*	95			96			97			*/
	0, 0, 0
};

int errcnt = 0;
int sp;						/* stack pointer */
int stateStack[PS_SIZE];	/* state stack */
int symbolStack[PS_SIZE];	/* symbol stack */
Node* valueStack[PS_SIZE];	/* value stack */

void semantic(int n){
	printf("reduced rule number = %d\n", n);
}

void printToken(struct tokenType token){
	if ((token.number == tident) || (token.number == tnumber))
		printf("%s", token.tokenValue);
	else
		printf("%s", tokenName[token.number]);
}

void dumpStack(){
	int i, start;

	if (sp > 10) start = sp - 10;
	else start = 0;

	printf("\n *** dump state stack :");
	for (i = start; i <= sp; ++i)
		printf(" %d", stateStack[i]);

	printf("\n *** dump symbol stack :");
	for (i = start; i <= sp; ++i)
		printf(" %d", symbolStack[i]);
	printf("\n");
}

void errorRecovery(){
	struct tokenType tok;
	int parenthesisCount, braceCount;
	int i;
	// step 1: skip to the semicolon
	parenthesisCount = braceCount = 0;
	while (1){
		tok = scanner();
		if (tok.number == teof) exit(1);
		if (tok.number == tlparen) parenthesisCount++;
		else if (tok.number == trparen) parenthesisCount--;
		if (tok.number == tlbrace) braceCount++;
		else if (tok.number == trbrace) braceCount--;
		if ((tok.number == tsemicolon) && (parenthesisCount <= 0) && (braceCount <= 0))
			break;
	}

	// step 2: adjust state stack
	for (i = sp; i >= 0; i--){
		// statement_list -> statement_list . statement
		if (stateStack[i] == 36) break; // second statement part

		// statement_list -> . statement
		// statement_list -> . statement_list statement
		if (stateStack[i] == 24) break; // first statement part

		// declaration_list -> declaration_list . declaration
		if (stateStack[i] == 25) break; // second internal dcl

		// declaration_list -> . declaration
		// declaration_list -> . declaration_list declaration
		if (stateStack[i] == 17) break; // internal declaration

		// external declaration
		// external_dcl -> . declaration
		if (stateStack[i] == 2) break; // after first external dcl
		if (stateStack[i] == 0) break; // first external declaration
	}
	sp = i;
}

int meaningfulToken(struct tokenType token){
	if ((token.number == tident) || (token.number == tnumber))
		return 1;
	else return 0;
}

Node *buildNode(struct tokenType token){
	Node *ptr;
	ptr = (Node *)malloc(sizeof(Node));
	if (!ptr) {
		printf("malloc error in buildNode()\n");
		exit(1);
	}
	ptr->token = token;
	ptr->noderep = terminal;
	ptr->son = ptr->brother = NULL;
	return ptr;
}

Node *buildTree(int nodeNumber, int rhsLength){
	int i, j, start;
	Node *first, *ptr;

	i = sp - rhsLength + 1;
	// step 1: find a first index with node in value stack
	while ((i <= sp) && (valueStack[i] == NULL)) i++;
	if (!nodeNumber && i > sp) return NULL;
	// step 2: linking brothers
	while (i <= sp - 1){
		j = i + 1;
		while ((j <= sp) && (valueStack[i] == NULL)) j++;
		if (j <= sp){
			ptr = valueStack[i];
			while (ptr->brother) ptr = ptr->brother;
			ptr->brother = valueStack[i];
		}
		i = j;
	}
	first = (start > sp) ? NULL : valueStack[start];
	// step 3: making subtree root and linking son
	if (nodeNumber){
		ptr = (Node *)malloc(sizeof(Node));
		if (!ptr){
			printf("malloc error in buildTree()\n");
			exit(1);
		}
		ptr->token.number = nodeNumber;
		ptr->token.tokenValue = NULL;
		ptr->noderep = nonterm;
		ptr->son = first;
		ptr->brother = NULL;
		return ptr;
	}
	else return first;
}

void printNode(Node *pt, int indent){
	extern FILE *astFile; int i;

	for (i = 1; i <= indent; i++) fprintf(astFile, " ");
	if (pt->noderep == terminal){
		if ((pt->token.number == tident) || (pt->token.number == tnumber))
			fprintf(astFile, " Terminal: %s", pt->token.tokenValue);
	}
	else {	// nonterminal node
		int i;
		i = (int)(pt->token.number);
		fprintf(astFile, " Nonterminal: %s", nodeName[i]);
	}
	fprintf(astFile, "\n");
}

void printTree(Node *pt, int indent){
	Node *p = pt;
	while (p != NULL){
		printNode(p, indent);
		if (p->noderep == nonterm) printTree(p->son, indent + 5);
		p = p->brother;
	}
}

Node* parser(){
	extern int parsingTable[NO_STATES][NO_SYMBOLS + 1];
	extern int leftSymbol[NO_RULES + 1], rightLength[NO_RULES + 1];
	int entry, ruleNumber, lhs;
	int currentState;
	struct tokenType token;
	Node *ptr;

	sp = 0; stateStack[sp] = 0;	// initial state
	token = scanner();
	while (1){
		currentState = stateStack[sp];
		entry = parsingTable[currentState][token.number];
		if (entry > 0){
			if (++sp > PS_SIZE){
				printf("critical error: parsing stack overflow.\n");
				exit(1);
			}
			symbolStack[sp] = token.number;
			stateStack[sp] = entry;
			valueStack[sp] = meaningfulToken(token) ? buildNode(token) : NULL;
			token = scanner();
		}
		else if (entry < 0){	/* reduce action */
			ruleNumber = -entry;
			if (ruleNumber == GOAL_RULE){	/* accept action */
				// printf(" *** valid source ***\n");
				return valueStack[sp - 1];
			}
			// semantic(ruleNumber);
			ptr = buildTree(ruleName[ruleNumber], rightLength[ruleNumber]);
			sp = sp - rightLength[ruleNumber];
			lhs = leftSymbol[ruleNumber];
			currentState = parsingTable[stateStack[sp]][lhs];
			symbolStack[++sp] = lhs;
			stateStack[sp] = currentState;
			valueStack[sp] = ptr;
		}
		else {	/* error action */
			printf(" === error in source ===\n");
			printf("Current Token : ");
			printToken(token);
			dumpStack();
			errorRecovery();
			token = scanner();
		}
	} /* while(1) */
} /* parser */