#ifndef __COOPFEE_H__
#define __COOPFEE_H__
#include <map>
#include "NonProperty.h"
class CoopFee: public NonProperty{
	public:
CoopFee(int site, Textdisplay* board);
void method(Player* p);
~CoopFee();
};
#endif
