#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "Property.h"
using namespace std;
Property::Property(bool Academic,int price, std::string name, int site, Textdisplay* board):
 Building(true,name,site,board),Academic(Academic),price(price){
 owner = nullptr;
 mortgaged = false; 
 improvements = 0;
}
Player* Property::getOwner(){
 return owner;
}
bool Property::getAca(){
  return Academic;
}
void Property::setOwner(Player* p){
 if(owner == nullptr){
  owner = p;
 }else{
  removeOwner();
  owner = p;
 }
 getBoard()->setOwner(p->getChar(),getSite());
 p->addProperty(getSite());
}
void Property::removeOwner(){
 if(owner == nullptr){
 }else{
  delete(owner);
 }
 getBoard()->removeOwner(getSite());
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
void Property::refresh(){
 b_refresh();
 removeOwner();
 setImprovements(0);
}
void Property::setImprovements(int n){
 improvements = n;
}
int Property::getImproveCount(){
 return improvements;
}
 int Property::getNumRoll(){
 	return 0;
 }
 void Property::setNumRoll(int n){
 }
Property::~Property(){}
int Property::getFee(){
 return 0;
}
string Property::getblock(){
 return "";
}
void Property::method(Player *p){

}
int Property::getImproveCost(){
 return 0;
}
int Property::getValue(){
 return 0;
}
