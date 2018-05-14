#ifndef _LexicalAnalyzer_H
#define _LexicalAnalyzer_H

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

struct tokenType {
	int number;			// token number
	char *tokenValue;	// token Value;
};

extern char *keyword[NO_KEYWORDS];
extern enum tsymol tnum[NO_KEYWORDS];

void lexicalError(int);
int superLetter(char);
int superLetterOrDigit(char);
int getIntNum(char);

struct tokenType scanner();

#endif