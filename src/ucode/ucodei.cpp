/* modified by juyoon, from here... */
/* Compiler lecture's report code.
 * The code is suggested by professor but will make changes later.
*/
#include <stdio.h>

//#include <iostream.h>
//#include <fstream.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define _CRT_SECURE_NO_WARNINGS 

#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <locale>

using namespace std;

/* ... to here, to relect new standard of c++ */

const int MAXINSTR = 2000;
const int MAXLABELS = 500;
const int STACKSIZE = 2000;
const int LABELSIZE = 10;
const int NO_OPCODES = 41;             // 36 + 5

ifstream inputFile;
ofstream outputFile;

enum opcode {
	notop, neg, incop, decop, dupl, swp, add, sub, mult, divop,
	modop, andop, orop, gt, lt, ge, le, eq, ne,
	lod, ldc, lda, ldi, ldp, str, sti, ujp, tjp, fjp,
	call, ret, retv, chkh, chkl, nop, proc, endop, bgn, sym,
	dump, none
};

const char* opcodeName[NO_OPCODES] = {
	"notop", "neg",  "inc", "dec", "dup", "swp", "add",
	"sub",   "mult", "div", "mod", "and", "or",  "gt",
	"lt",    "ge",   "le",  "eq",  "ne",  "lod", "ldc",
	"lda",   "ldi",  "ldp", "str", "sti", "ujp", "tjp",
	"fjp",   "call", "ret", "retv","chkh","chkl","nop",
	"proc",  "end",  "bgn", "sym", "dump","none"
};

int executable[NO_OPCODES] = {
	/* notop */ 1, /* neg */  1, /* inc */  1, /* dec */  1, /* dup */  1,
	/* swp */   1, /* add */  1, /* sub */  1, /* mult */ 1, /* div */  1,
	/* mod */   1, /* and */  1, /* or */   1, /* gt */   1, /* lt */   1,
	/* ge */    1, /* le */   1, /* eq */   1, /* ne */   1, /* lod */  1,
	/* ldc */   1, /* lda */  1, /* ldi */  1, /* ldp */  1, /* str */  1,
	/* sti */   1, /* ujp */  1, /* tjp */  1, /* fjp */  1, /* call */ 1,
	/* ret */   1, /* retv */ 1, /* chkh */ 1, /* chkl */ 1, /* nop */  0,
	/* proc */  1, /* end */  0, /* bgn */  0, /* sym */  0, /* dump */ 1,
	/* none */  0
};

int opcodeCycle[NO_OPCODES] = {
	/* notop */ 5, /* neg */   5, /* inc */  1, /* dec */   1, /* dup */    5,
	/* swp */  10, /* add */  10, /* sub */ 10, /* mult */ 50, /* div */  100,
	/* mod */ 100, /* and */  10, /* or */  10, /* gt */   20, /* lt */    20,
	/* ge */   20, /* le */   20, /* eq */  20, /* ne */   20, /* lod */    5,
	/* ldc */   5, /* lda */   5, /* ldi */ 10, /* ldp */  10, /* str */    5,
	/* sti */  10, /* ujp */  10, /* tjp */ 10, /* fjp */  10, /* call */  30,
	/* ret */  30, /* retv */ 30, /* chkh */ 5, /* chkl */  5, /* nop */    0,
	/* proc */ 30, /* end */   0, /* bgn */  0, /* sym */   0, /* dump */ 100,
	/* none */  0
};

long int dynamicCnt[NO_OPCODES] /* = {
								0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
								0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
								0,0,0,
								1
								} */;

int staticCnt[NO_OPCODES] /* = {
						  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
						  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
						  0,0,0,
						  1
						  } */;

enum { FALSE, TRUE };
enum procIndex {
	READPROC = -1, WRITEPROC = -2, LFPROC = -3,
	UNDEFINED = -1000
};

typedef struct {
	int opcode;
	int value1;
	int value2;
	int value3;
} Instruction;

Instruction instrBuf[MAXINSTR];

void errmsg(char* s, const char* s2 = "")
{
	cerr << "error !!!  " << s << ":  " << s2 << "\n";
	exit(1);
}

class UcodeiStack {
	int size;			// stack size
	int sp;				// stack pointer
	int* stackArray;	// stack Array
public:
	void push(int);		// stack push
	int pop();			// stack pop
	int top() { return sp; }	// return stack pointer 
	void spSet(int n) { sp = n; }	// stack pointer setting
	void dump();
	int& operator[](int);
	UcodeiStack(int);
	~UcodeiStack() { delete[] stackArray; }
};

class Label {
	struct fixUpList {
		int instrAddress;
		struct fixUpList* next;
	};
	struct labelEntry {
		char labelName[LABELSIZE];
		int address;
		struct fixUpList* instrList;
	};
	struct labelEntry labelTable[MAXLABELS];
	int labelCnt;
	void addFix(struct fixUpList*, int);
public:
	void insertLabel(char[], int);
	void findLabel(char[], int);
	void checkUndefinedLabel();
	Label();
	virtual ~Label() { }
};

class Assemble {
	int instrCnt;
	char lineBuffer[80];
	int bufIndex;
	Label labelProcess;
	char label[LABELSIZE];
	void getLabel();
	int getOpcode();
	int getOperand();
	void instrWrite();
public:
	void assemble();
	int startAddr;
	Assemble() {
		instrCnt = 0;
	}

};

class Interpret {
	UcodeiStack stack;
	int arBase;
	long int tcycle;
	long int exeCount;
	void predefinedProc(int);
	int findAddr(int);
	void statistic();
public:
	void execute(int);
	Interpret();
	virtual ~Interpret() { }
};

UcodeiStack::UcodeiStack(int size)
{
	/*
	생성자의 기능을 한다.
	size를 생성자로 받으면 그만큼 스택을 생성.
	*/
	stackArray = new int[size];
	sp = -1;
	push(-1); push(-1); push(-1); push(0);
	push(0);   push(0); push(-1); push(1);
}

void UcodeiStack::push(int value)
{
	// 푸쉬
	if (sp == STACKSIZE) errmsg("push()", "Stack Overflow...");
	stackArray[++sp] = value;
}

int UcodeiStack::pop()
{
	// 팝
	if (sp == 0) errmsg("pop()", "Stack Underflow...");
	return stackArray[sp--];
}

void UcodeiStack::dump()
{
	int i;

	cout << "stack dump (address : value)\n";
	for (i = sp - 10; i <= sp; ++i)
		cout << ' ' << i << " : " << stackArray[i] << "\n";
	cout << '\n';
}

int& UcodeiStack::operator[](int index)
{
	return stackArray[index];
}

Label::Label()
{
	int index;

	labelCnt = 2;
	
	strcpy(labelTable[0].labelName, "read");
	labelTable[0].address = READPROC;
	labelTable[0].instrList = NULL;

	strcpy(labelTable[1].labelName, "write"); /* modified by juyoon */
	labelTable[1].address = WRITEPROC;
	labelTable[1].instrList = NULL;

	strcpy(labelTable[2].labelName, "lf");
	labelTable[2].address = LFPROC;
	labelTable[2].instrList = NULL;

	for (index = 3; index < MAXLABELS; index++)
		labelTable[index].address = UNDEFINED;
}

void Label::insertLabel(char label[], int value)
{
	struct fixUpList* ptr;
	int index;

	for (index = 0; (index <= labelCnt)
		&& strcmp(labelTable[index].labelName, label); index++);
	labelTable[index].address = value;

	if (index > labelCnt) {
		strcpy(labelTable[index].labelName, label);
		labelCnt = index;
		labelTable[index].instrList = NULL;
	}
	else {
		ptr = labelTable[index].instrList;
		labelTable[index].instrList = NULL;
		while (ptr) {  // backpatching
			instrBuf[ptr->instrAddress].value1 = value;
			ptr = ptr->next;
		}
	}
}

void Label::findLabel(char label[], int instr)
{
	// 라벨을 탐색하는 함수다.
	struct fixUpList* ptr;
	int index;

	// 라벨을 탐색한다.
	for (index = 0; (index <= labelCnt) &&
		strcmp(label, labelTable[index].labelName); index++);
	if (index > labelCnt) { 
		// not found
		// 새로 fixUpList를 생성한다.
		strcpy(labelTable[index].labelName, label);
		labelCnt = index;
		ptr = new fixUpList;
		if (ptr == NULL) errmsg("findLabel()", "Out of memory -- new");
		labelTable[index].instrList = ptr;
		ptr->instrAddress = instr;
		ptr->next = NULL;
	}
	else {                
		// found
		ptr = labelTable[index].instrList;
		if (ptr) addFix(ptr, instr); // Fix를 추가한다.
		else instrBuf[instr].value1 = labelTable[index].address;
	}
}

void Label::addFix(struct fixUpList* prev, int instr)
{
	struct fixUpList* succ;

	while (prev->next) prev = prev->next;
	succ = new fixUpList;
	if (succ == NULL) errmsg("addFix()", "Out of memory");
	succ->instrAddress = instr;
	succ->next = NULL;
	prev->next = succ;
	//   delete succ;
}

void Label::checkUndefinedLabel()
{
	// 혹시 undefined가 있는지 확인하는 용도로 쓰이는 함수
	int index;

	for (index = 0; index <= labelCnt; index++)
		if (labelTable[index].address == UNDEFINED)
			errmsg("undefined label", labelTable[index].labelName);
}

void Assemble::getLabel()
{
	// 라벨의 이름을 가져오는 함수다.
	int i;

	// 해당 버퍼가 공백인지 찾는다. 공백이면 bufIndex를 추가한다.
	while (isspace(lineBuffer[bufIndex])) bufIndex++;

	// 라벨 이름을 복사한다.
	for (i = 0; i <= LABELSIZE && !isspace(label[i] = lineBuffer[bufIndex]);
		bufIndex++, i++);
	label[i] = '\0';
}

int Assemble::getOpcode()
{
	// opcode를 얻어오는 함수다.
	char mnemonic[6];
	int index;

	// always start at 12-th column

	bufIndex = 11;
	index = 0;

	// 명령어 이름 저장
	while (index < 5 && !isspace(lineBuffer[bufIndex])) {
		mnemonic[index++] = lineBuffer[bufIndex++];
	}
	mnemonic[index] = '\0';

	// 명령어 인덱스를 돌면서 검사를 해본다.
	// 만약 명령어 인덱스에 해당 명령어가 있다면,
	// 올바른 명령어의 index가 return값으로 지정될 것이다.
	for (index = notop; index < none; index++)
		if (!strcmp(mnemonic, opcodeName[index])) break;

	if (index == none) errmsg("Illegal opcode", mnemonic);
	return index;
}

int Assemble::getOperand()
{
	// operand를 얻어온다.
	int result;

	while (isspace(lineBuffer[bufIndex])) bufIndex++;
	result = 0;
	while (isdigit(lineBuffer[bufIndex]) && lineBuffer[bufIndex] != '\n')
		result = 10 * result + (lineBuffer[bufIndex++] - '0');
	return result;
}

void Assemble::instrWrite()
{
	int i, j;
	char ch;

	inputFile.seekg(0, ios::beg);

	outputFile << "\n line       object           ucode  source program\n\n";
	for (i = 1; i <= instrCnt; i++)
	{
		outputFile.width(4);
		outputFile << i << "    (";
		outputFile.width(2);
		outputFile << instrBuf[i].opcode;
		j = instrBuf[i].opcode;
		if (j == chkl || j == chkh || j == ldc || j == bgn ||
			j == ujp || j == call || j == fjp || j == tjp) {
			outputFile.width(5);
			outputFile << instrBuf[i].value1 << "     ";
		}
		else if (j == lod || j == str || j == lda || j == sym || j == proc) {
			outputFile.width(5);
			outputFile << instrBuf[i].value1;
			outputFile.width(5);
			outputFile << instrBuf[i].value2;
		}
		else outputFile << "          ";
		outputFile << ")     ";
		while ((ch = inputFile.get()) != '\n')  // copy input to output
			outputFile.put(ch);
		outputFile.put('\n');
	}
	outputFile << "\n\n\n   ****    Result    ****\n\n\n";
}

void Assemble::assemble()
{
	int done = FALSE;
	int end = FALSE;
	int n;

	cout << " == Assembling ... ==" << '\n';
	while (!inputFile.eof() && !inputFile.fail() && !end) {	// 파일이 끝일 때까지
		instrCnt++; bufIndex = 0;
		inputFile.getline(lineBuffer, sizeof(lineBuffer));	// 파일 한 줄씩 읽는다.	
		if (!isspace(lineBuffer[0])) {						// 첫번째 라인버퍼가 있다면
			getLabel();										// 라벨을 얻어오고
			labelProcess.insertLabel(label, instrCnt);		// labelProcess에 label과 instrCnt를 넣어둔다.
		}
		instrBuf[instrCnt].opcode = n = getOpcode();
		staticCnt[n]++;
		switch (n) {
		case chkl:
		case chkh:
		case ldc:
			instrBuf[instrCnt].value1 = getOperand();
			break
				;
		case lod:
		case str:
		case lda:
		case sym:
			instrBuf[instrCnt].value1 = getOperand();
			instrBuf[instrCnt].value2 = getOperand();
			break;
		case proc:
			instrBuf[instrCnt].value1 = getOperand();
			instrBuf[instrCnt].value2 = getOperand();
			instrBuf[instrCnt].value3 = getOperand();
			break;
		case bgn:
			instrBuf[instrCnt].value1 = getOperand();
			startAddr = instrCnt;
			done = TRUE;
			break;
		case ujp:
		case call:
		case fjp:
		case tjp:
			getLabel();
			labelProcess.findLabel(label, instrCnt);
			break;
		case endop:
			if (done) end = TRUE;
		}
	}
	instrWrite();
}

Interpret::Interpret()
	: stack(STACKSIZE)
{
	arBase = 4;
	tcycle = 0;
	exeCount = 0;
}

int Interpret::findAddr(int n)
{
	int temp;

	if (!instrBuf[n].value1)
		errmsg("findAddr()", "Lexical level is zero ...");
	if (instrBuf[n].value2 < 1)
		errmsg("findAddr()", "Negative offset ...");
	for (temp = arBase; instrBuf[n].value1 != stack[temp + 3]; temp = stack[temp]) {
		if ((temp > STACKSIZE) || (temp < 0))
			cout << "Lexical level :  " << instrBuf[n].value1 << ' '
			<< "Offset        :  " << instrBuf[n].value2 << '\n';
	}

	return (temp + instrBuf[n].value2 + 3);
}

void Interpret::predefinedProc(int procIndex)
{
	static ifstream dataFile;
	static int readFirst = TRUE;

	//     char dataFileName[20];
	int data, temp;

	if (procIndex == READPROC)           // read
	{
		/*
		if (readFirst) {
		cout << "\nEnter Data File Name : ";
		cin >> dataFileName;
		dataFile.open(dataFileName, ios::in);
		if (dataFileName == NULL)
		errmsg("checkPredefined()", "Data file open error ...");
		readFirst = FALSE;
		}
		dataFile >> data;
		*/
		cin >> data;
		temp = stack.pop();
		stack[temp] = data;
		stack.spSet(stack.top() - 4);
	}
	else if (procIndex == WRITEPROC) {   // write
		temp = stack.pop();
		cout << ' ' << temp;
		outputFile << ' ' << temp;
		stack.spSet(stack.top() - 4);
	}
	else if (procIndex == LFPROC) {    // lf : line feed
		outputFile.put('\n');
		cout << "\n";
	}
}

void Interpret::statistic()
{
	int i, opcode;

	outputFile << "\n\n   **********************\n\n";
	outputFile << "\n\n\n                 " << "#### Statistics ####\n";
	outputFile << "\n\n    ****  Static Instruction Counts  ****\n\n\n";
	for (i = 0, opcode = notop; opcode <= none; opcode++) {
		if (staticCnt[opcode] != 0) {
			outputFile.width(5);
			outputFile.setf(ios::left, ios::adjustfield);
			outputFile << opcodeName[opcode] << "  =  ";
			outputFile.width(5);
			outputFile.setf(ios::left, ios::adjustfield);
			outputFile << staticCnt[opcode] << "   ";
			i++;
			if (i % 4 == 0) outputFile.put('\n');
		}
	}
	outputFile << "\n\n\n  ****  Dynamic instruction counts  ****\n\n\n";
	for (i = 0, opcode = notop; opcode <= none; opcode++) {
		if (dynamicCnt[opcode] != 0) {
			outputFile.width(5);
			outputFile.setf(ios::left, ios::adjustfield);
			outputFile << opcodeName[opcode] << "  =  ";
			outputFile.width(8);
			outputFile.setf(ios::left, ios::adjustfield);
			outputFile << dynamicCnt[opcode] << "  ";
			i++;
			if (i % 4 == 0) outputFile << "\n";
		}
	}
	outputFile << "\n\n Executable instruction count  =   " << exeCount;
	outputFile << "\n\n Total execution cycle         =   " << tcycle;
	outputFile << "\n";
}

void Interpret::execute(int startAddr)
{
	int parms;
	int temp, temp1;
	int pc;
	//	 int returnAddress;

	pc = startAddr;
	cout << " == Executing ...  ==\n";
	cout << " == Result         ==\n";
	while (pc >= 0)
	{
		dynamicCnt[instrBuf[pc].opcode]++;
		if (executable[instrBuf[pc].opcode]) exeCount++;
		tcycle += opcodeCycle[instrBuf[pc].opcode];
		switch (instrBuf[pc].opcode)
		{
		case notop:
			stack.push(!stack.pop());
			break;
		case neg:
			stack.push(-stack.pop());
			break;
		case add:
			stack.push(stack.pop() + stack.pop());
			break;
		case divop:
			temp = stack.pop();
			if (temp == 0) errmsg("execute()", "Divide by Zero ...");
			stack.push(stack.pop() / temp);
			break;
		case sub:
			temp = stack.pop();
			stack.push(stack.pop() - temp);
			break;
		case mult:
			stack.push(stack.pop()*stack.pop());
			break;
		case modop:
			temp = stack.pop();
			stack.push(stack.pop() % temp);
			break;
		case andop:
			stack.push(stack.pop() & stack.pop());
			break;
		case orop:
			stack.push(stack.pop() | stack.pop());
			break;
		case gt:
			temp = stack.pop();
			stack.push(stack.pop()>temp);
			break;
		case lt:
			temp = stack.pop();
			stack.push(stack.pop()<temp);
			break;
		case ge:
			temp = stack.pop();
			stack.push(stack.pop() >= temp);
			break;
		case le:
			temp = stack.pop();
			stack.push(stack.pop() <= temp);
			break;
		case eq:
			temp = stack.pop();
			stack.push(stack.pop() == temp);
			break;
		case ne:
			temp = stack.pop();
			stack.push(stack.pop() != temp);
			break;
		case swp:
			temp = stack.pop();
			temp1 = stack.pop();
			stack.push(temp);
			stack.push(temp1);
			break;
		case lod:
			stack.push(stack[findAddr(pc)]);
			break;
		case ldc:
			stack.push(instrBuf[pc].value1);
			break;
		case lda:
			stack.push(findAddr(pc));
			break;
		case str:
			stack[findAddr(pc)] = stack.pop();
			break;
		case ldi:
			if ((stack.top() <= 0) || (stack.top() > STACKSIZE))
				errmsg("execute()", "Illegal ldi instruction ...");
			temp = stack.pop();
			stack.push(temp);
			stack[stack.top()] = stack[temp];
			break;
		case sti:
			temp = stack.pop();
			stack[stack.pop()] = temp;
			break;
		case ujp:
			pc = instrBuf[pc].value1 - 1;
			break;
		case tjp:
			if (stack.pop()) pc = instrBuf[pc].value1 - 1;
			break;
		case fjp:
			if (!stack.pop()) pc = instrBuf[pc].value1 - 1;
			break;
		case chkh:
			temp = stack.pop();
			if (temp > instrBuf[pc].value1)
				errmsg("execute()", "High check failed...");
			stack.push(temp);
			break;
		case chkl:
			temp = stack.pop();
			if (temp < instrBuf[pc].value1)
				errmsg("execute()", "Low check failed...");
			stack.push(temp);
			break;
		case ldp:
			parms = stack.top() + 1;		// save sp
			stack.spSet(stack.top() + 4);   // set a frame
			break;
		case call:
			if ((temp = instrBuf[pc].value1) < 0) predefinedProc(temp);
			else {
				stack[parms + 2] = pc + 1;
				stack[parms + 1] = arBase;
				arBase = parms;
				pc = instrBuf[pc].value1 - 1;
			}
			break;
		case retv:
			temp = stack.pop();
		case ret:
			stack.spSet(arBase - 1);
			if (instrBuf[pc].opcode == retv)
				stack.push(temp);
			pc = stack[arBase + 2] - 1;
			arBase = stack[arBase + 1];
			break;
			/*
			case stp:
			returnAddress = stack[arBase+2] - 1;
			stack.spSet(arBase - 1);
			arBase = stack[arBase + 1];
			break;
			case ret:
			pc = returnAddress;
			break;
			*/
		case proc:
			// value 1: (size of paras + size of local vars)
			// value 2: block number(base)
			// value 3: static level => lexical level (static chain)
			stack.spSet(arBase + instrBuf[pc].value1 + 3);
			stack[arBase + 3] = instrBuf[pc].value2;
			for (temp = stack[arBase + 1]; stack[temp + 3] !=
				instrBuf[pc].value3 - 1; temp = stack[temp]);
			stack[arBase] = temp;
			break;
		case endop:
			pc = -2;
			break;
		case bgn:
			stack.spSet(stack.top() + instrBuf[pc].value1);
			break;
			/*
			case ones:
			temp = stack.pop();
			stack.push(~temp);
			break;
			*/
		case nop:
		case sym:
			break;
			/* augmented operation code */
		case incop:
			temp = stack.pop();
			stack.push(++temp);
			break;
		case decop:
			temp = stack.pop();
			stack.push(--temp);
			break;
		case dupl:
			temp = stack.pop();
			stack.push(temp);
			stack.push(temp);
			break;
		case dump:
			stack.dump();
			break;
		}
		pc++;
	}
	cout << '\n';
	statistic();
}

int main(int argc, char* argv[])
{

	Assemble sourceProgram;
	Interpret binaryProgram;

	if (argc != 2) errmsg("main()", "Wrong number of arguments");

	inputFile.open(argv[1], ios::in);
	if (!inputFile) errmsg("cannot open input file", argv[1]);

	outputFile.open(strcat(strtok(argv[1], "."), ".lst"), ios::out);
	if (!outputFile) errmsg("cannot open output file", argv[1]) ;

	sourceProgram.assemble();
	binaryProgram.execute(sourceProgram.startAddr);

	inputFile.close();
	outputFile.close();

	return 0;
}
