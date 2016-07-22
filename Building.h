#ifndef   __BUILDING_H__
#define  __BUILDING_H__
#include <vector>
#include "player.h"
#include "textdisplay.h"
class Building {
 bool ownable;
 std::string name;
 int site;
 std::vector <Player*> curplayer;
 Textdisplay* display;
	public:
 Building(bool ownable, std::string name, int site, Textdisplay* board);
 int getSite();
 Textdisplay *getBoard();
 std::string getName();
 bool tradable(Player *p);
 bool getOwn();
 void setPlayer(Player* p);
 void removePlayer(Player* p);
 int improvable();
};
#endif
