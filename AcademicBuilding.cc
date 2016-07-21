#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "AcademicBuilding.h"

AcademicBuilding::AcademicBuilding(int price, int improveCost, int tuition[],string lock,string name, int site, TextDisplay* board ):improveCost(improveCost), tuition[tuition],lock[lock]{
 Property(true,price,name,site,board);
}
int AcademicBuilding::getImproveCount(){
 return improveCount;
}
int AcademicBuilding::getImproveCost(){
 return improveCost;
}
int AcademicBuilding::getFee(){
 return tuition[improveCount];
}
int AcademicBuilding::getValue(){
 return (price+(improveCost*improveCount));
}
void AcademicBuilding::improve(){
 improveCount++;
 board->improve(getSite(),true);
}
void AcademicBuilding::setImproveCount(int n){
 improveCount = n;
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
 	cout << "This Building is empty, do you want to purchase it?"<<endl;
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
 	}else{
 		cout << "land on academic building, you need to pay"<<tuition[improveCount]<<endl;
 		p->changeBalance(tuition[improveCount]);
 	}
  }
 }
}