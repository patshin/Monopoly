#ifndef _CONTROLLER_
#define _CONTROLLER_
#include "board.h"
#include "textdisplay.h"
#include "player.h"
#include <string>
#include <vector>

class Controller
{
	Board &board;//okay to use refernece?
	int playerindex;
	int NumOfPlayers;
	bool trading;
	bool testingMode;
        std::vector <char> characters;
public:
	Controller(Board &b, int seed);
	~Controller();
	void gamestart();
	//start the game by letting players choose their own characters
	// if not loaded from a file
	void roll(int dice1 = 0, int dice2 = 0);
	//roll the dice twice or input manually 
	void next();
	// notify board to move on to the next player
	void dropout();
	// notify board to notify the player bankrupt
	void asset();
	// notify board to print all the asset of the current player
	void all();
	// notify board to print all the asset of all players
	void save(std::string filename);
	// notify board to save the game to filename
	void load(std::ifstream &filename);
	// notify board to load the game from filename stream
	bool win();
	// notify board to return the game status
	void stuckAtTimline();
	// notify the board make no move since player is stuck at Tim Line
	bool playerstatus(); // inform the implemetation of player
	// notify the board to return the status(able to roll or not) of a the current play
    std::string getwinner();
    // notify board to return name of winner
	bool getMode();
	// return if the game is in testing mode
	void turnonTestingMode();
	// turn on the testing mode
//	void clearboard();
	bool is_atTimline();
	bool is_trading();
	void display();
	void trade();
	void improve();
	void mortgage(const bool &whether);
        bool rollStage();
        std::string playername();
        void clearboard();
};

#endif
