#ifndef __GYM_H__
#define __GYM_H__
#include "Property.h"

class Gym : public Property{
	public:
 Gym(std::string name,int site,Textdisplay* board);
 int getFee(int numOwn);
 int getValue();
 void method(Player *p);
 int getImproveCost();
 std::string getblock();
 ~Gym();
};
#endif
