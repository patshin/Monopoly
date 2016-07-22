#include "controller.h"
#include "board.h"
#include <fstream>
#include <iostream>
#include <stdexcept>
using namespace std;


Controller::Controller(Board &b, Textdisplay &td,int seed): board{b},td{td},playerindex{0},actionStage{0},NumOfPlayers{0},testingMode{false},seed{seed},trading{false}{
	characters.push_back('G');
	characters.push_back('B');
	characters.push_back('D');
	characters.push_back('P');
	characters.push_back('S');
	characters.push_back('$');
	characters.push_back('L');
	characters.push_back('T');
} ///pass by reference???

Controller::~Controller(){} //need implemetations????????

void Controller::gamestart(){
	cout << "enter the number of players:";
    while(cin >> NumOfPlayers){
    	if(cin.fail()){
    		cout << "Please enter an interger:";
    		cin.clear();
    		cin.ignore();
    	}else{
    		if(NumOfPlayers > 6){
    			cout << "Maximum players 6, try again:" << endl;
    		}
    		if(NumOfPlayers <= 6) break;
    	}
    }
    cout << "Choose your character from Goose(G), GRT Bus(B), Tim Hortons Doughnut(D), Professor(P), Student(S), Money($), Laptop(L), Pink tie(T)" << endl;
    int len = 8;
    for (int n = 0; n < NumOfPlayers; n++){
    	cout << "Enter the letter your character represent (case sensitive):";
	    char c;
	    while(cin >> c){
	    	for(int n = 0; n < len; n++){
	    		bool found = false;
	    		if(characters[n] == c){
	    			characters.erase(characters.begin() + n);
	    			found = true;
	    			len--;
	    			break;
	    		}
	    	}
	    		if(found) break;
	    		cout << "Player Not found or chosen. Please enter a player character in the list: ";
	    		for (int j = 0; j < len; j++){
	    			cout << characters[j] << ' ';
	    		}
	    		cout << endl;
	    	}
		board.attachplayers(c);//add to the board
	}
}

void Controller::roll(int dice1, int dice2){
	if(c.playerstatus()){
		if(testingMode = false){
			srand(seed);
		    dice1 = rand()%6 + 1;
		    dice2 = rand()%6 + 1;
		    board.moveplayer(dice1+dice2); 
		    cout << "dice1: " << dice1 << endl;
		    cout << "dice2: " << dice2 << endl; 
		}else{
			board.moveplayer(dice1 + dice2);
			cout << "dice1: " << dice1 << endl;
		    cout << "dice2: " << dice2 << endl; 
		}
		//board.switchStage();
	}else{
		cout << "Fuck off! You are not allowed to roll." << end;
	}
}

void Controller::next(){
	if(c.playerstatus()){
		cout << "Please roll first." << endl;
	}else{
        board.nextplayer();
        playerindex++;
	}

}

void Controller::dropout(){
	board.playerBankrupt();
	NumOfPlayers--;

}

void Controller::asset(){
    board.printAsset();
}

void Controller::all(){
	board.printall();
}

void Controller::save(string filename){
	board.saveTo(filename);
}

void Controller::load(ifstream &filename){
	board.loadFrom(filename);
}

bool Controller::win(){
	return board.finish();
}

void Controller::stuckAtTimline(){
	board.stayAtTim();
}

bool Controller::playerstatus(){
	return board.playerStatus();
}

string Controller::getwinner(){
	return board.winner();
}

bool Controller::getMode(){
	return testingMode;
}

void Controller::turonTestingMode(){
	testingMode = true;
}

void Controller::clearboard(){
	board.clear();
}

bool Controller::is_atTimline(){
	return board.at_Tim();
}


bool Controller::is_tading(){
	return trading;
}

void Controller::display(){
	cout << td << endl; //cout or out?
}


void Controller::trade(){
	trading = true;
	board.trade();
}

void Controller::improve(){
	board.imporve();
}


void Controller::mortgage(const bool &whether){
	board.mortgage(whether);
}



