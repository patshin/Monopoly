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
 int getImproveCost() override;
 int getFee() override;
 int getValue() override;
 void improve() override;
 std::string getblock() override;
 void doublebase() override;
 void halfbase() override;
 void method(Player* p);
 ~AcademicBuilding();
};	

#endif
