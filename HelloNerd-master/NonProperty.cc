#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "NonProperty.h"
using namespace std;

NonProperty::NonProperty(bool ownable, string name, int site, Textdisplay* board):
 Building(ownable,name,site,board){
 numRollup = 0;
}

int NonProperty::getNumRoll(){
 return numRollup;
}

void NonProperty::setNumRoll(int n){
 if(n == -1){
  numRollup = numRollup-1;
 }else{
  numRollup = n;
 }
}
Player* NonProperty:: getOwner(){
	return nullptr;
}
int NonProperty::getImproveCount(){
	return 0;
}
bool NonProperty::getAca() {
	return false;
}
void NonProperty::setOwner(Player *p) {

}
void NonProperty::setImprovements(int n){
	
}
bool NonProperty::getMort(){
 return false;
}
int NonProperty::getPrice(){
 return 0;

}
void NonProperty::refresh(){
 b_refresh();
 numRollup = 4;
}
void NonProperty::changeMort(){}

string NonProperty::getblock(){
	return "";
}
NonProperty::~NonProperty(){}

int NonProperty::getImproveCost(){
 return 0;
}
