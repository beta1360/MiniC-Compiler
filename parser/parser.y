%{   
	#include "parser.h"

%}
%union {
    struct nodeType *node;
    int value;
    char* string;
}

%token tconst telse tif tint treturn tvoid twhile
	tand tor taddAssign tsubAssign tmulAssign 
    tdivAssign tmodAssign tfor
    tswitch tcase tdefault tbreak tcontinue

%nonassoc TIFX
%left tgreate tlesse tequal tnotequ '>' '<'
%left '+' '-'
%left '*' '/'
%left tinc tdec
%nonassoc uminus

%token <string> tident tnumber
%type <node> translation_unit external_dcl function_def function_header dcl_spec dcl_specifiers
	dcl_specifier type_qualifier type_specifier function_name formal_param opt_formal_param
	formal_param_list param_dcl compound_st opt_dcl_list declaration_list declaration init_dcl_list
	init_declarator declarator opt_number opt_stat_list statement_list statement expression_st 
	opt_expression if_st while_st return_st for_st for_dcl for_dcl_list for_exp for_inc for_inc_list
	continue_st break_st switch_st switch_list  switch_compound case_list switch_case loop_st condition_st flow_st expression
	assignment_exp logical_or_exp logical_and_exp equality_exp relational_exp additive_exp
	multiplicative_exp unary_exp postfix_exp opt_actual_param actual_param_list actual_param primary_exp
%%
mini_c           : translation_unit                         {root = buildTree(PROGRAM, $1);};
translation_unit : external_dcl                             { $$ = $1;}
                 | translation_unit external_dcl            {appendNext($1, $2); $$ = $1;};         
external_dcl     : function_def                             {$$ = $1;}
                 | declaration                              {$$ = $1;};          
function_def     : function_header compound_st              {appendNext($1, $2); $$ = buildTree(FUNC_DEF, $1);};
function_header  : dcl_spec function_name formal_param      {appendNext($1, $2); appendNext($2, $3); $$ = buildTree(FUNC_HEAD, $1);};
dcl_spec         : dcl_specifiers                           {$$ = buildTree(DCL_SPEC, $1);};
dcl_specifiers   : dcl_specifier                            {$$ = $1;}
                 | dcl_specifiers dcl_specifier             {appendNext($1, $2); $$ = $1;} ;          
dcl_specifier    : type_qualifier                           {$$ = $1;}
                 | type_specifier                           {$$ = $1;};                           
type_qualifier   : tconst                                   {$$ = buildTree(CONST_TYPE, NULL);};
type_specifier   : tint                                     {$$ = buildTree(INT_TYPE, NULL);}
                 | tvoid                                    {$$ = buildTree(VOID_TYPE, NULL);};
function_name    : tident                                   {$$ = buildNode(IDENT, $1); };
formal_param     : '(' opt_formal_param ')'                 {$$ = buildTree(FORMAL_PARA, $2);};
opt_formal_param : formal_param_list                        {$$ = $1;}
                 |                  						{$$ = NULL;};
formal_param_list: param_dcl                                {$$ = $1;}
                 | formal_param_list ',' param_dcl          {appendNext($1, $3);  $$ = $1;};
param_dcl        : dcl_spec declarator                      {appendNext($1, $2); $$ = buildTree(PARAM_DCL, $1);} ;
compound_st      : '{' opt_dcl_list opt_stat_list '}'       {appendNext($2, $3); $$ = buildTree(COMPOUND_ST, $2);};
opt_dcl_list     : declaration_list                         {$$ = buildTree(DCL_LIST, $1);}
                 |                                          {$$ = buildTree(DCL_LIST, NULL);};
declaration_list : declaration                              {$$ = $1;}
                 | declaration_list declaration             {appendNext($1, $2); $$ = $1;};
declaration      : dcl_spec init_dcl_list ';'               {appendNext($1, $2); $$ = buildTree(DCL, $1);}; 
init_dcl_list    : init_declarator                          {$$ = $1;}
                 | init_dcl_list ',' init_declarator        {appendNext($1, $3); $$ = $1;};
init_declarator  : declarator                               {$$ = $1;}
                 | declarator '=' tnumber                   {appendNext($1->son, buildNode(IDENT, $3)); $$ = $1;};
declarator       : tident                                   {Node* ptr = buildTree(SIMPLE_VAR, buildNode(IDENT, $1)); $$ = buildTree(DCL_ITEM, ptr);};
                 | tident '[' opt_number ']'                {Node* ptr = buildNode(IDENT, $1); appendNext(ptr, $3); $$ = buildTree(DCL_ITEM, buildTree(ARRAY_VAR, ptr));};
opt_number       : tnumber                                  {$$ = buildNode(NUMBER, $1);};   
                 |                                          {$$ = NULL;};
opt_stat_list    : statement_list                           {$$ = buildTree(STAT_LIST, $1);}
                 |                                          {$$ = NULL; };
statement_list   : statement                                {$$ = $1;}
                 | statement_list statement                 {appendNext($1, $2); $$ = $1;};
statement        : compound_st                              {$$ = $1;}
	             | expression_st                            {$$ = $1;}
	             | condition_st                             {$$ = $1;}
	             | loop_st                                  {$$ = $1;}
	             | flow_st                                  {$$ = $1;};
expression_st    : opt_expression ';'                       {$$ = buildTree(EXP_ST, $1);} ;
opt_expression   : expression                               {$$ = $1;}
                 |                                          {$$ = NULL;};
loop_st          : for_st                                   {$$ = $1;}
                 | while_st                                 {$$ = $1;};
condition_st     : if_st                                    {$$ = $1;}
	             | switch_st                                {$$ = $1;};
flow_st          : return_st                                {$$ = $1;}
	             | continue_st                              {$$ = $1;}
	             | break_st                                 {$$ = $1;};
if_st            : tif '(' expression ')' statement %prec TIFX {appendNext($3, $5); $$ = buildTree(IF_ST, $3);}
                 | tif '(' expression ')' statement telse statement  {appendNext($3, $5); appendNext($5, $7); $$ = buildTree(IF_ELSE_ST, $3);};
while_st         : twhile '(' expression ')' statement      {appendNext($3, $5); $$ = buildTree(WHILE_ST, $3);};
return_st        : treturn opt_expression ';'               {$$ = buildTree(RETURN_ST, $2);};
for_st           : tfor '(' for_dcl ';' for_exp ';' for_inc')' statement    {appendNext($3, $5);appendNext($5, $7);appendNext($7, $9);$$ = buildTree(FOR_ST,$3);};
for_dcl          : for_dcl_list                             {$$ = buildTree(FOR_DCL, $1);}
	             |                                          {$$ = buildTree(FOR_DCL,NULL); };
for_dcl_list     : for_dcl_list ',' assignment_exp          {appendNext($1, $3);$$ = $1;}
	             | assignment_exp                           {$$ = $1;};
for_exp          : logical_or_exp                           {$$ = buildTree(FOR_EXP, $1);}
                 | logical_and_exp                          {$$ = buildTree(FOR_EXP, $1);}
	             |                                          {$$ = buildTree(FOR_EXP, NULL); };
for_inc          : for_inc_list                             {$$ = buildTree(FOR_INC, $1);}
	             |                                          { $$ = buildTree(FOR_INC,NULL); };
for_inc_list     : assignment_exp                           { $$ = $1; }
	             | for_inc_list ',' assignment_exp          {appendNext($1, $3);$$ = $1;}
continue_st      : tcontinue ';'                           {$$ = buildTree(CONTINUE_ST,NULL);};
break_st         : tbreak ';'                               {$$ = buildTree(BREAK_ST, NULL);};
switch_st        : tswitch '(' declarator ')' '{' switch_list '}'       {appendNext($3, $6);$$ = buildTree(SWITCH_ST, $3);};
switch_list      : switch_list switch_compound              {appendNext($1, $2);} 
	             | switch_compound                          {$$ = $1;};
switch_compound  : case_list statement_list                 {Node *p = buildTree(CASE_EXP,$2); Node *q = buildTree(CASE_LST,$1); appendNext(q, p); $$ = q;};
case_list        : case_list switch_case                    {appendNext($1, $2);}
                 | switch_case                              {$$ = $1;};
switch_case      : tcase tnumber ':'                        {Node * son = buildNode(NUMBER, $2); $$ = buildTree(CASE_ST, son);}
	             | tdefault ':'                             {$$ = buildTree(DEFAULT_ST, NULL);};
expression       : assignment_exp                           {$$ = $1;}; 
assignment_exp   : logical_or_exp                           {$$ = $1;}
                 | unary_exp '=' assignment_exp             {appendNext($1, $3); $$ = buildTree(ASSIGN_OP, $1);}  
                 | unary_exp taddAssign assignment_exp      {appendNext($1, $3); $$ = buildTree(ADD_ASSIGN, $1);}
                 | unary_exp tsubAssign assignment_exp      {appendNext($1, $3); $$ = buildTree(SUB_ASSIGN, $1);}
                 | unary_exp tmulAssign assignment_exp      {appendNext($1, $3); $$ = buildTree(MUL_ASSIGN, $1);}
                 | unary_exp tdivAssign assignment_exp      {appendNext($1, $3); $$ = buildTree(DIV_ASSIGN, $1);}
                 | unary_exp tmodAssign assignment_exp      {appendNext($1, $3); $$ = buildTree(MOD_ASSIGN, $1);} ;
logical_or_exp   : logical_and_exp                          {$$ = $1;}
                 | logical_or_exp tor logical_and_exp       {appendNext($1, $3); $$ = buildTree(LOGICAL_OR, $1);};
logical_and_exp  : equality_exp                             {$$ = $1;}
                 | logical_and_exp tand equality_exp        {appendNext($1, $3); $$ = buildTree(LOGICAL_AND, $1);};
equality_exp     : relational_exp                           {$$ = $1;}
                 | equality_exp tequal relational_exp       {appendNext($1, $3); $$ = buildTree(EQ, $1);}
                 | equality_exp tnotequ relational_exp      {appendNext($1, $3); $$ = buildTree(NE, $1);};
relational_exp   : additive_exp                             {$$ = $1;}
                 | relational_exp '>' additive_exp          {appendNext($1, $3); $$ = buildTree(GT, $1);} 
                 | relational_exp '<' additive_exp          {appendNext($1, $3); $$ = buildTree(LT, $1);}
                 | relational_exp tgreate additive_exp      {appendNext($1, $3); $$ = buildTree(GE, $1);}
                 | relational_exp tlesse additive_exp       {appendNext($1, $3); $$ = buildTree(LE, $1);};
additive_exp     : multiplicative_exp                       {$$ = $1;}
                 | additive_exp '+' multiplicative_exp      {appendNext($1, $3); $$ = buildTree(ADD, $1);}
                 | additive_exp '-' multiplicative_exp      {appendNext($1, $3); $$ = buildTree(SUB, $1);};
multiplicative_exp : unary_exp                              {$$ = $1;}
                   | multiplicative_exp '*' unary_exp       {appendNext($1, $3); $$ = buildTree(MUL, $1);}
                   | multiplicative_exp '/' unary_exp       {appendNext($1, $3); $$ = buildTree(DIV, $1);}
                   | multiplicative_exp '%' unary_exp       {appendNext($1, $3); $$ = buildTree(MOD, $1);};
unary_exp          : postfix_exp                            {$$ = $1;}
                   | '-' unary_exp                          {$$ = buildTree(UNARY_MINUS, $2);}
                   | '!' unary_exp                          {$$ = buildTree(LOGICAL_NOT, $2);}
                   | tinc unary_exp                         {$$ = buildTree(PRE_INC, $2);}
                   | tdec unary_exp                         {$$ = buildTree(PRE_DEC, $2);};
postfix_exp        : primary_exp                            {$$ = $1;}
                   | postfix_exp '[' expression ']'         {appendNext($1, $3); $$ = buildTree(INDEX, $1);}
                   | postfix_exp '(' opt_actual_param ')'   {appendNext($1, $3); $$ = buildTree(CALL, $1);}
                   | postfix_exp tinc                       {$$ = buildTree(POST_INC, $1);}
                   | postfix_exp tdec                       {$$ = buildTree(POST_DEC, $1);};
opt_actual_param   : actual_param                           {$$ = $1;}
                   |                                        {$$ = NULL; };
actual_param       : actual_param_list                      {$$ = buildTree(ACTUAL_PARAM, $1);};
actual_param_list  : assignment_exp                         {$$ = $1;}
                   | actual_param_list ',' assignment_exp   {appendNext($1, $3); $$ = $1;};
primary_exp        : tident                                 {$$ = buildNode(IDENT, $1);}
                   | tnumber                                {$$ = buildNode(NUMBER, $1);}
                   | '(' expression ')'                     {$$ = $2;}; 
%%

int main(int argc, char *argv[]) {
	Node * root;
	FILE *inFile;
	FILE *astFile;
	
	if((inFile = fopen(argv[1], "r")) == NULL){
        printf("File path error: Invalid file path(%s).\n",argv[1]);
        return -1;
    }
	if((astFile = fopen(strcat(strtok(argv[1], "."), ".ast"), "w"))==NULL){
        printf("Making ast file error: Don\'t make ast file.\n");
        return -1;
    }
	
	root = parse(inFile);
	printTree(root, 0, astFile);
	    
	fclose(inFile);
	fclose(astFile);
	
	return 0;
}
