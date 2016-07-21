#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "Residence.h"

Residence::Residence(string name,int site, TextDisplay* board){
 Property(false, 200,name,site,board);
 numOwn = 0;
}
int Residence::getFee(int numOwn){
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
void Residence::method(Player *p){
 if(p->getOwner() == nullptr){
 	cout << "This residence is empty, do you want to purchase it?"<<endl;
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
 	int n = pyr->getNumOwn();
 	int fee = getFee(n);
 	cout << "land at res, you need to pay "<<fee <<endl;
 	p->changeBalance(-fee);
 	return;
 }
}
