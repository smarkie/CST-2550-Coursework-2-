output: main.o node.o list.o
	g++ main.o node.o list.o -output

program : main.cpp 
main.o: main.cpp
	g++ -c main.cpp

node.o:	node.cpp node.h
	g++ -c node.cpp

list.o: list.cpp list.h
	g++ -c list.cpp

clean:
	rm *.o output
	