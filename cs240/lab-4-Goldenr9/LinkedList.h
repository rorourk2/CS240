#ifndef LinkedList_H
#define LinkedList_H
#include <iostream>
#include <cstring>
template <class T>
class Node{
	private:
		T data;
		//int index;
		Node *nextNode;
	public:
		Node(T data){
			this->data=data;
			this->nextNode=NULL;
		}
		Node *getNextNode(){
			return this->nextNode;
		}
		T getData(){
			return this->data;
		}
		void reconnect(){
			this->nextNode=this->nextNode->getNextNode();
		}
		void setNextNode(T *data){
			Node a=new Node(data);
			this->nextNode=a;
		}
		//int getId();
		~Node(){
			delete this->data;
		}
};
template <class T>
class LinkedList{
	private:
		Node<T> *node1;
		Node<T> *currentNode;
	public:
		LinkedList(){
			this->node1=NULL;
			this->currentNode=NULL;
		}
		LinkedList(const LinkedList& sll){
			if(sll.node1==NULL){
				this->node1=NULL;
				this->currentNode=NULL;
			}
			else{
				Node<T> *n= sll.node1;
				this->node1=new Node<T>(n->getData());
				//Node *t=this->node1->getNextNode();
				Node<T> *old=sll.node1;
				while(old->getNextNode()!=NULL){
					old=old->getNextNode();
					this->addNode(old->getData());
					//t=t->getNextNode();
			
				}
			}
		}
		~LinkedList(){
			if(this->node1!=NULL){
			Node<T> *n=this->node1;
			Node<T> *t=this->node1;
			while(n->getNextNode()!=NULL){
				n=n->getNextNode();
				delete t;
				t=n;
			}
			delete t;
			}	
		}
		void insert(T data){
			if(this->node1==NULL){
				this->node1=new Node<T>(data);
			}else{
				Node<T> *n=this->node1;
				while(n->getNextNode()!=NULL){
					n=n->getNextNode();
				}
				n->setNextNode(data);
			}
		}
		T read(){
			if(currentNode==NULL){
				return NULL;
			}
			T d=this->currentNode->getData();
			this->currentNode=currentNode->getNextNode();
			return d;
		}
		bool empty(){
			if(node1==NULL){
				return true;
			}
			return false;
		}
		void reset(){
			this->currentNode=this->node1;
		}
		bool remove(T &data){
			this->reset();
			Node<T> *a=this->node1;
			Node<T> *b=this->node1;
			if(this->node1==NULL){
				return false;
			}
			if(data==this->node1->getData()){
				this->node1=this->node1->getNextNode();
				this->currentNode=this->node1;
				delete a;
				return true;
			}
			while(a->getNextNode()!=NULL){
				b=a->getNextNode();
				if(b.getData()=data){
					a->reconnect();
					delete b;
					return true;
				}
				a=b;
			}
			return false;
		}
};

#endif