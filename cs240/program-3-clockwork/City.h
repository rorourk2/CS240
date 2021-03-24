#ifndef MQRR_CITY_H
#define MQRR_CITY_H
#include <string>
#include <vector>
#include <list>

class City{
	
	private:
		int xCoor;
		int yCoor;
		bool visited;
		std::string name;
		int dist;
		City * prev;
		std::vector<City *> adjacent;
		friend class Map;
	public:
		City(std::string, int, int); //main constructor
		City(const City &o); //copy constructor
		~City(); //destructor
		std::string getName() const {return this->name;};
		int getXCoor() const {return this->xCoor;};
		int getYCoor() const {return this->yCoor;};
		std::list<City *> getAdjacent() const; //creates and returns adjacency list for city
		bool operator<(const City &) const; //compares cities using string.operator<(string)
		void print() const;
		
};

#endif
