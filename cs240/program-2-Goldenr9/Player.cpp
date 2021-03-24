#include <iostream>

#include "Player.h"

Player::Player(std::string name, int budget){
	this->name=name;
	this->budget=budget;
}
Player::Player(){
	this->name="";
	this->budget=0;
}
std::string Player::getName(){
	return name;
}
int Player::getBudget(){
	return budget;
}
bool Player::bet(int amount){
	if(amount>budget){
		return false;
	}
	budget-=amount;
	return true;
}
void Player::collectWinnings(int amount){
	budget+=amount;
}
