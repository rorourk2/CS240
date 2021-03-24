P=program3
Q=Map
R=City
S=Filereader
CFLAGS= -g -Wall

all: $(P)

$(P): $(P).o $(Q).o $(R).o $(S).o
	g++ $(CFLAGS) $(P).o $(Q).o $(R).o $(S).o -o $(P)

$(P).o: $(P).cpp $(Q).h $(R).h $(S).h
	g++ $(CFLAGS) -c $(P).cpp -o $(P).o

$(Q).o: $(Q).cpp $(Q).h $(R).h $(S).h
	g++ $(CFLAGS) -c $(Q).cpp -o $(Q).o
	
$(R).o: $(R).cpp $(R).h $(S).h
	g++ $(CFLAGS) -c $(R).cpp -o $(R).o

$(S).o: $(S).cpp $(S).h
	g++ $(CFLAGS) -c $(S).cpp -o $(S).o

run: $(P)
	./$(P)

checkmem: $(P)
	valgrind ./$(P)

clear:
	clear
	clear
	
clean:
	rm -rf $(P)
	rm -rf $(P).o
	rm -rf $(Q).o
	rm -rf $(R).o
	rm -rf $(S).o
