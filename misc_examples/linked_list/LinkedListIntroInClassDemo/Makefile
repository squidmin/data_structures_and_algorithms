p : LLutil.o LLplay.o
	g++ LLutil.o LLplay.o -o p
LLutil.o : LLutil.cpp LLutil.h
	g++ -Wall -ansi -pedantic -c LLutil.cpp
LLplay.o : LLplay.cpp LLutil.h
	g++ -Wall -ansi -pedantic -c LLplay.cpp
cleanall:
	@rm *.o p

