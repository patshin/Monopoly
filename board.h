#ifndef _BOARD_
#define _BOARD_
#include "player.h"
#include "Building.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Board{
	int NumPlayers;
	int currentplayer;
	std::string winner; 
	std::vector <Player*> players;///share ptr??
	std::vector <Building*> buildings;//share ptr??
	Textdisplay *td;
public:
	Board();
	~Board();
	void attachplayers(char c);
    void moveplayer(int steps);
    void switchStage();
    //notify the current player to switch status(being able to roll or not)
    bool playerStatus();
    // notify the current player to return status(being able to roll or not)
    void nextplayer();
    void playerBankrupt();
    void printAsset();
    void saveTo(std::string filename);
    void loadFrom(std::ifstream &filename);
    bool finish();
    void stayAtTim();
    // notify the current player to make no move this round and impelment the Tims Line again
    std::string getwinner();
    bool at_Tim();
    void clear();
    void trade();
    void improve();
    void mortgage(const bool &whether);
};



#endif

