#ifndef __TUITION_H__
#define __TUITION_H__
#include <map>
#include "NonProperty.h"
class Tuition: public NonProperty{
	public:
Tuition(int site,Textdisplay*board);
void method(Player* p);
}
#endif
