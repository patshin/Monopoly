#ifndef __GYM_H__
#define __GYM_H__
#include "Property.h"

class Gym : public Property{
	public:
 Gym(std::string name,int site,Textdisplay* board);
 int getFee(int numOwn);
 int getValue() override;
 void method(Player *p);
 int getImproveCost() override;
 std::string getblock() override;
 ~Gym();
};
#endif
