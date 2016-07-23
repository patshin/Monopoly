#ifndef __NONPROPERTY_H__
#define __NONPROPERTY_H__
#include "Building.h"
class NonProperty: public Building{
 int numRollup;
	public:
 NonProperty(bool ownable, std::string name, int site, Textdisplay* board);
 int getNumRoll();
 void setNumRoll(int n);
 virtual void method(Player* p) = 0;
 Player *getOwner();
 int getImproveCount();
 bool getAca() ;
 void setOwner(Player *p) ;
 void setImprovements(int n);
 bool getMort();
 int getPrice();
 int getImproveCost();
 void refresh();
 void changeMort();
};
#endif
