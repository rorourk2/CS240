#include "AntHill.h"
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <fstream>

AntHill::AntHill(){
	this->current_ants=3;
	this->food=0;
	/*this->headAnt=new Ant();
	this->headAnt->setNextAnt();
	this->headAnt->getNextAnt()->setNextAnt();*/
	this->list= new LinkedList();
	Ant *a=new Ant();
	Ant *b=new Ant();
	Ant *c=new Ant();
	list->addNode(a);
	list->addNode(b);
	list->addNode(c);
	this->round=0;
	this->attackOdds=5;
	this->foodOdds=5;
	this->battleOdds=5;
	this->success=0;
	this->failure=0;
	this->attacks=0;
	//file = fopen("anthill.log", "w+");
}
AntHill::~AntHill(){
	/*Ant curr=this->headAnt;
	Ant nex=this->headAnt;
	fclose(file);
	while(curr->getNextAnt!=NULL){
		nex=curr->getNextAnt();
		delete curr;
		curr=nex;
	}*/
	delete this->list;
	//fclose(file);
	
}
int AntHill::getCurrentNumAnts(){
	return this->current_ants;
}
void AntHill::turn(){
	std::fstream fil;
	fil.open("anthill.log", std::fstream::in | std::fstream::out | std::fstream::app);
	Ant *curr=this->list->findAnt();
	if(this->round==0){
		fil<< "\t=============== Turn #";
		fil<< this->round;
		fil<< " ===============\n";
		fil<<"The hill currently has:\n";
		fil<<"\tFood:";
		fil<< this->food;
		fil<<"\n\tAnts:";
		fil<< this->current_ants;
		fil<<"\nThe hill has been attacked ";
		fil<<this->attacks;
		fil<<" times:\n";
		fil<<"\tSuccessfully defended:";
		fil<<this->success;
		fil<<"\n\tFailed to defend:";
		//std::cout<<"food"<<this->food<<std::endl;
		fil<<this->failure;
		fil<<"\n";
	}
	/*Ant nex=this->headAnt;*/
	int i=0;
	this->list->reset();
	bool suc=true;
	//fprintf(file,"\t=============== Turn #",this->round," ===============\n");
	this->round+=1;
	/*fprintf(file,"The hill currently has:");
	fprintf(file,"\tFood:",this->food);
	fprintf(file,"\tAnts:",this->current_ants);
	fprintf(file,"The hill has been attacked ",this->attacks," times:");
	fprintf(file,"\tSuccessfully defended:",this->success);
	fprintf(file,"\tFailed to defend:",this->failure);*/
	//std::cout<<"1"<<std::endl;
	while(this->food>0){
		//std::cout<<"2"<<std::endl;
		addAnt();
		food--;
		//std::cout<<"3"<<std::endl;
	}
	int num=0;
	int rot=0;
	int org=this->current_ants;
	while(rot<org){
		curr=this->list->findAnt();
		num++;
		//std::cout<<"4"<<std::endl;
		suc=true;
		//nex=curr->getNextAnt();
		curr->move();
		i=rand() %battleOdds;
		if(i==0){
			//std::cout<<"5"<<std::endl;
			suc=curr->rivalDuel();
			fil<<"Ant #";
			fil<<num;
			fil<<" has run into rival ant\n";
			//fprintf(file,"Ant #",num," has run into a rival ant");
			//std::cout<<"6"<<std::endl;
			if(suc==true){
				//std::cout<<"6.2"<<std::endl;
				fil<<"Ant #";
				fil<<num;
				fil<<" won the fight\n";
				//fprintf(file,"Ant #",num," won the fight");
			}else{
				
				fil<<"Ant #";
				fil<<num;
				fil<<" lost the fight and died\n";
				//fprintf(file,"Ant #",num," lost the fight and died");

				this->list->deleteNode();

				this->current_ants--;

			}
			//std::cout<<"7"<<std::endl;
		}
		else{
			//std::cout<<"8"<<std::endl;
			i=rand() %foodOdds;
			if(i==0){
				food+=1;
			}

		}
		/*if(suc==false && t==0){
			current_ants-=1;
			this->headAnt=nex;
			delete curr;
		}else if(suc==false){
			current_ants-=1;
			delete curr;
			t=1;
		}else{
			t=1;
		}*/
		//std::cout<<"9"<<std::endl;
		rot++;

		if(rot!=org){
			//std::cout<<"10"<<std::endl;
			this->list->increment();
			//std::cout<<"10.5"<<std::endl;
		}

		
	}
	i=rand() %attackOdds;

	//std::cout<<"11"<<std::endl;
	if(i==0){
		battle();
		this->attacks++;
	}

	//std::cout<<"12"<<std::endl;
	this->list->reset();
	fil<< "\t=============== Turn #";
	fil<< this->round;
	fil<< " ===============\n";
	fil<<"The hill currently has:\n";
	fil<<"\tFood:";
	fil<< this->food;
	fil<<"\n\tAnts:";
	fil<< this->current_ants;
	fil<<"\nThe hill has been attacked ";
	fil<<this->attacks;
	fil<<" times:\n";
	fil<<"\tSuccessfully defended:";
	fil<<this->success;
	fil<<"\n\tFailed to defend:";
	//std::cout<<"food"<<this->food<<std::endl;
	fil<<this->failure;
	fil<<"\n";
	fil.close();
	//std::cout<<"13"<<std::endl;
}
void AntHill::battle(){
	/*Ant curr=this->headAnt;
	Ant nex=this->headAnt;
	
	int hea=0;*/

	int x=0;
	int i=0;
	this->list->reset();
	int rot=0;
	Ant *curr=this->list->findAnt();
	this->list->increment();

	while(rot<this->current_ants){
		if(curr->getCurrentX()<=curr->getMaxX() && curr->getCurrentY()<=curr->getMaxY()){
			x++;
		}
		rot++;
		if(rot!=this->current_ants){
			curr=this->list->findAnt();
			this->list->increment();
		}
	}
	i=rand() %current_ants +1;
	if(x<=i){
		this->failure++;
		this->list->reset();
		curr=this->list->findAnt();
		rot=0;
		int orig=this->current_ants;
		while(rot<orig){
			curr=this->list->findAnt();
			rot++;
			if(curr->getCurrentX()>=curr->getMaxX()/4 && curr->getCurrentY()>=curr->getMaxX()/4 && curr->getCurrentX()<=curr->getMaxX()/4*3 && curr->getCurrentY()<=curr->getMaxY()/4*3){

				this->list->deleteNode();

				this->current_ants--;
			}
			else{
				this->list->increment();
			}
			
		}
	}
	else{
		this->success++;
	}

	this->list->reset();

}
void AntHill::addAnt(){
	/*Ant curr=this->headAnt;
	while(curr.getNextAnt!=NULL){
		curr=curr.getNextAnt();
	}
	curr.setNextAnt();*/
	this->list->addNode(new Ant());
	this->current_ants++;
}
