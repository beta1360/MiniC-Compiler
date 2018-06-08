#ifndef _UCODE_GEN_
#define _UCODE_GEN_

#include "parser.h"
#include "table.h"

void emit0(char *opcode);
void emit1(char *opcode, int operand);
void emit2(char *opcode, int operand1, int operand2);
void emitJump(char *opcode, char *operand);
void emitSym(char *opcode, int operand1, int operand2, int operand3);
void emitProc(char *label, int operand1, int operand2, int operand3);
void emitLabel(char *label);

void rv_emit(SymbolTable *table, Node *ptr);
void processSimpleVariable(SymbolTable *table, Node *ptr, typeSpecifier spec, typeQualifier qual);
void processArrayVariable(SymbolTable *table, Node *ptr, typeSpecifier spec, typeQualifier qual);
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