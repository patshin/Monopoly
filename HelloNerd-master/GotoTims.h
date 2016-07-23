#ifndef __GOTOTIMS_H__
#define __GOTOTIMS_H__
#include <map>
#include "NonProperty.h"
class GotoTims: public NonProperty{
	public:
GotoTims(int site, Textdisplay* board);
void method(Player* p);
~GotoTims();
};
#endif

