#ifndef __PROPERTY_H__
#define __PROPERTY_H__
#include "Building.h"
class Property: public Building{
 bool Academic;
 Player* owner;
 int price;
 bool mortgaged;
	public:
 Property(bool Academic, int price,std::string name, int site, TextDisplay* board);
 Player* getOwner();
 void setOwner(Player* p);
 void removeOwner();
 int getPrice();
 void changeMort();
 bool getMort();
 virtual int getFee();
 virtual int getValue();
}
#endif

