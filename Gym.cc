#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "Gym.h"
using namespace std;
Gym::Gym(string name,int site, Textdisplay* board):
 Property(false,150,name,site,board){
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
 		cout << "You have pruchased this property!"<<endl;
 		p->purchase(getName());
 		return;
 	}else if(s =="N"){
 		p->auction(getName(),getSite());
 		return;
 	}else{}
  }
 }else{
	 if(getOwner()->getChar() == p->getChar()){
   return;
  }      
	 if(getMort() == true){
          cout << "Lucky! this property is mortgaged"<<endl;
        }
 	Player *pyr = getOwner();
 	int n = pyr->getNumOwn("gym");
 	int fee = getFee(n);
 	cout << "Landing at gym, you need to pay: "<<fee <<endl;
 	p->changeBalance(-fee);
	pyr->changeBalance(fee);
 	return;
 }
}
int Gym::getImproveCost(){
 return 0;
}
string Gym::getblock(){
 return "";
}
Gym::~Gym(){}
