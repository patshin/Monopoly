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
