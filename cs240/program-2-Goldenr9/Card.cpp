#include <iostream>

#include "Card.h"

Card::Card(int suit, int value){
	if(suit<1 || suit>4){
		this->suit=1;
	}else{
		this->suit=suit;
	}
	if(value<2 || value>14){
		this->value=2;
	}else{
		this->value=value;
	}
}
Card::Card(){
	this->suit=1;
	this->value=2;
}
void Card::alterCard(int suit, int value){
		if(suit<1 || suit>4){
		this->suit=1;
	}else{
		this->suit=suit;
	}
	if(value<2 || value>14){
		this->value=2;
	}else{
		this->value=value;
	}
	
}
int Card::getValue(){
	return this->value;
}
int Card::getSuit(){
	return this->suit;
}
bool Card::operator==(const Card &other){
	if(this->value==other.value){
		return true;
	}
	return false;
}
