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
 Textdisplay *getBoard(); //return the current display
 std::string getName(); 
 bool tradable(Player *p); //return true if it is tradable
 bool getOwn(); //return true if it is property
 void setPlayer(Player* p);
 void removePlayer(Player* p);
 virtual bool getAca() = 0; //return true if it is academic building
 virtual int getImproveCount(); 
 virtual Player* getOwner() = 0; 
 virtual void setOwner(Player *p) = 0;
 virtual void setImprovements(int n);
 virtual bool getMort() =0; //return true if it is already mortgaged
 virtual int getPrice() ;
 virtual int getImproveCost();
 virtual void refresh() = 0; // return to original state
 void b_refresh();
 virtual ~Building();
 virtual void method(Player *p) = 0;
 virtual void changeMort(); //swap mortgage status
 virtual std::string getblock(); //return the block it is located
 virtual int getNumRoll();
 virtual void setNumRoll(int n);
 
};
#endif
