#ifndef _UCODE_GEN_
#define _UCODE_GEN_

#include "parser.h"

#define LABEL_LEN		8
#define SYM_TABLE_SIZE  512

typedef enum {
	NONE_SPEC, VOID_SPEC, INT_SPEC
} Specifier;

typedef enum{
	NONE_QUAL, CONST_QUAL, VAR_QUAL, FUNC_QUAL, LOOP_QUAL, SWITCH_QUAL
} Qualifier;

typedef struct _symbolInfo {
	char *id;
	Qualifier qual;
	Specifier spec;
	int width;
	int offset;
	int initialValue;	
} SymbolInfo;

typedef struct _symbolTable {
	int count;
	int offset;
	int base;
	SymbolInfo symbols[SYM_TABLE_SIZE];
	struct _symbolTable *parent;
} SymbolTable;

typedef struct _flowInfo{
	char* startLabel; 
	char* endLabel;
	Qualifier qual;
} FlowInfo;
typedef struct _flowTable {
	int count;
	FlowInfo flows[SYM_TABLE_SIZE];
} FlowTable;

SymbolTable* makeSymbolTable(SymbolTable *parent, int base);
SymbolTable* initSymbolTable();

void findSymbol(char* findId, SymbolTable** foundTable, int* findIdx);
int appendSymbol(SymbolTable* table, Qualifier qual, Specifier spec, char* id, int width, int initialValue);

FlowTable* initFlowTable();
void findFlow(FlowTable* table,Qualifier qual, char** foundStartLabel, char** foundEndLabel);
void topFlow(FlowTable* table, char** foundStartLabel, char** foundEndLabel);
void pushFlow(FlowTable* table,Qualifier qual, char* startLabel, char* endLabel);
void popFlow(FlowTable* table);

void emit0(char *opcode);
void emit1(char *opcode, int operand);
void emit2(char *opcode, int operand1, int operand2);
void emitJump(char *opcode, char *operand);
void emitSym(char *opcode, int operand1, int operand2, int operand3);
void emitProc(char *label, int operand1, int operand2, int operand3);
void emitLabel(char *label);

void rv_emit(SymbolTable *table, Node *ptr);
void processSimpleVariable(SymbolTable *table, Node *ptr, Specifier spec, Qualifier qual);
void processArrayVariable(SymbolTable *table, Node *ptr, Specifier spec, Qualifier qual);
void processDeclaration(SymbolTable *table, Node *ptr);
void processFuncHeader(SymbolTable *table, Node *ptr);
void processOperator(SymbolTable *table, Node *ptr);
void processStatement(SymbolTable *table, Node *ptr);
void processCondition(SymbolTable *table, Node *ptr);
void processFunction(SymbolTable *table, Node *ptr);
int checkPredefined(SymbolTable *table, Node *ptr);
void genLabel(char *label);
void codeGen(Node *root, FILE *ucoFile);

#endif