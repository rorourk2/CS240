#ifndef ANTHILL_H
#define ANTHILL_H
#include "LinkedList.h"
class AntHill{
	private:
		int current_ants;
		int food;
		//Ant *headAnt;
		LinkedList *list;
		int round;
		int attackOdds;
		int foodOdds;
		int battleOdds;
		int success;
		int failure;
		int attacks;
		//FILE *file;
	public:
		AntHill();
		~AntHill();
		void turn();
		//void makeAnts();
		void addAnt();//
		void battle();
		int getCurrentNumAnts();
		
};

#endif
