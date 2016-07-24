#include "controller.h"
#include "board.h"
#include <fstream>
#include <iostream>
#include <stdexcept>
using namespace std;


Controller::Controller(Board &b,int seed): board{b},playerindex{0},NumOfPlayers{0},testingMode{false},trading{false}{
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
	string name;
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
    bool found = false;
    for (int n = 0; n < NumOfPlayers; n++){
    	cout << "Enter the letter your character represent (case sensitive):";
	    char c;
	    while(cin >> c){
	    	for(int n = 0; n < len; n++){
	    		if(characters[n] == c){
	    			characters.erase(characters.begin() + n);
	    			found = true;
	    			len--;
	    			break;
	    		}
	    	}
	    	if(found){
	    		cout << "Enter your name:";
	    		cin >> name;
	    		break;
	    	}
	    	cout << "Player Not found or chosen. Please enter a player character in the list: ";
	    	for (int j = 0; j < len; j++){
	    		cout << characters[j] << ' ';
	    	}
	    	cout << endl;
	    }   
                cout << "player attached failed" << endl;
		board.attachplayers(name,c);//add to the board
                cout << "player attached." << endl;
	}
}
bool Controller::rollStage(){
    return board.playerStatus();
}
string Controller::playername(){
    return board.playername();
}

void Controller::roll(int dice1, int dice2){
	int turn = 0;
	string roll;
	if(playerstatus()){
		if(!testingMode){
		    dice1 = rand()%6 + 1;
		    dice2 = rand()%6 + 1;
		    while(dice1 == dice2 && turn < 3){
		    	cout << "dice1: " << dice1 << endl;
		        cout << "dice2: " << dice2 << endl; 
		    	cout << "A double, roll again:" << endl;
		    	cin >> roll;
		    	while(roll != "roll"){
		    		cout << "You have to roll!!!!!! Try again" << endl;
		    		cin >> roll;
		    	}
		    	dice1 = rand()%6 + 1;
		        dice2 = rand()%6 + 1;
		        turn++;
		    }
		    if(turn == 3){
		    	cout << "dice1: " << dice1 << endl;
		        cout << "dice2: " << dice2 << endl; 
		    	cout << "Poor thing. Go to Timline lol." << endl;
		    	board.playerGotoTim();
		    }else{
		    	cout << "dice1: " << dice1 << endl;
		        cout << "dice2: " << dice2 << endl; 
		    	board.moveplayer(dice1+dice2); 
		        
		    }
		}else{
			while(dice1 == dice2 && turn < 3){ ////consider the case where dice1 and 2 greater than 6!!
		    	cout << "dice1: " << dice1 << endl;
		        cout << "dice2: " << dice2 << endl; 
		    	cout << "A double, roll again:" << endl;
		    	cin >> roll;
		    	cin >> dice1;
		    	cin >> dice2;
		    	while(roll != "roll" || cin.fail()){
		    		cout << "You have to roll correctly!!!!!! Try again" << endl;
		    		if(cin.fail()){
		    			cin.clear();
		    			cin.ignore();
		    		}
		    		cin >> roll;
		    		cin >> dice1;
		    		cin >> dice2;
		    	}
		    	turn++;
		    }
		    if(turn == 3){
		        cout << "dice1: " << dice1 << endl;
		        cout << "dice2: " << dice2 << endl; 
		    	cout << "Poor thing. Go to Timline lol." << endl;
		    	board.playerGotoTim();
		    }else{
		        cout << "dice1: " << dice1 << endl;
		    	cout << "dice2: " << dice2 << endl;
                        cout << "start moving" << endl; 
		    	board.moveplayer(dice1 + dice2);
			}
		}
		board.switchStage();
	}else{
		cout << "Fuck off! You are not allowed to roll." << endl;
	}
}

void Controller::next(){
	if(playerstatus()){
		cout << "Please roll first." << endl;
	}else{
        board.switchStage();
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
//        cout << "Calling win??" << endl;
	return board.finish();
}

void Controller::stuckAtTimline(){
	board.stayAtTim();
}

bool Controller::playerstatus(){
	return board.playerStatus();
}

string Controller::getwinner(){
	return board.getwinner();
}

bool Controller::getMode(){
	return testingMode;
}

void Controller::turnonTestingMode(){
	testingMode = true;
}

void Controller::clearboard(){
	board.clear();
}

bool Controller::is_atTimline(){
	return board.at_Tim();
}


bool Controller::is_trading(){
	return trading;
}

void Controller::display(){
	board.display(); //cout or out?
}


void Controller::trade(){
	trading = true;
	board.trade();
}

void Controller::improve(){
	board.improve();
}


void Controller::mortgage(const bool &whether){
	board.mortgage(whether);
}
