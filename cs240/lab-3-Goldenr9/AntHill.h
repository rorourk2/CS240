#ifndef ANTHILL_H
#define ANTHILL_H
#include "Ant.h"



class AntHill{
	private:
		int current_ants;
		Ant ** ants;
		int next_id;
	public:
		AntHill();
		~AntHill();
		int addAnt();
		bool removeAnt(int);
		Ant* getAnt(int);
		void move();
		void printHillInfo();
		int getCurrentNumAnts(){
			return this->current_ants;
		}
};

#endif
