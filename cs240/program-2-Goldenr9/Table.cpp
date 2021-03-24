#include <iostream>
#include <string>
#include <vector>
#include "Table.h"

using namespace std;



Table::Table(int seats, int ante) {
	this->numSeats = seats;
	this->ante = ante;
	emptySeats = seats;
}
bool Table::emptySeat() {
	if(emptySeats == 0){ 
		return false; 
	}
	else{ 
		return true; 
	}
}
unsigned int Table::getNumPlayers(){
	return players.size();
}

vector<Player> Table::playRound() {
	//cout << "1" << endl;
	Deck deck;
	deck.shuffle();
	Card drawn(0,0);
	//cout << "2" << endl;
	vector<Player> temp;
	while(players.size()>0){
		temp.push_back(players.getPlayer());
	}
	//cout << "3" << endl;
	for (int i = 0; i < numSeats - emptySeats; i++) {
		temp[i].bet(ante);
		drawn = deck.draw();
		temp[i].hand.alterCard(drawn.getValue(), drawn.getSuit());
	}
	//cout << "4" << endl;
	Card winningCard(temp[0].hand.getValue(), temp[0].hand.getSuit());
	winner = temp[0];
	int winnerPos = 0;
	for (int i = 1; i < numSeats - emptySeats; i++) {
		if (winningCard.getValue() < temp[i].hand.getValue()) {
			winningCard.alterCard(temp[i].hand.getValue(), temp[i].hand.getSuit());
			winner = temp[i];
			winnerPos = i;
		}

		//if there is a tie
		if (winningCard.getValue()
				== temp[i].hand.getValue()) {
			if (winningCard.getSuit() < temp[i].hand.getSuit()) {
				winningCard.alterCard(temp[i].hand.getValue(), temp[i].hand.getSuit());
				winner = temp[i];
				winnerPos = i;
			}
		}
	}
	//cout << "5" << endl;
	winner.collectWinnings(ante * (numSeats - emptySeats));
	int the=0;
	vector<Player> losers;
	for (int i = 0; i < numSeats - emptySeats; i++) {
		if (i != winnerPos) {
			losers.push_back(temp[i]);
			the++;
		}
	}
	emptySeats=numSeats;
	//players.clear();
	//cout << "A" << endl;
	players.clear();
	//cout << "B" << endl;
	players.addPlayer(winner);
	//cout << "C" << endl;
	return losers;

}



void Table::addPlayer(Player p) {
	if(emptySeats!=0){
		players.addPlayer(p);
		emptySeats--;
	}
}


void Table::printWinner() {
	cout << winner.getName() << endl;
}
