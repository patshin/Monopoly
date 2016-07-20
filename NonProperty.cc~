#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "NonProperty.h"
using namespace std;

Nonproperty::NonProperty(bool ownable, string name, int site, BoardDisplay* board){
 Building(ownable,name,site,board);
 numRollup = 0;
}

int Nonproperty::getNumRoll(){
 return numRollup;
}

void Nonproperty::setNumRoll(int n){
 if(n == -1){
  numRollup = numRollup-1;
 }else{
  numRollup = n;
 }
}
