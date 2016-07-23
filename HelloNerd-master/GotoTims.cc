#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "GotoTims.h"
using namespace std;

GotoTims::GotoTims(int site, Textdisplay *board):
 NonProperty(false, "GotoTims", site, board){
}
void GotoTims::method(Player* p){
 p->gotoSite(10);
}
GotoTims::~GotoTims(){}