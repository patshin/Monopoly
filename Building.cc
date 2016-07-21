#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "Building.h"
using namespace std;

Building::Building(bool ownable,std::string name,int site,TextDisplay* display,Board* board):
ownable(ownable), name(name), site(site), display(display), board(board){
 curplayer.clear();
}
int Building::getSite(){
 return site;
}
string Building::getName(){
 return name;
}
bool Building::getOwn(){
 return ownable;
}
void Building::setPlayer(Player* p){
 int i = curplayer.size();
 for(int n = 0 ; n < i ; n++){
  if(p->getChar() == curplayer[n]->getChar()){
   return;
  }
 }
 curplayer.push_back(p);
 d->setOwner(p->getChar(),site);
}
void Building::removePlayer(Player* p){
 int i = curplayer.size();
 for(int n = 0 ; n < i ; n++){
  if(p->getChar() == curplayer[n]->getChar()){
   curplayer.erase(vec.begin()+n);
   d->removePlayer(P->getChar(),site);
  }
 }
}


Building::tradable(Player *p){
 if(!ownable){
 	return false;
 }
 vector <Building*> *ptr = p->getBuildingList();
 int n = ptr->size();
 bool contain = false;
 for(int i = 0 ; i < n ; i++){
  if((ptr[i])->getOwn()){
   if(((ptr[i])->getOwner())->getName() == p->getName()) {
   	if(((ptr[i])->getName())==name){
   		contain = true;
   	}
   	if(((ptr[i])->getAca()) == true){
   		if(((ptr[i])->getImproveCount())!=0){
   			return false;
   		}
   	}
   }
  }
 }
 if(contain == false){
 	return false;
 }else{
 	return true;
 }
}

