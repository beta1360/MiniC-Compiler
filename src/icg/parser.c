#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "parser.h"

char *nodeName[]	= {
	"ACTUAL_PARAM",	"ADD",			"ADD_ASSIGN",	"ARRAY_VAR",	"ASSIGN_OP",
	"BREAK_ST",		"CALL",			"CASE_EXP",		"CASE_LST",		"CASE_ST",		
	"COMPOUND_ST",	"CONST_TYPE",	"CONTINUE_ST",	"DCL",			"DCL_ITEM",		
	"DCL_LIST",		"DCL_SPEC",		"DEFAULT_ST",	"DIV",			"DIV_ASSIGN",		
	"EQ",			"ERROR",		"EXP_ST",		"FORMAL_PARA",	"FOR_DCL",		
	"FOR_EXP",		"FOR_INC",		"FOR_ST",		"FUNC_DEF",		"FUNC_HEAD",		
	"GE",			"GT",			"IDENT",		"IF_ELSE_ST",	"IF_ST",			
	"INDEX",		"INT_TYPE",		"LE",			"LOGICAL_AND",	"LOGICAL_NOT",	
	"LOGICAL_OR",	"LT",			"MOD_ASSIGN",	"MUL",			"MUL_ASSIGN",		
	"NE",			"NUMBER",		"PARAM_DCL",	"POST_DEC",		"POST_INC",		
	"PRE_DEC",		"PRE_INC",		"PROGRAM",		"REMAINDER",    "MOD",
    "RETURN_ST",	"SIMPLE_VAR",	"STAT_LIST",	"SUB",			"SUB_ASSIGN",	
    "SWITCH_ST",	"UNARY_MINUS",	"VOID_TYPE",	"WHILE_ST"	
};

char* toString(char* string) {
    char* str;
    str = (char*)malloc(strlen(string) + 1);
    strcpy(str, string);
    return str;
}

Node* buildNode(int tokenNumber, char* tokenValue) {
    Node *ptr;
    ptr = (Node *)malloc(sizeof(Node));
    if (!ptr) {
        printf("ERROR : memory allocation error in buildNode()\n");
        exit(1);
    }
    ptr->token.number = tokenNumber;
    ptr->token.value = tokenValue;
    ptr->noderep = terminal;
    ptr->son = ptr->brother = NULL;
    return ptr;
}


Node* buildTree(int tokenNumber, Node* son) {
    Node *ptr;
    ptr = (Node*) malloc(sizeof(Node));
    if (!ptr) {
        printf("ERROR : memory allocation error in buildTree()\n");
        exit(1);
    }
    ptr->token.number = tokenNumber;
    ptr->token.value = NULL;
    ptr->noderep = nonterm;
    ptr->son = son;
    ptr->brother = NULL;
    return ptr;
}

void appendNext(Node* node, Node* next) {
    Node *ptr = node;
    int i = 1;
    while (ptr->brother != NULL) {
        ptr = ptr->brother;
        i++;
    }
    ptr->brother = next;
}


void printNode(Node *pt, int indent, FILE* astFile) {
    int i;
    for (i = 1; i <= indent; i++) 
        fprintf(astFile, "     ");
    if (pt->noderep == terminal)    
        fprintf(astFile, "Terminal: %s\n", pt->token.value);
    else {
        i = (int)(pt->token.number);
        fprintf(astFile, "Nonterminal: %s\n", nodeName[i]);
    }
}


void printTree(Node *ptr, int indent, FILE* astFile) {
    Node *p = ptr;
    while (p != NULL) {
        printNode(p, indent, astFile);
        if (p->noderep == nonterm) {
            printTree(p->son, indent + 1, astFile);
        }
        p = p->brother;
    }
}

void yyerror(char *msg) {
   printf("%s\n", msg);
}

