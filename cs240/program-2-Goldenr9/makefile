CFLAGS= -Wall -Wextra -DDEBUG -g -pedantic -std=c++14

all: program2

program2.o: program2.cpp Table.h Heap.h Player.h Deck.h Card.h 
	g++ $(CFLAGS) program2.cpp -c -o program2.o

Heap.o: Heap.cpp Heap.h Player.h Deck.h Card.h
	g++ $(CFLAGS) Heap.cpp -c  -o Heap.o

Table.o: Table.cpp Table.h Player.h Deck.h Card.h Heap.h
	g++ $(CFLAGS) Table.cpp -c -o Table.o

program2: program2.o Table.o Heap.o Player.o Card.o Deck.o
	g++ $(CFLAGS) program2.o Table.o Heap.o Player.o Card.o Deck.o -o program2 
	
Player.o:  Player.cpp  Player.h Card.h Deck.h  
	g++ $(CFLAGS) -c Player.cpp -o Player.o
	
Card.o:  Card.h Card.cpp 
	g++ $(CFLAGS) -c Card.cpp -o Card.o

Deck.o: Card.h Deck.h Deck.cpp 
	g++ $(CFLAGS) -c Deck.cpp -o Deck.o	
	
clean:
	rm -f *.o program2
	rm -f *.o Heap
	rm -f *.o Table
	rm -f *.o Player
	rm -f *.o Deck
	rm -f *.o Card
	
run: all
	./program2

checkmem: all
	valgrind ./program2