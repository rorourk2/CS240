#ifndef LinkedList_H
#define LinkedList_H
#include "Ant.h"
class Node{
	private:
		Ant *ant;
		//int index;
		Node *nextNode;
	public:
		Node(Ant *);//
		Node *getNextNode();//
		Ant *getAnt();//
		void reconnect();//
		void setNextAnt(Ant *);//
		void setNextNode(Node *);//
		//int getId();
		~Node();
};

class LinkedList{
	private:
		Node *node1;
		Node *lastNode;
		Node *currentNode;
	public:
		LinkedList();//
		LinkedList(const LinkedList&);
		~LinkedList();//
		//Node *getNode1();
		Ant *findAnt();//
		void deleteNode();//
		void addNode(Ant *);//
		void increment();
		void reset();
		void operator <<(Ant *a){
			this->addNode(a);
		}
};

#endif
