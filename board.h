#ifndef _BOARD_
#define _BOARD_
#include "Building.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
class Textdisplay;
class Player;

class Board{
        int NumPlayers;
        int currentplayer;
        std::string winner;
        std::vector <Player*> players;///share ptr??
        std::vector <Building*> building;//share ptr??
        Textdisplay td;
public:
        Board(Textdisplay &td,std::vector <Player *> &p);
        ~Board();
        void attachplayers(std::string name,char c);
    void moveplayer(int steps);
    void switchStage();
    //notify the current player to switch status(being able to roll or not)
    bool playerStatus();
    // notify the current player to return status(being able to roll or not)
    void nextplayer();
    int findbuilding(std::string name);
    int findplayer(std::string name);
    void playerBankrupt();
    void printAsset();
    void printall();
    void saveTo(std::string filename);
    void loadFrom(std::ifstream &filename);
    bool finish();
    void stayAtTim();
    // notify the current player to make no move this round and impelment the Tims Line again
    std::string getwinner();
    bool at_Tim();
    void clear();
    void trade();
    void playerGotoTim();
    void improve();
    void display();
    void mortgage(const bool &whether);
    std::string playername();
};



#endif
