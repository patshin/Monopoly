#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "CollectOSAP.h"
using namespace std;
CollectOSAP::CollectOSAP(int site, Textdisplay* board):
 NonProperty(false, "OSAP", site, board){
}
void CollectOSAP::method(Player* p){
 cout << "You Have Collected $200 !"<< endl;
 p->changeBalance(200);
}
CollectOSAP::~CollectOSAP(){}
