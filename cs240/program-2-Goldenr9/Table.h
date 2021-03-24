#ifndef TABLE_H
#define TABLE_H

#include <iostream>
#include <string>
#include <vector>
#include "Heap.h"
#include "Deck.h"

class Table {
	private:
		int numSeats;
		int ante;
		int emptySeats;
		Heap players;
		Player winner;
	public:
		Table(int,int);
		bool emptySeat();
		std::vector<Player> playRound();
		void addPlayer(Player p);
		void printWinner();
		unsigned int getNumPlayers();

	

};

#endif