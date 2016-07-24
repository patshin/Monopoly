#include <iostream>
#include <fstream>
#include <string>  
#include <vector>
#include <stdexcept>
#include <sstream>
#include "textdisplay.h"
using namespace std;


Textdisplay::Textdisplay(){ //56
     stringDisplay = "-----------------------------------------------------------------------------------------";
    stringDisplay += "|Goose  |       |NEEDLES|       |       |V1     |       |       |CIF    |       |GO TO  |";
    stringDisplay += "|NESTING|-------|HALL   |-------|-------|       |-------|-------|       |-------|TIMS   |";
    stringDisplay += "|       |EV1    |       |EV2    |EV3    |       |PHYS   |B1     |       |B2     |       |";
    stringDisplay += "|       |       |       |       |       |       |       |       |       |       |       |";
    stringDisplay += "|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|";
    stringDisplay += "|       |                                                                       |       |";
    stringDisplay += "|-------|                                                                       |-------|";
    stringDisplay += "|OPT    |                                                                       |EIT    |";
    stringDisplay += "|       |                                                                       |       |";
    stringDisplay += "|_______|                                                                       |_______|";
    stringDisplay += "|       |                                                                       |       |";
    stringDisplay += "|-------|                                                                       |-------|";
    stringDisplay += "|BMH    |                                                                       |ESC    |";
    stringDisplay += "|       |                                                                       |       |";
    stringDisplay += "|_______|                                                                       |_______|";
    stringDisplay += "|SLC    |                                                                       |SLC    |";
    stringDisplay += "|       |                                                                       |       |";
    stringDisplay += "|       |                                                                       |       |";
    stringDisplay += "|       |                                                                       |       |";
    stringDisplay += "|_______|                                                                       |_______|";
    stringDisplay += "|       |                                                                       |       |";
    stringDisplay += "|-------|                                                                       |-------|";
    stringDisplay += "|LHI    |                                                                       |C2     |";
    stringDisplay += "|       |        __________________________________________________             |       |";
    stringDisplay += "|_______|        |                                                |             |_______|";
    stringDisplay += "|UWP    |        | #   #  ##  #####  ###   ###   ###   #    #   # |             |REV    |";
    stringDisplay += "|       |        | #   # #  #   #   #   #  #  # #   #  #    #   # |             |       |";
    stringDisplay += "|       |        | # # # ####   #   #   #  ###  #   #  #     # #  |             |       |";
    stringDisplay += "|       |        | # # # #  #   #   #   #  #    #   #  #      #   |             |       |";
    stringDisplay += "|_______|        | ##### #  #   #    ###   #     ###   ## #   #   |             |_______|";
    stringDisplay += "|       |        |________________________________________________|             |NEEDLES|";
    stringDisplay += "|-------|                                                                       |HALL   |";
    stringDisplay += "|CPH    |                                                                       |       |";
    stringDisplay += "|       |                                                                       |       |";
    stringDisplay += "|_______|                                                                       |_______|";
    stringDisplay += "|       |                                                                       |       |";
    stringDisplay += "|-------|                                                                       |-------|";
    stringDisplay += "|DWE    |                                                                       |MC     |";
    stringDisplay += "|       |                                                                       |       |";
    stringDisplay += "|_______|                                                                       |_______|";
    stringDisplay += "|PAC    |                                                                       |COOP   |";
    stringDisplay += "|       |                                                                       |FEE    |";
    stringDisplay += "|       |                                                                       |       |";
    stringDisplay += "|       |                                                                       |       |";
    stringDisplay += "|_______|                                                                       |_______|";
    stringDisplay += "|       |                                                                       |       |";
    stringDisplay += "|-------|                                                                       |-------|";
    stringDisplay += "|RCH    |                                                                       |DC     |";
    stringDisplay += "|       |                                                                       |       |";
    stringDisplay += "|_______|_______________________________________________________________________|_______|";
    stringDisplay += "|DC Tims|       |       |NEEDLES|       |MKV    |TUITION|       |SLC    |       |COLLECT|";
    stringDisplay += "|Line   |-------|-------|HALL   |-------|       |       |-------|       |-------|OSAP   |";
    stringDisplay += "|       |HH     |PAS    |       |ECH    |       |       |ML     |       |AL     |       |";
    stringDisplay += "|       |       |       |       |       |       |       |       |       |       |       |";
    stringDisplay += "|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|";//89
    istringstream ss(stringDisplay);
    int x =0;
    for(int n = 0; n < 56; n++){
        vector <char> v;
        display.push_back(v);
    	for(int j = 0; j < 89; j++){
    		display[n].push_back(stringDisplay[x]);
                cout << display[n][j];
//                cout << "pushback works!!" << endl;
                x++;
    	}
        cout << endl;
    }
}
	
Textdisplay::~Textdisplay(){}
vector <int> Textdisplay::PosToindex(int pos){
	int row;
	int col;
	if(pos >= 0 && pos <= 10){
		col = 81 - pos*8;
		row = 54;
	}else if(pos >= 11 && pos <= 19){
		row = 54 - (pos - 10)*5;
		col = 1;
	}else if(pos >= 20 && pos <= 30){
		row = 4;
		col = (pos - 20) * 8 + 1;
	}else if(pos >= 21 && pos <= 39){
		col = 81;
		row = (pos - 20) * 5 + 4;
	}
	vector<int> v;
	v.push_back(row);
	v.push_back(col);
	return v;
}

void Textdisplay::putPlayer(char c, int pos){
	cout << c << " is at position " << pos <<endl;
	vector<int> v = PosToindex(pos);
	int row = v[0];
	int col = v[1]; 
	for(int i=0; i < 6; i++){
		if(display[row][col] != ' '){
			col++;
		}else break;
	}
	cout << "col is "<<col <<" row is "<<row <<endl;
	cout << display[row][col] << "v" << endl;
	display[row][col] = c;
        cout << display[row][col] << "v" << endl;
        cout << (*this);
//        cout << "finish displaying" << endl;
}
//	void movePlayer(int pos, char c, int steps);
 void Textdisplay::removePlayer(char c, int pos){
 	vector<int> v = PosToindex(pos);
 	int row = v[0];
	int col = v[1];
 	for(int n = 0; n < 6; n++){
 		if(display[row][col+n] == c){
 			display[row][col+n] = ' ';
 			break;
 		}
 	}
         cout << (*this);
 }
 void Textdisplay::setOwner(char c, int pos){
 	vector<int> v = PosToindex(pos);
 	int row = v[0] + 1;
	int col = v[1];
	display[row][col] = c;
        cout << (*this);
 }
 
void Textdisplay::removeOwner(int pos){
 	vector<int> v = PosToindex(pos);
 	int row = v[0] + 1;
	int col = v[1];
	display[row][col] = '_';
        cout << (*this);
 }
void Textdisplay::improve(int pos, bool whether){
	if(whether){
		vector<int> v = PosToindex(pos);
 	    int row = v[0] - 3;
	    int col = v[1];
	    for(int i=0; i < 6; i++){
	    	if(display[row][col] != ' '){
	    		col++;
	    	}else break;
	    	display[row][col] = 'I';
	    }
	}else{
		vector<int> v = PosToindex(pos);
 	    int row = v[0] - 3;
	    int col = v[1];
	    for(int i=0; i < 6; i++){
	    	if(display[row][col] != ' '){
	    		col++;
	    	}else break;
	    	display[row][col-1] = ' ';
	    }
	}
         cout << (*this);
}
void Textdisplay::mortgage(int pos, bool whether){
	if(whether){
		vector<int> v = PosToindex(pos);
 	    int row = v[0] - 1;
	    int col = v[1] + 2;
	    display[row][col] = 'M';
	}else{
		vector<int> v = PosToindex(pos);
 	    int row = v[0] - 1;
	    int col = v[1] + 2;
	    display[row][col] = '_';
	}
         cout << (*this);
}

ostream &operator<<(ostream &out, const Textdisplay &td) {
	for(int j = 0; j < 56; j++){
		for(int i=0; i < 89; i++){
			out << td.display[j][i]; //at right?
		}
		out << endl;
	}
	return out;
} 
