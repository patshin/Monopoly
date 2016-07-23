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
 void setPlayer(Player* p);
 void removePlayer(Player* p);
 int improvable();
 virtual bool getAca() = 0;
 virtual int getImproveCount();
 virtual Player* getOwner() = 0;
 virtual void setOwner(Player *p) = 0;
 virtual void setImprovements(int n) = 0;
 virtual int getImprovCount();
 virtual bool getMort() =0;
 virtual int getPrice() ;
 virtual int getImproveCost();
 virtual void refresh() = 0;
 void b_refresh();
 virtual ~Building();
 virtual void method(Player *p) = 0;
 virtual void changeMort() = 0;
 virtual std::string getblock() ;
};
#endif
