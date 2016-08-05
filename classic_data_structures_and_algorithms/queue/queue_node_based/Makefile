queue_driver: queue_driver.o
	g++ queue_driver.o -o queue_driver
queue_driver.o: node.template node.h queue.template queue.h
	g++ -Wall -ansi -pedantic -c queue_driver.cpp
queue.o: queue.template queue.h
	g++ -Wall -ansi -pedantic -c queue.template
node.o: node.template node.h
	g++ -Wall -ansi -pedantic -c node.template

clean:
	@rm -rf queue_driver.o

cleanall:
	@rm -rf queue_driver.o queue_driver
