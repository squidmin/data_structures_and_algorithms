stack_driver: stack_driver.o
	g++ stack_driver.o -o stack_driver
stack_driver.o: stack.h stack.template stack_driver.cpp
	g++ -Wall -ansi -pedantic -c stack_driver.cpp

clean:
	@rm -rf stack_driver.o

cleanall:
	@rm -rf stack_driver.o stack_driver
