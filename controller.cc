#include "controller.h"
#include "board.h"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <vector>
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
        cin.exceptions(ios::eofbit|ios::failbit);
	cout << "enter the number of players:";
	string name;
        bool threw = false;
     do{
       try{ 
         cin >> NumOfPlayers;
         if(NumOfPlayers > 6 || NumOfPlayers < 2){
              throw 6;
           }
         threw = false;  
         }
    	catch(ios::failure&){
    		cout << "Please enter an interger:";
    		cin.clear();
    		cin.ignore();
               // cin >> NumOfPlayers;
              //  if(NumOfPlayers > 6){
               //   throw 6;
               // }
                threw = true;
                
    	}
        catch(int x){
    	        cout << "Maximum players 6, Minimum 2, try again:" ;
    	//	cin >> NumOfPlayers;
          //      if(NumOfPlayers > 6){
            //      throw 6;
              //  }
                threw = true;
         }
      }while(threw); 
      

    cout << "Choose your character from Goose(G), GRT Bus(B), Tim Hortons Doughnut(D), Professor(P), Student(S), Money($), Laptop(L), Pink tie(T)" << endl;
    int len = 8;
    bool found = false;
    for (int n = 0; n < NumOfPlayers; n++){
    	cout << "Enter the letter your character represent (case sensitive):";
	    char c;
	    while(cin >> c){
	    	for(int n = 0; n < len; n++){
	    		if(characters[n] == c){
//                               cout << characters[n] << endl;
	    			 characters.erase(characters.begin() + n);
  //                             cout << characters[n] << endl;
	    			found = true;
	    			len--;
	    			break;
	    		}
	    	}
	    	if(found){
	    		cout << "Enter your name:";
	    		cin >> name;
                        found = false;
	    		break;
	    	}
	    	cout << "Player Not found or chosen. Please enter a player character in the list: ";
	    	for (int j = 0; j < len; j++){
	    		cout << characters[j] << ' ';
	    	}
	    	cout << endl;
	    }   
//                cout << "player attached failed" << endl;
		board.attachplayers(name,c);//add to the board
  //              cout << "player attached." << endl;
	}
	for(int j = 0; j < NumOfPlayers; j++){
		board.sendvector(j);
	}
	characters.clear();
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
	srand(time(0));
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
              //          cout << "This is testing mode,enter the number of <dice1> <dice2>." << endl;
//                        try{
  //                       cin >> dice1 >> dice2;
    //                    }
      //                  catch(ios::failure&){
        //                 cout << "Invalid input. Try agian: " << endl;
          //               cin >> dice1 >> dice2;
            //            }
                        if(dice1 > 6 || dice2 > 6){
                          cout << "Dice number cannot be more than 6. moving 0 as a punishment." << endl;
                          dice1 = -1;
                          dice2 = 1;
                        }
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
                      //  cout << "start moving" << endl;
                        cout << "total moves" << dice1+dice2 << endl;
		    	board.moveplayer(dice1 + dice2);
		    }
		}
		if(board.playerStatus()){
			board.switchStage();
			
		}
	}else{
		cout << "You are not allowed to roll." << endl;
	}
}

void Controller::next(){
       if(board.playerbankrupt()){
         cout << "You don't have money to move on. Declare <bankrupt> to drop out or sell your property." << endl;
        }else{
        	if(playerstatus()){
	        	cout << "Please roll first." << endl;
        	}else{
                       board.switchStage();
                       board.nextplayer();
                       playerindex++;
        	}
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

//void Controller::clearboard(){
//	board.clear();
//}

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

void Controller::clearboard(){
        characters.push_back('G');
        characters.push_back('B');
        characters.push_back('D');
        characters.push_back('P');
        characters.push_back('S');
        characters.push_back('$');
        characters.push_back('L');
        characters.push_back('T');
        board.clear();
        playerindex = 0;
        NumOfPlayers = 0;
        testingMode = false; 
        trading = false;
}



