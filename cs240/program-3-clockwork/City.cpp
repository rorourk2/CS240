#include "City.h"
#include <iostream>

using namespace std;

//main constructor
City::City(string cityName, int xCoor, int yCoor){
	this->name=cityName;
	this->xCoor=xCoor;
	this->yCoor=yCoor;
	this->visited=false;
	this->dist=-1;
	this->prev=NULL;
	this->adjacent=vector<City *>();
	for(unsigned int i=0; i<4; i++)
		this->adjacent.push_back((City *) NULL);
	this->adjacent.shrink_to_fit();
}

//copy constructor
City::City(const City &o){
	this->name=o.getName();
	this->xCoor=o.getXCoor();
	this->yCoor=o.getYCoor();
	this->visited=o.visited;
	this->dist=o.dist;
	this->prev=o.prev;
	this->adjacent=vector<City *>();
	list<City *> temp = o.getAdjacent();
	for(auto a:temp){
		if(a->getXCoor()==this->xCoor){
			if(a->getYCoor()>this->yCoor){
				if(this->adjacent[0]==NULL)
					this->adjacent[0]=a;
				else
					if(a->getYCoor()<this->adjacent[0]->getYCoor())
						this->adjacent[0]=a;
			} else if(a->getYCoor()<this->yCoor){
				if(this->adjacent[2]==NULL)
					this->adjacent[2]=a;
				else
					if(a->getYCoor()>this->adjacent[2]->getYCoor())
						this->adjacent[2]=a;
			}
		} else if(a->getYCoor()==this->yCoor){
			if(a->getXCoor()>this->xCoor){
				if(this->adjacent[1]==NULL)
					this->adjacent[1]=a;
				else
					if(a->getXCoor()<this->adjacent[1]->getXCoor())
						this->adjacent[1]=a;
			} else if(a->getXCoor()<this->xCoor){
				if(this->adjacent[3]==NULL)
					this->adjacent[3]=a;
				else
					if(a->getXCoor()>this->adjacent[3]->getXCoor())
						this->adjacent[3]=a;
			}
		}
	}
}

//destructor
City::~City(){
	for(unsigned int i=0; i<4; i++){
		this->adjacent[i]=NULL;
	}
	this->prev=NULL;
}

//compares cities using string.operator<(string)
bool City::operator<(const City &o) const {
	return this->name<o.getName();
}

//creates and returns a list of all City pointers in this->adjacent
list<City*> City::getAdjacent() const {
	list<City *> adj = list<City *>();
	for(unsigned int i=0; i<this->adjacent.size(); i++){
		if(this->adjacent[i]!=NULL)
			adj.push_back(this->adjacent[i]);
	}
	return adj;
}

//prints city
void City::print() const {
	cout << "[" << this->name << ":(" << this->xCoor << "," << this->yCoor << ")] ";
}
