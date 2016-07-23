#ifndef __GYM_H__
#define __GYM_H__
#include "Property.h"

class Gym : public Property{
	public:
 Gym(std::string name,int site,Textdisplay* board);
 int getFee(int numOwn);
 int getValue();
 void setNumOwn(int n);
 void method(Player *p);
 int getImproveCount();
 void setImprovements();
 int getImproveCost();
};
#endif
