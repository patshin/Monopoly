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
		col = 30;//81 - pos*8;
		row = 30;//54;
	}else if(pos >= 11 && pos <= 19){
		row = 30;//54 - (pos - 10)*5;
		col = 30;//1;
	}else if(pos >= 20 && pos <= 30){
		col = 30;//4;
		row = 30;//(pos - 20) * 8 + 1;
	}else if(pos >= 21 && pos <= 39){
		row = 30;//81;
		col = 30;//(pos - 20) * 5 + 4;
	}
	vector<int> v;
	v.push_back(row);
	v.push_back(col);
	return v;
}

void Textdisplay::putPlayer(char c, int pos){
	cout <<pos<< "is position"<<endl;
	vector<int> v = PosToindex(pos);
	int col = v[0];
	int row = v[1]; 
	for(int i=0; i < 6; i++){
		if(display[col][row] != ' '){
			col++;
		}else break;
	}
	cout << "col is "<<col <<"row is "<<row <<endl;
	cout <<"30 30 is  "<<display[30][30]<<endl;
	display[30][30] = c;
}
//	void movePlayer(int pos, char c, int steps);
 void Textdisplay::removePlayer(char c, int pos){
 	vector<int> v = PosToindex(pos);
 	int row = v[1];
	int col = v[2];
 	for(int n = 0; n < 6; n++){
 		if(display[col+n][row] == 'c'){
 			display[col+n][row] = ' ';
 			break;
 		}
 	}
 }
 void Textdisplay::setOwner(char c, int pos){
 	vector<int> v = PosToindex(pos);
 	int row = v[1] + 1;
	int col = v[2];
	display[col][row] = c;
 }
 
void Textdisplay::removeOwner(int pos){
 	vector<int> v = PosToindex(pos);
 	int row = v[1] + 1;
	int col = v[2];
	display[col][row] = '_';
 }
void Textdisplay::improve(int pos, bool whether){
	if(whether){
		vector<int> v = PosToindex(pos);
 	    int row = v[1] - 3;
	    int col = v[2];
	    for(int i=0; i < 6; i++){
	    	if(display[col][row] != ' '){
	    		col++;
	    	}else break;
	    	display[col][row] = 'I';
	    }
	}else{
		vector<int> v = PosToindex(pos);
 	    int row = v[1] - 3;
	    int col = v[2];
	    for(int i=0; i < 6; i++){
	    	if(display[col][row] != ' '){
	    		col++;
	    	}else break;
	    	display[col-1][row] = ' ';
	    }
	}
}
void Textdisplay::mortgage(int pos, bool whether){
	if(whether){
		vector<int> v = PosToindex(pos);
 	    int row = v[1] - 1;
	    int col = v[2] + 2;
	    display[col][row] = 'M';
	}else{
		vector<int> v = PosToindex(pos);
 	    int row = v[1] - 1;
	    int col = v[2] + 2;
	    display[col][row] = '_';
	}
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
