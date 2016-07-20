#include "controller.h"
#include "board.h"
#include <fstream>
#include <iostream>
#include <stdexcept>
using namespace std;


Controller::Controller(Board &b, Textdisplay &td,int seed): board{b},td{td},playerindex{0},actionStage{0},NumOfPlayers{0},testingMode{false},seed{seed},trading{false}{} ///pass by reference???

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
    for (int n = 0; n < NumOfPlayers; n++){
    	cout << "Enter the letter your character represent (case sensitive):";
	    char c;
	    while(cin >> c){
	    	if(c != 'G' || c != 'B' || c != 'D' || c != 'P' || c != 'S' || c != '$' || c != 'L' || c != 'T'){
	    		cout << "Player Not found. Please enter a player character in the list:";
	    	}else break;
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
		board.switchStage();
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
