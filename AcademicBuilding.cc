#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "AcademicBuilding.h"
using namespace std;

AcademicBuilding::AcademicBuilding(int price, int imc, vector <int> tut,string blk,string name, int site, Textdisplay* board ) 
:Property(true,price,name,site,board){
 this->improveCost=imc;
 this->tuition=tut;
 this->block=blk;
}
int AcademicBuilding::getImproveCost(){
 return improveCost;
}
int AcademicBuilding::getFee(){
 return tuition[getImproveCount()];
}
int AcademicBuilding::getValue(){
 return (getPrice()+(improveCost*getImproveCount()));
}
void AcademicBuilding::improve(){
 setImprovements(getImproveCount() + 1);
 getBoard()->improve(getSite(),true);
}
string AcademicBuilding::getblock(){
 return block;
}
void AcademicBuilding::doublebase(){
 tuition[0] = tuition[0]*2;
}
void AcademicBuilding::halfbase(){
 tuition[0] = tuition[0]/2;
}
void AcademicBuilding::method(Player *p){
	if(getOwner() == nullptr){
 	cout << "This building is empty, do you want to purchase it?"<<endl;
 	cout << "[Y/N]" << endl;
 string s;
 while(cin>>s){
 	if(s == "Y"){
 		cout<<"You have purchased this property!"<<endl;
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
  cout << "Landing on an academic building, you need to pay "<<tuition[getImproveCount()];
  cout << " dollar." << endl;
  p->changeBalance(-tuition[getImproveCount()]);
  (getOwner())->changeBalance(tuition[getImproveCount()]);
 }
}

AcademicBuilding::~AcademicBuilding(){
	tuition.clear();
}
