stack_driver: stack_driver.o
	g++ stack_driver.o -o stack_driver
stack_driver.o: node.template node.h stack.template stack.h
	g++ -Wall -ansi -pedantic -c stack_driver.cpp
stack.o: stack.template stack.h
	g++ -Wall -ansi -pedantic -c stack.template
node.o: node.template node.h
	g++ -Wall -ansi -pedantic -c node.template

clean:
	@rm -rf stack_driver.o

cleanall:
	@rm -rf stack_driver.o stack_driver
