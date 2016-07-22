#ifndef __NEEDLESHALL_H__
#define __NEEDLESHALL_H__
#include <map>
#include "NonProperty.h"
class NeedlesHall: public NonProperty{
	public:
NeedlesHall(int site, Textdisplay* board);
void method(Player* p);
}
#endif
