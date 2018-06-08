#include "table.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

SymbolTable* createSymbolTable(SymbolTable *parent, int base) {
	SymbolTable* table = (SymbolTable *)malloc(sizeof(SymbolTable));

	table->parent = parent;
	table->offset = 1;
	table->base   = base;
	table->count  = 0;

	return table;
}

SymbolTable* initSymbolTable() {
	return createSymbolTable(NULL, 1);
}

void lookupSymbol(char *findId, SymbolTable** foundTable, int* findIdx) {
	if((*foundTable) == NULL) {
		*findIdx = -1;
		return;
	}

	for(int i = 0; i < (*foundTable)->count; i++) {
		if(strcmp((*foundTable)->symbols[i].id, findId) == 0) {
			*findIdx = i; 
			return;
		}
	}

	(*foundTable) = (*foundTable)->parent;
	lookupSymbol(findId,foundTable, findIdx);
}

int insertSymbol(SymbolTable *table, typeQualifier qual, typeSpecifier spec, char *id, int width, int initialValue) {
	int symIdx;
	SymbolTable *findTable = table;
	lookupSymbol(id,&findTable,&symIdx);
	
	if (findTable == table && symIdx != -1) {
		printf("returned\n");
		return symIdx;
	}

	int top = table->count;
	table->symbols[top].id = id;
	table->symbols[top].qual = qual;
	table->symbols[top].spec = spec;
	table->symbols[top].width = width;
	table->symbols[top].offset = table->offset;
	table->symbols[top].initialValue = initialValue;
	table->count++;

	if(qual != FUNC_QUAL && qual != CONST_QUAL) 
		table->offset += width;
	
	return -1;
}

FlowTable * initFlowTable() {
	FlowTable* table = (FlowTable *)malloc(sizeof(FlowTable));
	table->count = 0;
	return table;
}

void findFlow(FlowTable* table,typeQualifier qual, char** startLabel, char** endLabel) {
	for(int i = table->count-1; i >= 0; i--) {
		if(table->flows[i].qual == qual) {
			*startLabel = (table->flows[i].startLabel);
			*endLabel = (table->flows[i].endLabel);
			return;
		}	
	}

	*startLabel = 0;
	*endLabel = 0;
}

void topFlow(FlowTable* table, char** startLabel, char** endLabel) {
	int count = table->count;

	if(count == 0) {
		*startLabel = 0;
		*endLabel = 0;
		return;
	}

	count--;
	*startLabel = (table->flows[count].startLabel);
	*endLabel = (table->flows[count].endLabel);
}

void pushFlow(FlowTable * table, typeQualifier qual, char* startLabel, char* endLabel) {
	int count = table->count++;
	table->flows[count].qual = qual;
	table->flows[count].startLabel = (char *)malloc(sizeof(char) * LABEL_SIZE);
	table->flows[count].endLabel   = (char *)malloc(sizeof(char) * LABEL_SIZE);
    
	strcpy(table->flows[count].startLabel, startLabel);
	strcpy(table->flows[count].endLabel, endLabel);
}

void popFlow(FlowTable * table) {	
	int count = table->count--;
	if( count > 0 ) {
		free(table->flows[count].startLabel);
		free(table->flows[count].endLabel);
	}
}
