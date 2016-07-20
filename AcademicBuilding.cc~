#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "AcademicBuilding.h"

AcademicBuilding::AcademicBuilding(int price, int improveCost, int tuition[],string lock,string name, int site, BoardDisplay* board ):improveCost(improveCost), tuition[tuition],lock[lock]{
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
 notify();
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
