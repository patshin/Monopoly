#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "Gym.h"

Gym::Gym(string name,int site, TextDisplay* board){
 Property(false,150,name,site,board);
 numOwn = 0; 
}_
int Gym::getFee(){
 srand(time(0));
 int a = (rand()%6)+1;
 int b = (rand()%6)+1;
 int sum = a+b;
 if(numOwn == 1){
  return 4*sum;
 }else {
  return 10*sum;
 }
}

int Gym::getValue(){
 return 150;
}
void Gym::setNumOwn(int n){
 numOwn = n;
}