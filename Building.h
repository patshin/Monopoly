#ifndef   __BUILDING_H__
#define  __BUILDING_H__
#include <vector>
#include "Player.h"
#include "TextDisplay.h"
class Building {
 bool ownable;
 std::string name;
 int site;
 std::vector <Player*> curplayer;
 BoardDisplay* display;
	public:
 Building(bool ownable, std::string name, int site, TextDisplay* board);
 int getSite();
 std::string getName();
 bool tradable(Player *p);
 bool getOwn();
 void setPlayer(Player* p);
 void removePlayer(Player* p);
 int improvable();
}
#endif