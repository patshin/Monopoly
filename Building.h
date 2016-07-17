#include <vector>
#include "Player.h"
#include "BoardDisplay.h"
#include "Board.h"
class Building {
 bool ownable;
 std::string name;
 int site;
 std::vector <Player*> curplayer;
 BoardDisplay* display;
 Board* board;
	public:
 Building(bool ownable, std::string name, int site, BoardDisplay* board);
 std::string getName();
 bool getOwn();
 void setPlayer(Player* p);
 void removePlayer(Player* p);
 void notify();//Notify display the change of current landing player(include function display->changeres(Building*))
}
