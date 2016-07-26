#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "CoopFee.h"
using namespace std;

CoopFee::CoopFee(int site, Textdisplay* board):
 NonProperty(false, "Coop", site, board){
}
void CoopFee::method(Player* p){
 cout << "Once you choose to coop, you pay 150" << endl;
 p->changeBalance(-150);
}
CoopFee::~CoopFee(){}





