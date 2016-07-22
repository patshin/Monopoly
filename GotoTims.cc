#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "GotoTims.h"
using namespace std;

GotoTims::GotoTims(int site, TextDisplay *board){
 NonProperty(false, "GotoTims", site, board);
}
void TimsLine::method(Player* p){
 p->gotoSite(10);
}
