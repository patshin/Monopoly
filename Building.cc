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
 //cout << "Building::entering display" << endl;
 display->putPlayer(p->getChar(),site);
 //cout << "Building::finish displaying" << endl;
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



void Building::b_refresh(){
 curplayer.clear();
}
Building ::~Building(){
  curplayer.clear();
}
int Building::getImproveCost(){
 return 0;
}
bool Building::getAca(){
  return false;
}
int Building::getImproveCount(){
  return 0;
}
Player* Building::getOwner(){
  return nullptr;
}
void Building::setOwner(Player *p){

}
void Building::setImprovements(int n){

}
bool Building::getMort(){
  return false;
}
int Building::getPrice(){
  return 0;
}
void Building::method(Player *p){

}
void Building::changeMort(){

}
string Building::getblock(){
  return "";
}
int Building::getNumRoll(){
  return 0;
}
void Building::setNumRoll(int n){
  
}
void Building::removeOwner(){
 
}



