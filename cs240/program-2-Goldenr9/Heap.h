#ifndef HEAP_H
#define HEAP_H
#include <vector>
#include <string>
#include "Player.h"
class Heap{
	private:
		/*class Node{
			public:
				Node *left, *right, *parent;
				Player player;
				Node(Player n){player=n;left=NULL;right=NULL;parent=NULL;};
			}
		Node *root;
		unsigned int size;
		Node *attachNode;
		Node *newestNode;
		void heapify();*/
		std::vector<Player> vec;
		//int num;
		void heapify();
		void shiftDown(int);
		bool isLeaf(int);
		int getLeft(int);
		void remove();
		void shiftUp(int);
		int getParent(int);
	public:
		
		Heap();
		~Heap();
		Heap(std::string filename);
		Heap(const Heap &copy);
		void clear();
		void addPlayer(Player newPlayer);
		Player getPlayer();
		std::vector<Player> getArray();
		bool empty();
		void printHeap();
		unsigned int size();
};

#endif
