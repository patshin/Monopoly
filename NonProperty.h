#include "Building.h"
class NonProperty: public Building{
 int numRollup;
	public:
 Nonpropertyy(bool ownable, string name, int site, BoardDisplay* board);
 int getNumRoll();
 void setNumRoll(int n);
 virtual void method(Player* p) = 0;
}
