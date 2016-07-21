#ifndef __GYM_H__
#define __GYM_H__
#include "Property.h"

class Gym : public Property{
 int numOwn;
	public:
 Gym(std::string name,int site,TextDisplay* board);
 int getFee();
 int getValue();
 void setNumOwn(int n);
}
#endif