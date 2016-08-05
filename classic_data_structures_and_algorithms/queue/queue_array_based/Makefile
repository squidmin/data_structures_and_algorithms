queue_driver: queue_driver.o
	g++ queue_driver.o -o queue_driver
queue_driver.o: queue.h queue.template queue_driver.cpp
	g++ -Wall -ansi -pedantic -c queue_driver.cpp

clean:
	@rm -rf queue_driver.o

cleanall:
	@rm -rf queue_driver.o queue_driver queue_driver.exe
