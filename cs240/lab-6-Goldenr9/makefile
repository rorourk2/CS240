P=Card
Q=lab6
R=Deck
CFLAGS= -Wall -Wextra -DDEBUG -g -pedantic -std=c++14


all: $(Q)

$(P).o:  $(P).h $(P).cpp
	g++ $(CFLAGS) -c $(P).cpp -o $(P).o

$(R).o: $(P).h $(R).h $(R).cpp $(P).cpp 
	g++ $(CFLAGS) -c $(R).cpp -o $(R).o

$(Q).o: $(P).h $(R).h $(Q).cpp $(R).cpp $(P).cpp 
	g++ $(CFLAGS) -c $(Q).cpp -o $(Q).o

$(Q): $(Q).o $(P).o $(R).o
	g++ $(P).o $(R).o $(Q).o -o $(Q) $(CFLAGS)

run: all
	./$(Q)

checkmem: all
	valgrind ./$(Q)

clean: 
	rm $(Q).o  $(R).o $(P).o $(Q)
