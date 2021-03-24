#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "Heap.h"
using namespace std;
Heap::Heap(){
	//num=0;
}
Heap::~Heap(){
	vec.clear();
}
void Heap::clear(){
	vec.clear();
}
Heap::Heap(string filename){
	
	string name;
	string budgetTemp;
	int budget;

	//string line;
	string line;

	char filenameArray[100];
	for (unsigned int i = 0; i < filename.size(); i++) {

		filenameArray[i] = filename[i];

	}

	filenameArray[filename.size()] = '\0';

	ifstream myfile (filenameArray);
	if (myfile.is_open()) {


		int i = 0;
		
		getline(myfile, line);

		while (i == 0) {

			name = line;
			getline(myfile, line);
			budgetTemp = line;
			stringstream ss(budgetTemp);
			ss >> budget;
			Player player(name, budget);
			vec.push_back(player);
			//this->num++;
			getline(myfile, line);
			if (myfile.eof()) { i = 1; }		

		}
		heapify();

		myfile.close();

	}

	else { cout << "File cannot be opened" << endl; }
	/*char filenameArray[100];
	for (int i = 0; i < filename.size(); i++) {

		filenameArray[i] = filename[i];

	}

	filenameArray[filename.size()] = '\0';*/

	//ifstream myfile (filenameArray);
	/*ifstream myfile;
	myfile.open(filename);
	if (myfile.is_open()) {
		while(getline(myfile, name) && getline(myfile, budgetTemp)){
			budget = stoi(budgetTemp);
			Player player(name, budget);
			vec.push_back(player);
		}

		int i = 0;
		
		getline(myfile, line);

		while (i == 0) {

			name = line;
			getline(myfile, line);
			budgetTemp = line;
			stringstream the(budgetTemp);
			the >> budget;
			//Player * player = new Player(name, budget);
			//vec.push_back(*player);
			Player player(name, budget);
			vec.push_back(player);
			num++;
			getline(myfile, line);
			if (myfile.eof()) { i = 1; }		

		}*/
		//heapify();

		//myfile.close();

	

	//else { cout << "Invalid File" << endl; }
	//printHeap();
}
Heap::Heap(const Heap &copy){
	for (int i = 0; i < size(); i++) {
		vec.push_back(copy.vec[i]);
	}
}
void Heap::heapify(){ 
	for (int x = (size()- 2)/2; x >= 0; x--) {
		shiftDown(x);
	}
}
void Heap::shiftUp(int p) {
	if ((p < 0) || (p >= size()))
		{ return; } 
	int i = 0;
	int par = getParent(p);
	while (par != -1) {

		if (vec[p].getBudget() > vec[par].getBudget()) 
		{		
			Player temp;
			temp = vec[p];
			vec[p] = vec[par];
			vec[par] = temp;

			p = par;
			par = getParent(par);
		}

		else { return; }

	}
}
void Heap::shiftDown(int p) {
	if ((p < 0) || (p >= this->size())) { return; } 
	while (!isLeaf(p)) { 
		int l = getLeft(p); 
		int r = -1;
		int max = l;
	        if ((l + 1 < this->size())) {
			r = l + 1; 
		}
	
		if (r != -1 && vec[l].getBudget() < vec[r].getBudget()) {
			max = r; 
		}

		if (vec[max].getBudget() > vec[p].getBudget()) {
			
		    Player temp;
			temp = vec[p];
			vec[p] = vec[max];
			vec[max] = temp;
		}

		p = max;
	}
}
void Heap::addPlayer(Player newPlayer){
	/*if(root==NULL){
		root= new Node(newPlayer);
		attachNode=root;
	}else if(newestNode->left==NULL){
		attachNode->left= new Node(newPlayer);
		attachNode->left->parent=attachNode;
	}else if(newestNode->right==NULL){
		attachNode->right= new Node(newPlayer);
		attachNode->left->parent=attachNode;
		if(attachNode->parent!=NULL && attachNode=attachNode->parent->right){
			attachNode=attachNode->parent->left->left;
		}else if(attachNode->parent!=NULL && attachNode=attachNode->parent->left){
			attachNode=attachNode->parent->right;
		}else{
			attachNode=attachNode->left;
		}
	}
	heapify();
	size++;*/
	vec.push_back(newPlayer);
	shiftUp(size()-1);
	//num++;
}
Player Heap::getPlayer(){
	/*if(root==NULL){
		return NULL;
	}
	Player ret=root->player;
	if(root->left==NULL){
		delete root;
		return ret;
	}
	if(attachNode->left!=NULL){
		root->player=attachNode->left->player;
		delete attachNode->left;
	}else{
		Node re=attachNode;
		root->player=attachNode->player;
		attachNode=attachNode->parent;
		delete re;
	}
	heapify();
	size--;*/
	if(!empty()){
		Player p= vec[0];
		vec[0] = vec[size() - 1];
		vec.pop_back();
		//num--;
		shiftDown(0);
	
	//printHeap();
		return p;
	}
	Player p("This is not a player",0);
	return p;
}
bool Heap::isLeaf(int p) {

	if ((2*(p)) + 1 > size() && (2*(p)) + 2 > size()) {
		return true;
	}
	else { return false; }

}

int Heap::getLeft(int p) {
	return (2*(p) + 1);
}

int Heap::getParent(int p) {

	if (p == 0) { return -1; }
	else { return (p-1)/2; }

}
vector<Player> Heap::getArray(){
	/*std::vector<Player> v;
	if(root!=NULL){
		v.push_back(root->player);
		Node curr=root;
		while(curr!=NULL){
			if(curr->left!=NULL){
				v.push_back(curr->left->player);
					if(curr->right!=NULL){
						v.push_back(curr->right->player);
					}
			}
		}
	}*/
	return vec;
}
bool Heap::empty(){
	if(size()==0){
		return true;
	}
	return false;
}
unsigned int Heap::size(){
	return vec.size();
}
void Heap::printHeap() {

	/*for (int i = 0; i < size(); i++) {
		cout << vec[i].getName() << ", ";
		cout << vec[i].getBudget() << endl;
	}
	cout << "/n" << endl;*/
}
