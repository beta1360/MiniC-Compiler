CC = gcc
LEX = flex
YACC = bison

all: ast

ast: lex.yy.c parser.tab.c util.h parser.h
	$(CC) -o ast lex.yy.c parser.tab.c

lex.yy.c: scanner.l parser.tab.h
	$(LEX) scanner.l

parser.tab.c parser.tab.h: parser.y
	$(YACC) -d parser.y

clean:
	-rm -f *.o ast lex.yy.c *.tab.* *.ast
