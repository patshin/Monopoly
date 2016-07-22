#ifndef _TEXDISPLAY_
#define _TEXDISPLAY_
#include <iostream>
#include <fstream>
#include <string>  
#include <vector>
#include <stdexcept>
#include <sstream>
#include "board.h"
#include "player.h"
#include "Building.h"


class Textdisplay
{
	std::vector<std::vector<char>> display;
	std::string stringDislay;
public:
	 Textdisplay();
	~Textdisplay();
	std::vector<int> PosToindex(int pos);
	//transfer the position to in board to the index in display which is the rightmost position in that sqaure 
	void putPlayer(char c, int pos);
	void movePlayer(int pos, char c, int steps);
    void removePlayer(char c, int pos);
    void setOwner(char c, int pos);
    void improve(int pos, bool whether);
    // make one improvement if whether is true
    // remove one improvemnt if whether is false
    void mortgage(int pos, bool whether);
    // mortgage if whether is true
    // unmortgage if whether is false
    friend std::ostream &operator<<(std::ostream &out, const Textdisplay &td);
};
#endif
