#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include "Card.h"
class Player{
	private:
		std::string name;
		int budget;
	public:
		Player();
		Card hand;
		Player(std::string name, int budget);
		std::string getName();
		int getBudget();
		bool bet(int amount);
		void collectWinnings(int amount);
};

#endif
