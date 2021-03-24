
#ifndef ANT_H
#define ANT_H

class Ant{
	private:
		int id;
		int x;
		int y;
		int xp;
	public:
		Ant(int);
		void move();
		int getID(){
			return this->id;
		};

		int getX(){
			return this->x;
		};
		int getY(){
			return this->y;
		};
		Ant* fight(Ant*);
		//write any additional functions on your own.
};

#endif
