#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
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
