#ifndef __RESIDENCE_H__
#define __RESIDENCE_H__
#include "Property.h"

class Residence : public Property{
	public:
 Residence(std::string name,int site, Textdisplay* board);
 int getFee(int numOwn);
 int getValue();
 void method(Player *p);
 int getImproveCost();
 std::string getblock();
};
#endif

