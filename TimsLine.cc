#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "TimsLine.h"
using namespace std;

TimsLine::TimsLine(int site,Textdisplay* board):
 NonProperty(false,"TimeLine",site,board){
}
void TimsLine::method(Player* p){
 p->setTimTime(1);
 cout << "You are stuck at the tim line, choose to [dice] double, [pay] 50 or [use] a tim cup, you can also [skip]" <<endl;
 cout <<"You now have "<< p->getCupsOwn() <<" tim cups."<<endl;
 string cmd;
 int roll = 0;
 int skip = p->getTimTime();
 while(cin>>cmd){
  if(cmd == "use"){
   if(p->getCupsOwn() == 0){
    cout << "You do not own and tim cups" << endl;
    cout << "please try [dice] double or [pay] 50"<<endl;
   }else{
    cout << "tim cup used"<<endl;
    p->useCup();
    p->setTimTime(0);
    setNumRoll(1);
    return;
   }
  }else if(cmd == "dice"){
   if(roll == 1){
    cout << "you have already rolled, please try [pay] 50 or [use] the rim cup"<<endl;
   }else{
    srand(time(0));
    int a = (rand()%6) + 1;
    int b = (rand()%6) + 1;
    if(a == b){
     cout << "you have rolled double, now leave the line"<<endl;
     p->setTimTime(0);
     return;
    }else{
     roll = 1;
     if(p->getTimTime() == 3){
      cout << "dice fail, you MUST [pay] 50 or [use] the rim cup"<<endl;
     }else{
      cout <<"dice fail, please try [pay] 50 or [use] the rim cup"<<endl;
     }
    }
   }
  }else if(cmd == "pay"){
   p->changeBalance(-50);
   p->setTimTime(0);
   return;
  }else if(cmd == "skip"){
   if(skip == 3){
    cout << "you can not skip, you MUST choose a method"<<endl;
   }else{
    cout << "skip this round, see you"<<endl;
    return;
   }
  }
 }
}
