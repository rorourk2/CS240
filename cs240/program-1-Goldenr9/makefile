P=AntHill
Q=Ant
R=LinkedList
S=program1
CFLAGS= -Wall -Wextra -DDEBUG -g -pedantic -std=c++14


all: $(S)

$(P).o: $(P).cpp $(P).h
	g++ $(CFLAGS) -c $(P).cpp -o $(P).o

$(Q).o: $(Q).cpp $(Q).h
	g++ $(CFLAGS) -c $(Q).cpp -o $(Q).o

$(R).o: $(R).cpp $(R).h
	g++ $(CFLAGS) -c $(R).cpp -o $(R).o

$(S).o: $(S).cpp
	g++ $(CFLAGS) -c $(S).cpp -o $(S).o

$(S): $(P).o $(Q).o $(S).o $(R).o 
	g++ $(P).o $(Q).o $(S).o $(R).o -o $(S) $(CFLAGS)

run: all
	./$(S)

checkmem: all
	valgrind ./$(S)

clean: 
	rm $(Q).o $(P).o $(R).o $(S).o anthill.log $(S)
