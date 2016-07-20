#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "Property.h"

Property::Property(bool Academic,int price, std::string name, int site, TextDisplay* board):Academic(Academic),price(price){
 Building(true,name,site,board);
 owner = nullptr;
 mortgaged = false; 
}
Player* Property::getOwner(){
 return owner;
}
void Property::setOwner(Player* p){
 if(owner == nullptr){
  owner = p;
 }else{
  removeOwner();
  owner = p;
 }
 board->setOwner(p->getChar(),getSite());
}
void Property::removeOwner(){
 if(owner == nullptr){
 }else{
  delete(owner);
 }
 board->removeOwner(p->getChar(),getSite);
}
int Property::getPrice(){
 return price;
}
void Property::changeMort(){
 mortgaged = !mortgaged;
}
bool Property::getMort(){
 return mortgaged;
}
bool Property::improvable(){
if (Academic)
{
	if(getImproveCount() == 5){
	 return false;
	}else{
     return true;
	}
}else{
  return false;
 }
}

