#include "Ant.h"
#include <iostream>
#include <cstdlib>

#define BUFFER_MAX 100

using namespace std;

Ant::Ant(int id){
	this->id = id;
	this->x = this->y = 0;
	this->xp=1;
}

void Ant::move(){
	int i=rand() %4;
	if(i==0){
		this->x -=1;
	}else if(i==1){
		this->x +=1;
	}else if(i==2){
		this->y -=1;
	}else{
		this->y +=1;
	}
}
Ant* Ant::fight(Ant* a){
	int i=rand() %100;
	int x=rand() %100;
	i=100-(i/(this->xp+1));
	i+=rand() %100;
	x=100-(x/(a->xp+1));
	x+=rand() %100;
	if(i>=x){
		this->xp=this->xp+a->xp;
		a->xp=0;
		return a;
	}
	else{
		a->xp=a->xp+this->xp;
		this->xp=0;
		return this;
	}
}

