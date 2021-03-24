#ifndef HASH_H
#define HASH_H
#include <string>
#include <vector>
class Hash{
	private:
		std::vector<std::string> ke;
		std::vector<std::string> val;
		unsigned int num;
	public:
		Hash(unsigned int);
		bool insert(std::string,std::string);
		bool remove(std::string);
		std::string find(std::string);
		bool empty();
		int size();
		void printHash();
		int hasher(std::string);
};




#endif
