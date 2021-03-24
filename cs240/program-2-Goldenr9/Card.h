#ifndef CARD_H
#define CARD_H
#include <cstdlib>
class Card{
	private:
		int value;
		int suit;
	public:
		Card(int,int);
		Card();
		int getValue();
		int getSuit();
		void alterCard(int,int);
		bool operator==(const Card &);
};

#endif
