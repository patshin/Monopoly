#ifndef __PROPERTY_H__
#define __PROPERTY_H__
#include "Building.h"
class Property: public Building{
 bool Academic;
 Player* owner;
 int price;
 bool mortgaged;
	public:
 Property(bool Academic, int price,std::string name, int site, Textdisplay* board);
 bool getAca();
 Player* getOwner();
 void removeOwner();
 int getPrice();
 void changeMort();
 bool getMort();
 bool improvable();
 virtual void method(Player *p);
 virtual int getFee();
 virtual int getValue();
 int getImproveCount();
 void setOwner(Player *p);
 void setImprovements(int n);
 int getImproveCost();
 void refresh();
};
#endif
