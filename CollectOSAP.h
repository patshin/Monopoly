#ifndef __COLLECTOSAP_H__
#define __COLLECTOSAP_H__
#include "NonProperty.h"
class CollectOSAP: public NonProperty{
	public:
CollectOSAP(int site, Textdisplay* board);
void method(Player* p);
~CollectOSAP();
};
#endif
