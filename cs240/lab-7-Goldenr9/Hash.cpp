
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <fstream>
#include "Hash.h"
Hash::Hash(unsigned int i){
	std::string s="";
	ke.resize(i,s);
	val.resize(i,s);
	num=i;
}
bool Hash::insert(std::string key ,std::string value){
	/*int i=0;
	while(i<size){
		if(ke[i].compare("")==0){
			ke[i]=key;
			val[i]=value;
			return true;
		}
		i++;
	}*/
	int i=0;
	unsigned int x=0;
	while(x<num-1){
		x=hasher(key)+i;
		if(ke[x].compare("")==0){
			ke[x]=key;
			val[x]=value;
			return true;
		}
		i++;
	}
	return false;
}
bool Hash::remove(std::string key){
	/*int i=0;
	while(i<size){
		if(ke[i].compare(key)==0){
			ke[i]="";
			val[i]="";
			return true;
		}
		i++;
	}*/
	int i=0;
	unsigned int x=0;
	while(x<num-1){
		x=hasher(key)+i;
		if(ke[x].compare(key)==0){
			ke[x]="";
			val[x]="";
			return true;
		}
		i++;
	}
	return false;
}
std::string Hash::find(std::string key){
	/*int i=0;
	while(i<size){
		if(ke[i].compare(key)==0){
			return val[i];
		}
		i++;
	}*/
	unsigned int i=0;
	unsigned int x=0;
	while(x<num-1){
		x=hasher(key)+i;
		if(ke[x].compare(key)==0){
			return val[x];
		}
		i++;
	}
	return "";
}
bool Hash::empty(){
	unsigned int i=0;
	while(i<num){
		if(ke[i].compare("")!=0){
			return false;
		}
		i++;
	}
	return true;
}
int Hash::size(){
	return num;
}
void Hash::printHash(){
	unsigned int i=0;
	std::cout<< "========    Hash Table    ========"<<std::endl;
	while(i<num){
		std::cout<< "Index:"<<i<<"\t\t"<<"Key:"<<ke[i]<<"\t\t"<<"Value:"<<val[i] <<std::endl;
		i++;
	}
}
int Hash::hasher(std::string key){
	unsigned int i=0;
	unsigned int x=0;
	while(i<key.length()){
		x+=(int)key[i];
		i++;
	}
	x=x%num;
	return x;
}