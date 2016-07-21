#ifndef __RESIDENCE_H__
#define __RESIDENCE_H__
#include "Property.h"

class Residence : public Property{
 int numOwn;
	public:
 Residence(std::string name,int site, TextDisplay* board);
 int getFee();
 int getValue();
 void setNumOwn(int n);
}
#endif