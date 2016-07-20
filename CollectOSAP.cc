#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "CollectOSAP.h"
using namespace std;

void CollectOSAP::method(Player* p){
 cout << "You Have Collected $200 !"<< endl;
 p->changeBalance(200);
}
