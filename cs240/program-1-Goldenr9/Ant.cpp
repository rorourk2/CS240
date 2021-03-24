#include "Ant.h"
#include <iostream>
#include <cstdlib>
#include <cstring>

Ant::Ant(){
	/*this->nextAnt=NULL;
	this->previousAnt=NULL;*/
	this->maxX=50;
	this->maxY=50;
	this->currentX=25;
	this->currentY=25;
	
}
Ant::Ant(const Ant& a){
	/*this->nextAnt=a.nextAnt;
	this->previousAnt=a.previousAnt;*/
	this->maxX=a.maxX;
	this->maxY=a.maxY;
	this->currentX=a.currentX;
	this->currentY=a.currentY;
}
/*Ant::~Ant(){
	if(this->previousAnt!=NULL){
		this->previousAnt->nextAnt=this->nextAnt;
	}
	if(this->nextAnt!=NULL){
		this->nextAnt->previousAnt=this->previousAnt;
	}
}*/
int Ant::getCurrentX(){
	return this->currentX;
}
int Ant::getCurrentY(){
	return this->currentY;
}
/*Ant *Ant::getPreviousAnt(){
	return this->previousAnt;
}
Ant *Ant::getNextAnt(){
	return this->nextAnt;
}*/
int Ant::getMaxX(){
	return this->maxX;
}
int Ant::getMaxY(){
	return this->maxY;
}
bool Ant::rivalDuel(){
	int i=rand() %2;
	if(i==0){
		return true;
	}
	return false;
}
void Ant::move(){
	int i=0;
	int x=0;
	while(x==0){
		i=rand() %4;
		if(i==0 && this->currentX>0){
			this->currentX -=1;
			x=1;
		}else if(i==1 && this->currentX<this->maxX){
			this->currentX +=1;
			x=1;
		}else if(i==2 && this->currentY>0){
			this->currentY -=1;
			x=1;
		}else if(i==3 && this->currentY<this->maxY ){
			this->currentY +=1;
			x=1;
		}
	}
}
