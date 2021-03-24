P=BSTree
Q=lab5

CFLAGS= -Wall -Wextra -DDEBUG -g -pedantic -std=c++14


all: $(Q)


$(P).o: $(P).cpp $(P).h
	g++ $(CFLAGS) -c $(P).cpp -o $(P).o

$(Q).o: $(Q).cpp $(P).h
	g++ $(CFLAGS) -c $(Q).cpp -o $(Q).o

$(Q): $(P).o $(Q).o 
	g++ $(P).o $(Q).o -o $(Q) $(CFLAGS)

run: all
	./$(Q)

checkmem: all
	valgrind ./$(Q)

clean: 
	rm $(Q).o $(P).o $(Q)
