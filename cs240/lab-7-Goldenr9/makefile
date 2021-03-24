P=Hash
Q=lab7

CFLAGS= -Wall -Wextra -DDEBUG -g -pedantic -std=c++14


all: $(Q)

$(P).o:  $(P).h $(P).cpp
	g++ $(CFLAGS) -c $(P).cpp -o $(P).o


$(Q).o: $(P).h $(Q).cpp $(P).cpp 
	g++ $(CFLAGS) -c $(Q).cpp -o $(Q).o

$(Q): $(Q).o $(P).o
	g++ $(P).o $(Q).o -o $(Q) $(CFLAGS)

run: all
	./$(Q)

checkmem: all
	valgrind ./$(Q)

clean: 
	rm $(Q).o $(P).o $(Q)
