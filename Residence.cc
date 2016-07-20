#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "Residence.h"

int Residence::getFee(){
 if(numOwn == 1){
  return 25;
 }else if(numOwn == 2){
  return 50;
 }else if(numOwn == 3){
  return 100;
 }else{
  return 200;
 }
}

int Residence::getValue(){
 return 200;
}
void Residence::setNumOwn(int n){
 numOwn = n;
}
