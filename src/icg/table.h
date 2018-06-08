#define LABEL_SIZE		8
#define SYM_TABLE_SIZE  512

typedef enum {
	NONE_SPEC, VOID_SPEC, INT_SPEC
} typeSpecifier;

typedef enum{
	NONE_QUAL, CONST_QUAL, VAR_QUAL, FUNC_QUAL, LOOP_QUAL, SWITCH_QUAL
} typeQualifier;

typedef struct SymbolInfo {
	char *id;
	typeQualifier qual;
	typeSpecifier spec;
	int width;
	int offset;
	int initialValue;	
} SymbolInfo;

typedef struct SymbolTable {
	int count;
	int offset;
	int base;
	SymbolInfo symbols[SYM_TABLE_SIZE];
	struct SymbolTable *parent;
} SymbolTable;

typedef struct FlowInfo{
	char* startLabel; 
	char* endLabel;
	typeQualifier qual;
} FlowInfo;
typedef struct FlowTable {
	int count;
	FlowInfo flows[SYM_TABLE_SIZE];
} FlowTable;

SymbolTable* createSymbolTable(SymbolTable *parent, int base);
SymbolTable* initSymbolTable();

void lookupSymbol(char* findId, SymbolTable** foundTable, int* findIdx);
int insertSymbol(SymbolTable* table, typeQualifier qual, typeSpecifier spec, char* id, int width, int initialValue);

FlowTable* initFlowTable();
void findFlow(FlowTable* table,typeQualifier qual, char** startLabel, char** endLabel);
void topFlow(FlowTable* table, char** startLabel, char** endLabel);
void pushFlow(FlowTable* table,typeQualifier qual, char* startLabel, char* endLabel);
void popFlow(FlowTable* table);
