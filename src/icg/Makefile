CC = gcc
LIBS = -ll -ly
LEX = flex
YACC = bison

all : minic

minic: lex.yy.c minic.tab.c parser.c icg.c table.c
	$(CC) -o $@ $^ $(LIBS) -w

minic.tab.c: minic.y
	$(YACC) -d $^

lex.yy.c: scanner.l
	$(LEX) -t $^ > $@

clean:
	-rm -f *.o minic lex.yy.c *.tab.* *.ast *.uco 
