#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "Gym.h"

Gym::Gym(string name,int site, TextDisplay* board){
 Property(false,150,name,site,board);
}

int Gym::getFee(int numOwn){
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
void Gym::method(Player *p){
 if(getOwner() == nullptr){
 	cout << "This gym is empty, do you want to purchase it?"<<endl;
 	cout << "[Y/N]" << endl;
 
 string s;
 while(cin>>s){
 	if(s == "Y"){
 		cout << "you have pruchased this property!"<<endl;
 		p->purchase(getName());
 		return;
 	}else if(s =="N"){
 		p->auction(getName(),getSite());
 		return;
 	}else{}
  }
 }else{
 	Player *pyr = getOwner();
 	int n = pyr->getNumOwn("gym");
 	int fee = getFee(n);
 	cout << "land at gym, you need to pay "<<fee <<endl;
 	p->changeBalance(-fee);
 	return;
 }
}