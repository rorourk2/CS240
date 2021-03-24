P=LinkedList
Q=lab4
R=Queue
CFLAGS= -Wall -Wextra -DDEBUG -g -pedantic -std=c++14


all: $(Q)

$(Q).o: $(Q).cpp $(P).h $(R).h
	g++ $(CFLAGS) -c $(Q).cpp -o $(Q).o

$(Q): $(Q).o
	g++ $(Q).o -o $(Q) $(CFLAGS)

run: all
	./$(Q)

checkmem: all
	valgrind ./$(Q)

clean: 
	rm $(Q).o $(P).o $(R).o $(Q)
