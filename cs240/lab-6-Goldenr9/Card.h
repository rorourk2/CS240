#ifndef CARD_H
#define CARD_H
#include <cstdlib>
class Card{
	private:
		int value;
		int suit;
	public:
		Card(int,int);
		int getValue();
		int getSuit();
		bool operator==(const Card &);
};

#endif
