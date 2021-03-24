#ifndef Deck_H
#define Deck_H
#include <deque>
#include "Card.h"
class Deck{
	private:
		std::deque<Card *> cards;
	public:
		Deck();
		~Deck();
		Card draw();
		bool empty();
		std::deque<Card *>& getInternal();
		void shuffle();
};

#endif
