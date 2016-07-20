#include <iostream>
#include <fstream>
#include <string>  
#include <vector>
#include <stdexcept>
#include <sstream>
#include "board.h"
#include "player.h"
#include "building.h"
#include "textdisplay.h"
using namespace std;


Board::Board(): NumPlayers{0},finish{false},currentplayer{0},winner{"No one"},players{{}}{
    Textdisplay td;
    Building *b1 = new NonProperty{false,"OSAP",0,td};
    building.push_back(b1);
    Building *b2 = new AcademicBuilding{true,"AL",1,td};
    building.push_back(b2);
    Building *b3 = new NonProperty{false,"SLC",2,td};
    building.push_back(b3);
    Building *b4 = new AcademicBuilding{true, "ML",3,td};
    building.push_back(b4);
    Building *b5 = new NonProperty{false,"TUITION",4,td};
    building.push_back(b5);
    Building *b6 = new Residence{true,"MKV",5,td};
    building.push_back(b6);
    Building *b7 = new AcademicBuilding{true,"ECH",6,td};
    building.push_back(b7);
    Building *b8 = new NonProperty{false,"NEEDLES HALL",7,td};
    building.push_back(b8);
    Building *b9 = new AcademicBuilding{false,"PAS",8,td};
    building.push_back(b9);
    Building *b10 = new AcademicBuilding{true,"HH",9,td};
    building.push_back(b10);
    Building *b11 = new AcademicBuilding{false,"DC Tims Line",10,td};
    building.push_back(b11);
    Building *b12 = new AcademicBuilding{true,"RCH",11,td};
    building.push_back(b12);
    Building *b13 = new AcademicBuilding{true,"PAC",12,td};
    building.push_back(b13);
    Building *b14 = new AcademicBuilding{true,"DWE",13,td};
    building.push_back(b14);
    Building *b15 = new AcademicBuilding{true,"CPH",14,td};
    building.push_back(b15);
    Building *b16 = new AcademicBuilding{true,"UWP",15,td};
    building.push_back(b16);
    Building *b17 = new AcademicBuilding{true,"LHI",16,td};
    building.push_back(b17);
    Building *b18 = new AcademicBuilding{false,"SLC",17,td};
    building.push_back(b18);
    Building *b19 = new AcademicBuilding{false,"BMH",18,td};
    building.push_back(b19);
    Building *b20 = new AcademicBuilding{false,"OPT",19,td};
    building.push_back(b20);
    Building *b21 = new AcademicBuilding{false,"Goose Nesting",20,td};
    building.push_back(b21);
    Building *b22 = new AcademicBuilding{false,"EV1",21,td};
    building.push_back(b22);
    Building *b23 = new AcademicBuilding{false,"NEEDLES HALL",22,td};
    building.push_back(b23);
    Building *b24 = new AcademicBuilding{false,"EV2",23,td};
    building.push_back(b24);
    Building *b25 = new AcademicBuilding{false,"EV3",24,td};
    building.push_back(b25);
    Building *b26 = new AcademicBuilding{false,"V1",25,td};
    building.push_back(b26);
    Building *b27 = new AcademicBuilding{false,"PHYS",26,td};
    building.push_back(b27);
    Building *b28 = new AcademicBuilding{false,"B1",27,td};
    building.push_back(b28);
    Building *b29 = new AcademicBuilding{false,"CIF",28,td};
    building.push_back(b29);
    Building *b30 = new AcademicBuilding{false,"B2",29,td};
    building.push_back(b30);
    Building *b31 = new AcademicBuilding{false,"GO TO TIMS",30,td};
    building.push_back(b31);
    Building *b32 = new AcademicBuilding{false,"EIT",31,td};
    building.push_back(b32);
    Building *b33 = new AcademicBuilding{false,"ESC",32,td};
    building.push_back(b33);
    Building *b34 = new AcademicBuilding{false,"SLC",33,td};
    building.push_back(b34);
    Building *b35 = new AcademicBuilding{false,"C2",34,td};
    building.push_back(b35);
    Building *b36 = new AcademicBuilding{false,"REV",35,td};
    building.push_back(b36);
    Building *b37 = new AcademicBuilding{false,"NEEDLES HALL",36,td};
    building.push_back(b37);
    Building *b38 = new AcademicBuilding{false,"MC",37,td};
    building.push_back(b38);
    Building *b39 = new AcademicBuilding{false,"COOP FEE",38,td};
    building.push_back(b39);
    Building *b40 = new AcademicBuilding{false,"DC",39,td};
    building.push_back(b40);////what else to put in except for the 40 

    this->td = &td;
}

Board::~Board(){
    for(int n = 0; n < NumPlayers; n++){
        delete players[n];
    }
    for(int j = 0; j < 40; j++){
        delete building[j];
    }
}

int Board::findbuilding(string name){
	for(int n=0; n < 40; n++){
		if(building[n]->getName() == name){
			return n;
		}
	}
	return 40;
}

void Board::attachplayers(char c){   
		Player *p = new Player{c, building, players}; 
        players.push_back(p);//contained its the player that has the vector, players always being modified??
        NumPlayers++;
}
void Board::moveplayer(int steps){
    players[currentplayer]->move(steps);
}

//void Board::switchStage(){
//    players[currentplayer]->switchstatus();//switch the status of a player who can roll or not?
//}
bool Board::playerStatus(){
    return players[currentplayer]->rollable();//return the status of a player who can roll or not
}
    
void Board::nextplayer(){
     if(currentplayer == NumPlayers - 1){
        currentplayer == 0;
     }else{
        currentplayer++;
     }
}

void Board::playerBankrupt(){
    players[currentplayer]->bankrupt();//what player actually does?
    NumPlayers--;
}

void Board::printAsset(){
    players[currentplayer]->printProperties();
}
void Board::saveTo(filename){
    ofstream savefile{filename};
    savefile << NumPlayers << endl;
    for(int n = 0; n < NumPlayers; n++){
    	if(players[n]->getPos() != 10){
    		savefile << players[n]->getName() << " " << players[n]->getChar() << " " << players[n]->getCupsOwn();
    		savefile << " " << players[n]->getBalance() << " " << players[n]->getPos() << endl;
    	}else{
    		if(players[n]->getTimTime() == 0){
    			savefile << players[n]->getName() << " " << players[n]->getChar() << " " << players[n]->getCupsOwn();
    		    savefile << " " << players[n]->getBalance() << " " << players[n]->getPos() << " 0" << endl;
    		}else{
    			savefile << players[n]->getName() << " " << players[n]->getChar() << " " << players[n]->getCupsOwn();
    		    savefile << " " << players[n]->getBalance() << " " << players[n]->getPos() << " " << players[n]->getTimTime() << endl;
    		}
    	}//balance or total money
    	for(int j = 0; j < 40; j++){
    		if(building[j]->getOwn()){
    			savefile << building[j]->getName() << " " << building[j]->getOwner(); //To get owner of the building;
                savefile << " " << building[j]->getImprovements() << endl; // To get number of improvements of the building
    		}
    	}
    	
    }
}

void Board::loadFrom(ifstream &filename){
	filename >> NumPlayers;
	for(int n = 0; n < NumPlayers; n++){
		string s;
		try{
			getline(filename,s);
		}
		catch(ios_failure&){
			if(filename.eof()) break;
			else{
				cout << "Loading Failed. Please check your file." << endl;
				exit;
			}
		}
		try{
			istringstream ss(s);
			char c;
			int a;
		    ss >> c;
		    this->attachplayers(c);
		    ss >> a;
		    players[n]->setCupsOwn(a); //set cups owned to a; can this method be protected??
		    ss >> a;
		    players[n]->setBalance(a); // set balance to a; can this method be protected;
		    ss >> a;
		    players[n]->setPos(a); // set position to a; can this method be protected;
		}
		catch(ios_failure&){
            cout << "Loading Failed. Please check your file." << endl;
            exit;
		}
	}
	while(true){
		string s;
		try{
			getline(filename,s);
		}
		catch(ios_failure&){
			if(filename.eof()) break;
			else{
				cout << "Loading Failed. Please check your file." << endl;
				exit;
			}
		}
		try{
		    istringstream ss(s);
		    string name;
		    string owner;
		    int improvements;
		    ss >> name;
		    int index = findbuilding(name);
		    ss >> owner;
		    building[index]->setOwner(owner); //set owner to owner; can this method be protected??
		    ss >> improvements;
		    building[index]->setImprovements(improvements); //set number of improvements to improvements; can this method be protected??
		}
		catch(ios_failure&){
			cout << "Loading Failed. Please check your file." << endl;
			exit;
		}
	}
}

bool Board::finish(){
    return NumPlayers == 1;
}

void Board::stayAtTim(){
    players[currentplayer]->move(0);
}

string Board::getwinner(){
    winner = players[0]->getName();
    return winner;
}

bool Board::at_Tim(){
    return players[currentplayer]->getTimTime() > 0;
}

void Board::clear(){
    NumPlayers = 0;
    finish = false;
    currentplayer = 0;
    winner = "No one";
    for(int n = 0; n < NumPlayers; n++){
        delete players[n];
    }
     for(int j = 0; j < 40; j++){
        building[j]->refresh(); //set all the buildings' fields to its initial value;
    }
}

void Board::trade(){
    string name;
    string give;
    string receive;
    int givemoney = -1;
    int receivemoney = -1;
    int receiveIndex;
    cout << "Name: ";
    while(cin >> name){
        bool in = false;
        for(int n = 0; n < NumPlayers; n++){
            if(players[n]->getName() == name){
                in = true;
                receiverIndex = n;
            }
            if(in) break;
        }
        if(in) break;
        cout << "Name not found. Try again:";
    }
    cout << endl << "Give: ";
    if(cin >> givemoney){
        give = "";
    }else{
        cin.clear();
        cin >> give;
    }
    cout << endl << "Receive: "
    if(cin >> receivemoney){
        receive = "";
    }else{
        cin.clear();
        cin >> receive;
    }
    if(give == "" && receive == ""){
        cout << "Money for money? Rejected." << endl;
    }else{
        int giveBuildingIndex = -1;
        int ReceiveBuildingIndex = -1;
        if(give != ""){
           giveBuildingIndex = findbuilding(give);
        }
        if(receive != ""){
            ReceiveBuildingIndex = findbuilding(receive);
        }
        if(giveBuildingIndex == 40 || ReceiveBuildingIndex == 40){
            cout << "Property not found. Request Rejected." << endl;
        }else if(!building[giveBuildingIndex]->tradable(players[currentplayer]){ // inform building to implement this. Including the case that it is not owned by the currentplayer.
            cout << give << " " << "cannot be traded. Request Rejected." << endl;
        }else if(!building[ReceiveBuildingIndex]->tradable(players[receiverIndex]){
            cout << receive << " " << "cannot be traded. Request Rejected." << endl;
        }else{
            string cmd;
            cout << "Please choose accept or reject this offer?" << end;
            while(cin >> cmd){
                
                if(cmd == "reject") break;
                if(cmd == "accept"){
                    players[currentplayer]->prop_manip(giveBuildingIndex, givemoney, "tradeout");//inform player this implementation involves givemoney = -1 to determine the situation
                    players[receiverIndex]->prop_manip(ReceiveBuildingIndex, receivemoney, "tradein");
                    break;
                }else{
                    cout << "command not found. Try agian: reject/accept."
                }
            }
        }
    }
}



void Board::improve(){
    int buildingIndex;
    string property;
    string transaction;
    cout << "Enter property name: ";
    while(cin >> property){
        buildingIndex = findbuilding(property);
        if(buildingIndex == 40){
            if(property == "quit") break;
            cout << "Property Not Found. If quit improving, enter quit. Or try again: ";
        }else if(players[currentplayer]->own(building[buildingIndex])){// inform player to implement this.
            cout << "You don't have this property. If quit improving, enter quit. Or try again: ";
        }else if(!building[buildingIndex]->isBlock()){
            cout << "Can't be improved without being monoploy. If quit improving, enter quit. Or try again: ";
        }else break;
    }
    cout << "Enter sell or buy:";
    while(cin >> transaction){
        if(transaction == "buy"){
             int improvements = building[buildingIndex]->getImproveCount();
             if(improvements >= 5){
                cout << "Maximent improvements. Cannot improve any more." << endl;
                break;
             }
             int improveCost = building[buildingIndex]->getImproveCost();
             cout << "This improvement costs " << improveCost << " dollars." << endl;
             players[currentplayer]->prop_manip(buildingIndex, improveCost, "improve");
        }else if(transaction == "sell"){
            int improvements = building[buildingIndex]->getImproveCount();
            if(improvements == 0){
                cout << "No improvements to sell" << endl;
                break;
            }
            int improveCost = (building[buildingIndex]->getImproveCost())/2;
            cout << "Selling this improvement is worth " << improveCost << " dollars." << endl;
            players[currentplayer]->prop_manip(buildingIndex, improveCost, "unimprove");//what if they can't afford it?? what happened when they short?
        }else{
            cout << "Illegal command." << endl;
        }
    }
}


void Board::mortgage(const bool &whether){
    int buildingIndex;
    string property;
    cout << "Enter property name: ";
    while(cin >> property){
        buildingIndex = findbuilding(property);
        if(buildingIndex == 40){
            if(property == "quit") break;
            cout << "Property Not Found. If quit mortgaging, enter quit. Or try again: ";
        }else if(players[currentplayer]->own(building[buildingIndex])){// inform player to implement this.
            cout << "You don't have this property. If quit mortgaging, enter quit. Or try again: ";
        }else if(building[buildingIndex]->getImproveCount() != 0){
            cout << "Improvements haven't been all sold. If quit mortgaging, enter quit. Or change another property: ";
        }else break;
    }
    if(whether){
        if(building[buildingIndex]->getMort()){
            cout << "Already mortgaged. Request Rejected.";
        }else{
            int get = (building[buildingIndex]->getPrice())/2;
            cout << "Morgaging this property is worth " << get << " dollars." << endl;
            players[currentplayer]->prop_manip(buildingIndex, get, "mortgage");
        }
    }else{
        if(!building[buildingIndex]->getMort()){
            cout << "Haven't bee mortgaged. You must be mistaken.";
        }else{
            int cost = (building[buildingIndex]->getPrice())*6/10;
            cout << "Unmorgaging this property costs " << get << " dollars." << endl;
            players[currentplayer]->prop_manip(buildingIndex, cost, "unmortgage");
        }
    }
}
