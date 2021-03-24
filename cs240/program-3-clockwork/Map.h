#ifndef MQRR_MAP_H
#define MQRR_MAP_H
#include "City.h"
#include "Filereader.h"
#include <string>
#include <vector>

class Map{
	private:
		std::vector<City *> locations;
		std::vector<City *> he;
		unsigned int adjacencies;
		bool heap;
		City * cityFromString(std::string) const; //makes and returns a city made from a string
		unsigned int addAdjacencies(); //adds adjecencies to all cities in the map and returns the number of adjecencies it made
		void cheatoConstructor(std::string, bool); //used to actually construct things
		void pathDistanceHelper(City*); //helps pathDistance and shortPath
		void pathDistanceHelper2(City*);//The sequel
	public:
		Map(std::string filename){this->cheatoConstructor(filename, false);}; //main constructor; also populates locations from file found through filename
		Map(std::string filename, bool heap){this->cheatoConstructor(filename, heap);};//Optimization algorithm constructor
		~Map(); //destructor for map
		City* findByName(std::string cityName);  //finds and returns a city based on the name
		std::vector<City *> shortestPath(City *, City *); //returns a lists of cities one must travel through on the shortest path from one city to the destination; can only change directions at cities
		unsigned int pathDistance(City *, City *); //returns the shortest distance between two cities
		
};

#endif
