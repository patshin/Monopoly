#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "Property.h"

Property::Property(bool Academic,int price, std::string name, int site, BoardDisplay* board):Academic(Academic),price(price){
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
 notify();
}
void Property::removeOwner(){
 if(owner == nullptr){
 }else{
  delete(owner);
 }
 notify();
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

