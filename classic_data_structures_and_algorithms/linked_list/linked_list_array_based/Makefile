test_node: test_node.o
	g++ test_node.o -o test_node
test_node.o: test_node.cpp node.cpp node.h
	g++ -Wall -ansi -pedantic -c test_node.cpp

clean:
	@rm -rf test_node.o
cleanall:
	@rm -rf test_node.o test_node

