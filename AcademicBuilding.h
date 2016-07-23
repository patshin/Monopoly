#ifndef __ACADEMICBUILDING_H__
#define __ACADEMICBUILDING_H__
#include "Property.h"
#include <vector>

class AcademicBuilding : public Property{
 int improveCost;
 std::vector <int> tuition;
 std::string block;
public:
 AcademicBuilding(int price,int imc, std::vector <int> tut, std::string blk,std::string name, int site, Textdisplay* board);
 int getImproveCost();
 int getFee();
 int getValue();
 void improve();
 std::string getblock();
 void doublebase();
 void halfbase();
 void method(Player* p);
 
};	

#endif
