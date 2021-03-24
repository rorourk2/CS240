#include "AntHill.h"
#include <iostream>
#include <cstdlib>

#define BUFFER_MAX 100

using namespace std;

AntHill::AntHill(){
	this->ants=NULL;
	this->current_ants=0;
	this->next_id=0;
}

AntHill::~AntHill(){
	int i=0;
	while(i<this->current_ants){
		delete this->ants[i];
		i++;
	}
	delete [] this->ants;

}

int AntHill::addAnt(){
	Ant **a=new Ant *[1+this->current_ants];
	int i=0;
	while(i<this->current_ants){
		a[i]=this->ants[i];
		i++;
	}
	//this->ants[this->current_ants]=Ant(this->next_id);
	
	Ant* t=new Ant(this->next_id);
	a[this->current_ants]=t;
	this->current_ants+=1;
	delete [] this->ants;
	this->ants=a;
	this->next_id+=1;
	return next_id-1;
}
bool AntHill::removeAnt(int id){
	int i=0;
	int x=0;
	while(i<this->current_ants){
		if(this->ants[i]->getID()==id){
			x=1;
			delete this->ants[i];
			break;
		}
		i++;
	}
	if(x==0){
		return false;
	}
	Ant **a=new Ant *[this->current_ants];
	x=0;
	int y=0;
	while(x<this->current_ants){
		if(x==i){
			y++;
		}
		a[x]=this->ants[y];
		x++;
		y++;
	}
	delete [] this->ants;
	this->ants=a;
	this->current_ants-=1;
	return true;
}
Ant* AntHill::getAnt(int id){
	int i=0;
	while(i<this->current_ants){
		if(this->ants[i]->getID()==id){
			return ants[i];
		}
	i++;
	}
	return NULL;		
}
void AntHill::move(){
	int i=0;
	while(i<this->current_ants){
		this->ants[i]->move();
		i++;
	}
}


void AntHill::printHillInfo(){
	int i=0;
	while(i<this->current_ants){
		std::cout << "Ant #" << i << " [" << this->ants[i]->getX() << "," << this->ants[i]->getY()<< "]" << std::endl;
		i++;
	}
}



