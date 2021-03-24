#include "LinkedList.h"
#include <iostream>
#include <cstring>

LinkedList::LinkedList(){
	this->node1=NULL;
	this->lastNode=NULL;
	this->currentNode=NULL;
}
LinkedList::LinkedList(const LinkedList& l){
	if(l.node1==NULL){
		this->node1=NULL;
	}
	else{
		Node *n= l.node1;
		this->node1=new Node(n->getAnt());
		//Node *t=this->node1->getNextNode();
		Node *old=l.node1;
		while(old->getNextNode()!=NULL){
			old=old->getNextNode();
			this->addNode(old->getAnt());
			//t=t->getNextNode();
			
		}
	}
}
Ant *LinkedList::findAnt(){
	/*Node *n=this->node1;
	while(x>0){
		n=n->getNextNode();
		x--;
	}*/
	return this->currentNode->getAnt();
}
void LinkedList::increment(){
	if(this->currentNode->getNextNode()!=NULL){
		this->currentNode=this->currentNode->getNextNode();
	}else{
		this->currentNode=this->lastNode;
	}
}
void LinkedList::reset(){
	this->currentNode=this->node1;
}
/*Node *LinkedList::getNode1(){
	return this->node1;
}*/
/*Node *LinkedList::findNode(int x){
	Node *n=this->getNode1();
	if(n->getId()==x){
		return n;
	}
	while(n->getNextNode()!=NULL){
		n=n->getNextNode();
		if(n->getId()==x){
			return n;
		}
	}
	return NULL;
}*/
void LinkedList::deleteNode(){
	/*Node *n=this->getNode1();
	if(n->getId()==x){
		this->node1=n->getNextNode();
		delete n;
	}
	Node *t=n;
	while(n->getNextNode()!=NULL){
		n=n->getNextNode();
		if(n->getId()==x){
			t->reconnect();
			delete n;
			break;
		}
		t=t->getNextNode();
	}*/
	Node *n=this->node1;

	if(this->node1==this->currentNode){

		this->node1=n->getNextNode();
		delete n;
		this->currentNode=this->node1;
	}
	else{
		while(n->getNextNode()!=this->currentNode){

			n=n->getNextNode();
		}

		n->reconnect();

		delete this->currentNode;

		if(n->getNextNode()!=NULL){
			this->currentNode=n->getNextNode();
		}else{
			this->lastNode=n;

		}

		/*Node *t=this->node1;
		x--;
		n=n->getNextNode();
		while(x>0){
			n=n->getNextNode();
			x--;
			t=t->getNextNode();
		}
		t->reconnect();
		delete n;*/
	}
	
}
/*void LinkedList::AddNode(int x){
	if(this->getNode1()==NULL){
		this->node1=new Node(x);
	}else{
		Node *n=this->getNode1();
		while(n->getNextNode()!=NULL){
			n=n->getNextNode();
		}
		n->setNextNode(x);
	}
}*/
void LinkedList::addNode(Ant *a){
	/*if(this->getNode1()==NULL){
		this->node1=new Node(x);
	}else{
		Node *n=this->getNode1();
		while(n->getNextNode()!=NULL){
			n=n->getNextNode();
		}
		n->setNextNode(x);
	}*/
	
	if(this->node1==NULL){
		
		this->node1=new Node(a);
		this->lastNode=this->node1;
		this->currentNode=this->node1;
	}else{
		this->lastNode->setNextAnt(a);
		this->lastNode=this->lastNode->getNextNode();
	}
}
LinkedList::~LinkedList(){
	if(this->node1!=NULL){
		Node *n=this->node1;
		Node *t=this->node1;
		while(n->getNextNode()!=NULL){
			n=n->getNextNode();
			delete t;
			t=n;
		}
		delete t;
	}
}
Node::Node(Ant *a){
	this->ant=a;
	this->nextNode=NULL;
	
}
Node *Node::getNextNode(){
	return this->nextNode;
}
void Node::reconnect(){
	Node *n=this->getNextNode()->getNextNode();
	this->nextNode=n;
}
void Node::setNextNode(Node *n){
	
	this->nextNode=n;
	/*Node *t=this;
	while(t->getNextNode()!=NULL){
			t=t->getNextNode();
	}
	t->nextNode=n;*/
}
Ant *Node::getAnt(){
	return this->ant;
}
void Node::setNextAnt(Ant *a){
	
	this->nextNode=new Node(a);
	/*Node *t=this;
	while(t->getNextNode()!=NULL){
			t=t->getNextNode();
	}
	t->nextNode=n;*/
}
Node::~Node(){
	delete this->ant;
}
/*int Node::getId(){
	return this->id;
}*/

