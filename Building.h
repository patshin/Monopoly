#ifndef   __BUILDING_H__
#define  __BUILDING_H__
#include <vector>
#include "player.h"
#include "textdisplay.h"
class Board;
class Building {
 bool ownable;
 std::string name;
 int site;
 std::vector <Player*> curplayer;
 Textdisplay* display;
	public:
 Building(bool ownable,std::string name,int site,Textdisplay* display);
 int getSite();
 Textdisplay *getBoard();
 std::string getName();
 bool tradable(Player *p);
 bool getOwn();
 virtual Player* getOwner() = 0;
 void setPlayer(Player* p);
 void removePlayer(Player* p);
 int improvable();
 virtual bool getAca() = 0;
 virtual int getImproveCount();
};
#endif
