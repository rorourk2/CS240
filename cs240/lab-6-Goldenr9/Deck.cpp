#include <iostream>
#include <cstdlib>


#include "Deck.h"

Deck::Deck(){
	this->cards=std::deque<Card *>();
	for(int i=1;i<=4;i++){
		for(int x=2;x<=14;x++){
			this->cards.push_back(new Card(i,x));
		}
	}
}
Deck::~Deck(){
	int i=0;
	while(i<52){
		delete this->cards.back();
		this->cards.pop_back();
		i++;
	}
}
Card Deck::draw(){
	Card ret=Card(this->cards.front()->getSuit(),this->cards.front()->getValue());
	this->cards.pop_front();
	return ret;
}
bool Deck::empty(){
	if(this->cards.size()==0){
		return true;
	}
	return false;
}
std::deque<Card *>& Deck::getInternal(){
	return this->cards;
}
void Deck::shuffle(){
	int x=0;
	int i=0;
	Card *ret=NULL;
	while(x<1000){
		i=rand() %52;
		ret=this->cards.at(i);
		this->cards.erase(this->cards.begin()+i);
		this->cards.push_back(ret);
		x++;
	}
}
