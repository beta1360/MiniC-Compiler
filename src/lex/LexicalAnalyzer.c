#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define NO_KEYWORDS 7
#define ID_LENGTH 12

enum tsymbol {
	tnull = -1,
	tnot, tnotequ, tmod, tmodAssign, tident, tnumber,
	/* 0	1		2		3			4		5	*/
	tand, tlparen, trparen, tmul, tmulAssign, tplus,
	/* 6	7		8		 9		10		  11	*/
	tinc, taddAssign, tcomma, tminus, tdec, tsubAssign,
	/* 12	13			14		15		16		17	*/
	tdiv, tdivAssign, tsemicolon, tless, tlesse, tassign,
	/* 18	19			20			21		22		23	*/
	tequal, tgreat, tgreate, tlbracket, trbracket, teof,
	/* 24	25			26		27		  28		29	*/
	tconst, telse, tif, tint, treturn, tvoid,
	/* 30	31		32	 33		34		35	*/
	twhile, tlbrace, tor, trbrace
	/* 36	37		 38		 39	*/
};

char* symbol_token[] = {
	"!", "!=", "%", "%=", NULL, NULL,
	/*0	  1	   2	 3	   4	 5	*/
	"&&", "(", ")", "*", "*=", "+",
	/*6	   7	8	 9	  10	11	*/
	"++", "+=", ",", "-", "--", "-=",
	/*12   13	14	 15   16	17	*/
	"/", "/=", ";", "<", "<=", "=",
	/*18   19	20	 21	  22    23	*/
	"==", ">", ">=", "[", "]", "",
	/*24   25	26	 27	  28	29	*/
	"const", "else", "if", "int", "return", "void",
	/*30		31	  32	 33		34		 35	*/
	"while", "{", "||", ")"
	/*36	  37   38	 39*/
};

struct tokenType {
	int number;		// token number
	union {
		char id[ID_LENGTH];
		int num;
	} value;		// token value
};

char *keyword[NO_KEYWORDS] = {
	"const", "else", "if", "int", "return", "void", "while"
};

enum tsymbol tnum[NO_KEYWORDS] = {
	tconst, telse, tif, tint, treturn, tvoid, twhile
};

void lexicalError(int n){
	printf(" *** Lexical Error : ");
	switch (n) {
	case 1:
		printf("an identifier length must be less than 12\n");
		break;
	case 2:
		printf("next character must be &.\n");
		break;
	case 3:
		printf("next character must be |.\n");
		break;
	case 4:
		printf("invalid character!!!\n");
		break;
	}
}

int superLetter(char ch){
	if (isalpha(ch) || ch == '_') return 1;
	else return 0;
}

int superLetterOrDigit(char ch){
	if (isalnum(ch) || ch == "_") return 1;
	else return 0;
}

/*
- Reference : http://www.hackerschool.org/HS_Boards/view.php?id=QNA_programming&no=2983
- Modified by KeonHeeLee
*/
int getIntNum(char firstCharacter) {
	int num = 0;
	char ch;
	if (firstCharacter != '0') {
		ch = firstCharacter;
		do {
			num = 10 * num + (int)(ch - '0');
			ch = getchar();
		} while (isdigit(ch));
		ungetc(ch, stdin);
	}
	return num;
}

struct tokenType scanner(){
	struct tokenType token;
	int i, index;
	char ch, id[ID_LENGTH];

	token.number = tnull;
	token.value.num = 0;

	do {
		while (isspace(ch = getchar())); // state 1: skip blanks
		if (superLetter(ch)) { // identifier or keyword
			i = 0;
			do {
				if (i < ID_LENGTH) id[i++] = ch;
				ch = getchar();
			} while (superLetterOrDigit(ch));
			if (i >= ID_LENGTH) lexicalError(1);
			id[i] = '\0';
			ungetc(ch, stdin); // retract
			// find the identifier in the keyword table
			for (index = 0; index < NO_KEYWORDS; index++){
				if (!strcmp(id, keyword[index])) break;
			}
			if (index < NO_KEYWORDS) {	// found, keyword exit
				token.number = tnum[index];
			}
			else {					// not found, identifier exit
				token.number = tident;
				strcpy(token.value.id, id);
			}
		} // end of identifier or keyword
		else if (isdigit(ch)) { // integer constant
			token.number = tnumber;
			token.value.num = getIntNum(ch);
		}
		else
			switch (ch) { // special character
			case '/':	//state 10
				ch = getchar();
				if (ch == '*')	// text comment
				do {
					while (ch != '*') ch = getchar();
					ch = getchar();
				} while (ch != '/');
				else if (ch == '/')	{// line comment
					while (getchar() != '\n');
				}
				else if (ch == '=') token.number = tdivAssign;
				else {
					token.number = tdiv;
					ungetc(ch, stdin); // retract
				}
				break;
			case '!':	// state 17
				ch = getchar();
				if (ch == '=') token.number = tnotequ;
				else {
					token.number = tnot;
					ungetc(ch, stdin); // retract
				}
				break;
			case '%':	// state 20
				ch = getchar();
				if (ch == '=')
					token.number = tmodAssign;
				else {
					token.number = tmod;
					ungetc(ch, stdin);
				}
				break;
			case '&':	// state 23
				ch = getchar();
				if (ch == '&') token.number = tand;
				else {
					lexicalError(2);
					ungetc(ch, stdin);	// retract
				}
				break;
			case '*':	// state 25
				ch = getchar();
				if (ch == '=') token.number = tmulAssign;
				else {
					token.number = tmul;
					ungetc(ch, stdin); // retract
				}
				break;
			case '+':	// state 28
				ch = getchar();
				if (ch == '+') token.number = tinc;
				else if (ch == '=') token.number = taddAssign;
				else {
					token.number = tplus;
					ungetc(ch, stdin); // retract
				}
				break;
			case '-':	// state 32
				ch = getchar();
				if (ch == '-') token.number = tdec;
				else if (ch == '=') token.number = tsubAssign;
				else {
					token.number = tminus;
					ungetc(ch, stdin); // retract
				}
				break;
			case '<':	// state 36
				ch = getchar();
				if (ch == '=') token.number = tlesse;
				else {
					token.number = tless;
					ungetc(ch, stdin); // retract
				}
				break;
			case '=':	// state 39
				ch = getchar();
				if (ch == '=') token.number = tequal;
				else {
					token.number = tassign;
					ungetc(ch, stdin); // retract
				}
				break;
			case '>':	// state 42
				ch = getchar();
				if (ch == '=') token.number = tgreate;
				else {
					token.number = tgreat;
					ungetc(ch, stdin); // retract
				}
				break;
			case '|':	// state 45
				ch = getchar();
				if (ch == '|') token.number = tor;
				else {
					lexicalError(3);
					ungetc(ch, stdin); // retract
				}
				break;
			case '(': token.number = tlparen;		break;
			case ')': token.number = trparen;		break;
			case ',': token.number = tcomma;		break;
			case ';': token.number = tsemicolon;	break;
			case '[': token.number = tlbracket;		break;
			case ']': token.number = trbracket;		break;
			case '{': token.number = tlbrace;		break;
			case '}': token.number = trbrace;		break;
			case EOF: token.number = teof;			break;
			default: {
						 printf("Current character : %c", ch);
						 lexicalError(4);
						 break;
			}
		} // switch end
	} while (token.number == tnull);
	return token;
} // end of scanner

int main(int argc, char *argv[]){
	if (argc != 2) {
		printf("Error: Must have two parameters.\n");
		printf("Usage: LexicalAnalyzer <file_name>\n");
		return -1;
	}

	if (freopen(argv[1], "rb", stdin) == NULL){
		printf("Error: Invalid file path.\n");
		return -1;
	}

	struct tokenType token = scanner();

	while (token.number != teof) {
		if (token.number == tident) // if it is identifier
			printf("%-11s %-11d %s\n", token.value.id, token.number, token.value.id);
		else if (token.number == tnumber)  // If it is number
			printf("%-11d %-11d %d\n", token.value.num, token.number, token.value.num);
		else // another token
			printf("%-11s %-11d %d\n", symbol_token[token.number], token.number, token.value.num);

		token = scanner();
	}

	return 0;
}
