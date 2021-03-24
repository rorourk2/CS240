#ifndef ANT_H
#define ANT_H
class Ant{
	private:
		/*Ant *nextAnt;
		Ant *previousAnt;*/
		int maxX;
		int maxY;
		int currentX;
		int currentY;
	public:
		Ant();
		/*~Ant();*/
		Ant(const Ant&);
		/*Ant *getPreviousAnt();
		Ant *getNextAnt();*/
		int getCurrentX();
		int getCurrentY();
		int getMaxX();
		int getMaxY();
		bool rivalDuel();
		void move();
};

#endif
