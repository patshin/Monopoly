#ifndef __NONPROPERTY_H__
#define __NONPROPERTY_H__
#include "Building.h"
class NonProperty: public Building{
 int numRollup;
	public:
 Nonproperty(bool ownable, string name, int site, Textdisplay* board);
 int getNumRoll();
 void setNumRoll(int n);
 virtual void method(Player* p) = 0;
};
