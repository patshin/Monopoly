#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "GooseNesting.h"
using namespace std;
GooseNesting::GooseNesting(int site, Textdisplay* board)
 :NonProperty(false, "goose",site, board){
}

void GooseNesting::method(Player* p){
 cout<<"ATTACKED BY GOOSE!"<<endl;
}
