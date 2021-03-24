#include "Map.h"
#include "City.h"
#include "Filereader.h"
#include <fstream>
#include <iostream>
#include <exception>
#define DEBUG false

using namespace std;

//used to save space
void Map::cheatoConstructor(string filename, bool heap){
	this->heap=heap;
	this->locations=vector<City *>();
	this->adjacencies=0;
	this->he=vector<City *>();
	ifstream file;
	file.open(filename);
	if(!file || !file.good()){
		//if the file isn't valid
		cout << "Bad input file" << endl;
		if(file.is_open())
			file.close();
	} else {
		//if the file is valid
		FileReader reader = FileReader(&file);
		if(!reader.readFile()){
			//if the file failed to be read
			cout << "Failed to read file" << endl;
			file.close();
		} else {
			//if the file was successfully read
			cout << "Successfully read file" << endl;
			file.close();
			do{
				try{
					if(DEBUG)
						cout << "Adding city... (" << reader.current() << ")" << endl;
					this->locations.push_back(this->cityFromString(reader.current()));
				} catch (exception e){
					cout << endl;
					cout << "Caught Exception" << endl;
					throw e;
				}
			} while(reader.next());
			this->locations.shrink_to_fit();
			this->addAdjacencies();
		}
	}
}

//destructor for Map
Map::~Map(){
	for(unsigned int i=0; i<this->locations.size(); i++){
		delete this->locations[i];
		this->locations[i]=NULL;
	}
	for(unsigned int i=0; i<this->he.size(); i++){
		this->he[i]=NULL;
	}
}

//adds adjacencies to all cities in the map and returns the number of adjacencies it made
unsigned int Map::addAdjacencies(){
	unsigned int found_adj=0;
	for(auto a:this->locations){
		for(auto b:this->locations){
			if(a->getXCoor()==b->getXCoor()){
				int ay=a->getYCoor();
				int by=b->getYCoor();
				int cy;
				if(ay<by){
					if(a->adjacent[0]==NULL){
						a->adjacent[0]=b;
						found_adj++;
					} else {
						cy=a->adjacent[0]->getYCoor();
						if(by<cy)
							a->adjacent[0]=b;
					}
				} else if(ay>by){
					if(a->adjacent[2]==NULL){
						a->adjacent[2]=b;
						found_adj++;
					} else {
						cy=a->adjacent[2]->getYCoor();
						if(by>cy)
							a->adjacent[2]=b;
					}
				}
			} else if(a->getYCoor()==b->getYCoor()){
				int ax=a->getXCoor();
				int bx=b->getXCoor();
				int cx;
				if(ax<bx){
					if(a->adjacent[1]==NULL){
						a->adjacent[1]=b;
						found_adj++;
					} else {
						cx=a->adjacent[1]->getXCoor();
						if(bx<cx)
							a->adjacent[1]=b;
					}
				} else if(ax>bx){
					if(a->adjacent[3]==NULL){
						a->adjacent[3]=b;
						found_adj++;
					} else {
						cx=a->adjacent[3]->getXCoor();
						if(bx>cx)
							a->adjacent[3]=b;
					}
				}
			}
		}
	}
	this->adjacencies+=found_adj;
	if(DEBUG){
		cout << "Found " << found_adj << " new adjacencies: " << this->adjacencies << " total" << endl;
		for(unsigned int i=0; i<this->locations.size(); i++){
			cout << "\t" << this->locations[i]->getName() << ":\t[";
			bool started = false;
			for(unsigned int j=0; j<4; j++){
				if(this->locations[i]->adjacent[j]!=NULL){
					if(!started)
						started = true;
					else
						cout << "\t";
					switch(j){
						case 0:
							cout << "(N: ";
							break;
						case 1:
							cout << "(E: ";
							break;
						case 2:
							cout << "(S: ";
							break;
						case 3:
							cout << "(W: ";
					}
					cout << this->locations[i]->adjacent[j]->getName() << ")";
				}
			}
			cout << "]" << endl;
		}
	}
	return found_adj;
}

//makes and returns a city made from a string
City * Map::cityFromString(string str) const {
	if(DEBUG)
		cout << "From: [" << str << "] to ";
	string name;
	int x, y;
	unsigned int index = 0;
	while(index<str.size() && str[index]!=' ')
		index++;
	name=str.substr(0, index);
	if(DEBUG)
		cout << name << ":";
	x=(int) index++;
	while(index<str.size() && str[index]!=' ' && str[index]!='\t' && str[index]!='\n')
		index++;
	x=stoi(str.substr(x, index));
	if(DEBUG)
		cout << "(" << x;
	y=(int) index++;
	while(index<str.size() && str[index]!=' ' && str[index]!='\t' && str[index]!='\n')
		index++;
	y=stoi(str.substr(y, index));
	if(DEBUG)
		cout << "," << y << ")" << endl;
	return new City(name, x, y);
}

//finds and returns a city based on the name
City* Map::findByName(string cityName){
	unsigned int i=0;
	while(i<locations.size()){
		if(locations[i]->getName().compare(cityName)==0){
			return locations[i];
		}
		i++;
	}
	return NULL;
}

//returns a lists of cities one must travel through on the shortest path from one city to the destination; can only change directions at cities
vector<City *> Map::shortestPath(City * start, City * dest){
	vector<City *> toReturn = vector<City *>();
	if(start==dest){
		toReturn.insert(toReturn.begin(),start);
		return toReturn;
	}
	start->dist=0;
	if(this->heap){
		this->he.push_back(start);
		pathDistanceHelper2(start);
	}else{
		pathDistanceHelper(start);
	}
	City * nex=dest;
	toReturn.insert(toReturn.begin(), nex);
	while(nex->prev!=NULL){
		nex=nex->prev;
		toReturn.insert(toReturn.begin(), nex);
	}
	if(nex!=start)
		toReturn.clear();
	for(unsigned int i=0; i<locations.size(); i++){
		locations[i]->visited=false;
		locations[i]->dist=-1;
		locations[i]->prev=NULL;
	}
	if(DEBUG){
		cout << "From " << start->getName() << " to " << dest->getName() << ":\t";
		for(unsigned int i=0; i<toReturn.size(); i++){
			if(i!=0)
				cout << "->";
			cout << toReturn[i]->getName();
		}
		cout << endl;
	}
	return toReturn;
}

//returns the shortest distance between two cities
unsigned int Map::pathDistance(City * start, City * dest){
	int toReturn=0;
	if(start==dest)
		return toReturn;
	start->dist=0;
	if(this->heap){
		
		this->he.push_back(start);
		pathDistanceHelper2(start);
	}else{
		pathDistanceHelper(start);
	}
	toReturn=dest->dist;
	
	/*City * nex=dest;
	toReturn+=nex->dist;*/
	/*while(nex->prev!=NULL){
		nex=nex->prev;
		toReturn+=nex->dist;
	}
	if(nex!=start)
		toReturn=-1;*/
	for(unsigned int i=0; i<locations.size(); i++){
		locations[i]->visited=false;
		locations[i]->dist=-1;
		locations[i]->prev=NULL;
	}
	/*vector<City *> path=shortestPath(start,dest);
	unsigned int i=0;
	while(i<path.size()){
		toReturn+=path[i]->dist;
		i++;
	}
	path.clear();*/
	//vector<City *> path=shortestPath(start,dest);
	return toReturn;
}

//helps pathDistance and shortPath
void Map::pathDistanceHelper(City* start) {
	start->visited=true;
	if(start->adjacent[0]!=NULL && start->adjacent[0]->visited==false){
		if(start->adjacent[0]->dist==-1 || start->adjacent[0]->dist>(start->adjacent[0]->yCoor-start->yCoor)){
			start->adjacent[0]->dist=start->dist+(start->adjacent[0]->yCoor-start->yCoor);
			start->adjacent[0]->prev=start;
		}
	}
	if(start->adjacent[1]!=NULL && start->adjacent[1]->visited==false){
		if(start->adjacent[1]->dist==-1 || start->adjacent[1]->dist>(start->dist+start->adjacent[1]->xCoor-start->xCoor)){
			start->adjacent[1]->dist=start->dist+(start->adjacent[1]->xCoor-start->xCoor);
			start->adjacent[1]->prev=start;
		}
	}
	if(start->adjacent[2]!=NULL && start->adjacent[2]->visited==false){
		if(start->adjacent[2]->dist==-1 || start->adjacent[2]->dist>(start->dist+start->yCoor-start->adjacent[2]->yCoor)){
			start->adjacent[2]->dist=start->dist+(start->yCoor-start->adjacent[2]->yCoor);
			start->adjacent[2]->prev=start;
		}
	}
	if(start->adjacent[3]!=NULL && start->adjacent[3]->visited==false){
		if(start->adjacent[3]->dist==-1 || start->adjacent[3]->dist>(start->dist+start->xCoor-start->adjacent[3]->xCoor)){
			start->adjacent[3]->dist=start->dist+(start->xCoor-start->adjacent[3]->xCoor);
			start->adjacent[3]->prev=start;
		}
	}
	City * next=NULL;
	unsigned int i=0;
	while(i<locations.size()){
		if(locations[i]->visited==false){
			if(locations[i]->dist!=-1){
				if(next==NULL || locations[i]->dist<next->dist)
					next=locations[i];
			}
		}
		i++;
	}
	if(next==NULL){
		return;
	}
	pathDistanceHelper(next);
}

void Map::pathDistanceHelper2(City* start) {
	he.erase(he.begin());
	start->visited=true;
	if(start->adjacent[0]!=NULL && start->adjacent[0]->visited==false){
		if(start->adjacent[0]->dist==-1 || start->adjacent[0]->dist>(start->adjacent[0]->yCoor-start->yCoor)){
			start->adjacent[0]->dist=start->dist+(start->adjacent[0]->yCoor-start->yCoor);
			start->adjacent[0]->prev=start;
			this->he.push_back(start->adjacent[0]);
		}
	}
	if(start->adjacent[1]!=NULL && start->adjacent[1]->visited==false){
		if(start->adjacent[1]->dist==-1 || start->adjacent[1]->dist>(start->dist+start->adjacent[1]->xCoor-start->xCoor)){
			start->adjacent[1]->dist=start->dist+(start->adjacent[1]->xCoor-start->xCoor);
			start->adjacent[1]->prev=start;
			this->he.push_back(start->adjacent[1]);
		}
	}
	if(start->adjacent[2]!=NULL && start->adjacent[2]->visited==false){
		if(start->adjacent[2]->dist==-1 || start->adjacent[2]->dist>(start->dist+start->yCoor-start->adjacent[2]->yCoor)){
			start->adjacent[2]->dist=start->dist+(start->yCoor-start->adjacent[2]->yCoor);
			start->adjacent[2]->prev=start;
			this->he.push_back(start->adjacent[2]);
		}
	}
	if(start->adjacent[3]!=NULL && start->adjacent[3]->visited==false){
		if(start->adjacent[3]->dist==-1 || start->adjacent[3]->dist>(start->dist+start->xCoor-start->adjacent[3]->xCoor)){
			start->adjacent[3]->dist=start->dist+(start->xCoor-start->adjacent[3]->xCoor);
			start->adjacent[3]->prev=start;
			this->he.push_back(start->adjacent[3]);
		}
	}
	//City * next=NULL;
	/*unsigned int i=0;
	while(i<locations.size()){
		if(locations[i]->visited==false){
			if(locations[i]->dist!=-1){
				if(next==NULL || locations[i]->dist<next->dist)
					next=locations[i];
			}
		}
		i++;
	}*/
	if(this->he.size()==0){
		return;
	}
	pathDistanceHelper(this->he[0]);
}
