llcp: llcpImp.o llcpApp.o
	g++ llcpImp.o llcpApp.o -o llcp
llcpImp.o: llcpImp.cpp llcpInt.h
	g++ -Wall -ansi -pedantic -c llcpImp.cpp
llcpApp.o: llcpApp.cpp llcpInt.h
	g++ -Wall -ansi -pedantic -c llcpApp.cpp

clean:
	@rm -rf llcpImp.o llcpApp.o
cleanall:
	@rm -rf llcpImp.o llcpApp.o llcp llcp.exe
