
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
    cout << "You do not own and tim cups." << endl;
    cout << "Please try [dice] double or [pay] 50."<<endl;
   }else{
    cout << "tim cup used"<<endl;
    p->useCup();
    p->setTimTime(0);
    setNumRoll(1);
    return;
   }
  }else if(cmd == "dice"){
   if(roll == 1){
    cout << "You have already rolled, please try [pay] 50 or [use] the rim cup."<<endl;
   }else{
    srand(time(0));
    int a = (rand()%6) + 1;
    int b = (rand()%6) + 1;
    if(a == b){
     cout << "You have rolled double, now leaving the line."<<endl;
     p->setTimTime(0);
     return;
    }else{
     roll = 1;
     if(p->getTimTime() == 3){
      cout << "Dice failed, you MUST [pay] 50 or [use] the rim cup."<<endl;
     }else{
      cout <<"Dice failed, please try [pay] 50 or [use] the rim cup."<<endl;
     }
    }
   }
  }else if(cmd == "pay"){
   p->changeBalance(-50);
   p->setTimTime(0);
   return;
  }else if(cmd == "skip"){
   if(skip == 3){
    cout << "You can not skip, you MUST choose a method."<<endl;
   }else{
    cout << "Skipping this round, see you!"<<endl;
    if(p->rollable() == true){
     p->changeRollable();
    }
    break;
   }
  }
 }
}


