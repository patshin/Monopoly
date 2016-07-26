#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "SLC.h"
using namespace std;
SLC::SLC(int site, Textdisplay* board):
 NonProperty(false,"SLC",site,board){
}

void SLC::method(Player* p){
 int n = getNumRoll();
 if(n == 0){
 }else{
  srand(time(0));
  int x = rand()%100+1;
  if(x == 1){
   cout << "Congrats! You've received a Tim Cup!" << endl;
   setNumRoll(n-1);
   p->receiveCup();
  }
 }
 srand(time(0));
 int position;
 int y = rand()%24+1;
 if(y>=1&&y<=3){
  p->move(-3);
 }else if(y>=4&&y<=7){
  p->move(-2);
 }else if(y>=8&&y<=11){
  p->move(-1);
 }else if(y>=12&&y<=14){
  p->move(1);
 }else if(y>=15&&y<=18){
  p->move(2);
 }else if(y>=19&&y<=22){
  p->move(3);
 }else if(y == 23){
  position = p->getPos();
  p->gotoSite(10);
 }else{
  position = p->getPos();
  p->move(30 - position);
 }
}








