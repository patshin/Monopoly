#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "Building.h"
using namespace std;

Building::Building(bool ownable,string name,int site,Textdisplay* display): ownable(ownable), name(name), site(site), display(display){
 curplayer.clear();
}
int Building::getSite(){
 return site;
}
Textdisplay* Building:: getBoard(){
 return this->display;
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
 display->setOwner(p->getChar(),site);
}
void Building::removePlayer(Player* p){
 int i = curplayer.size();
 for(int n = 0 ; n < i ; n++){
  if(p->getChar() == curplayer[n]->getChar()){
   curplayer.erase(curplayer.begin()+n);
   display->removePlayer(p->getChar(),site);
  }
 }
}


bool Building::tradable(Player *p){
 if(!ownable){
 	return false;
 }
 vector <Building*> *ptr = p->getBuildingList();
 int n = ptr->size();
 bool contain = false;
 for(int i = 0 ; i < n ; i++){
  if(((*ptr)[i])->getOwn()){
   if((((*ptr)[i])->getOwner())->getName() == p->getName()) {
   	if((((*ptr)[i])->getName())==name){
   		contain = true;
   	}
   	if((((*ptr)[i])->getAca()) == true){
   		if((((*ptr)[i])->getImproveCount())!=0){
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
void Building::b_refresh(){
 curplayer.clear();
}
Building ::~Building(){
}
