#include "board.h"
#include "textdisplay.h"
#include "player.h"
#include <string>





class Controller
{
	Board *board;
	Textdisplay *td;
	int seed;
	int playerindex;
	int NumOfPlayers;
	bool testingMode;
public:
	Controller();
	~Controller();
	void gamestart();
	void roll(int dice1 = 0, int dice2 = 0);
	void next();
	void dropout();
	void asset();
	void all();
	void save(string filename);
	void load(string filename);
	bool win();
	void stuckAtTimline();
	bool playerstatus(); // inform the implemetation of player
    std::string getwinner();
	void getMode();
	void turonTestingMode();
	void display();
};
