#include <iostream>
#include <fstream>
#include <string>  
#include <vector>
#include <stdexcept>
#include <sstream>
#include <stdlib.h>
#include "board.h"
#include "player.h"
#include "Building.h"
#include "CollectOSAP.h"
#include "AcademicBuilding.h"
#include "SLC.h"
#include "NeedlesHall.h"
#include "TimsLine.h"
#include "Residence.h"
#include "Gym.h"
#include "GotoTims.h"
#include "CoopFee.h"
#include "Tuition.h"
#include "GooseNesting.h"
#include "textdisplay.h"
using namespace std;


Board::Board(Textdisplay &td,vector <Player*> &p): NumPlayers{0},td{td},currentplayer{0},winner{"No one"},players{p}{
    Building *b1 = new CollectOSAP{0,&td};
    building.push_back(b1);
    Building *b2 = new AcademicBuilding{40,50,{2,10,30,90,160,250},"Art1","AL",1,&td};
    building.push_back(b2);
    Building *b3 = new SLC{2,&td};
    building.push_back(b3);
    Building *b4 = new AcademicBuilding{60,50,{4,20,60,180,320,450},"Art1", "ML",3,&td};
    building.push_back(b4);
    Building *b5 = new Tuition{4,&td};
    building.push_back(b5);
    Building *b6 = new Residence{"MKV",5,&td};
    building.push_back(b6);
    Building *b7 = new AcademicBuilding{100,50,{6,30,90,270,400,550},"Art2","ECH",6,&td};
    building.push_back(b7);
    Building *b8 = new NeedlesHall{7,&td};
    building.push_back(b8);
    Building *b9 = new AcademicBuilding{100,50,{6,30,90,270,400,550},"Art2","PAS",8,&td};
    building.push_back(b9);
    Building *b10 = new AcademicBuilding{120,50,{8,40,100,300,450,600},"Art2","HH",9,&td};
    building.push_back(b10);
    Building *b11 = new TimsLine{10,&td};
    building.push_back(b11);
    Building *b12 = new AcademicBuilding{140,100,{10,50,150,450,625,750},"Eng","RCH",11,&td};
    building.push_back(b12);
    Building *b13 = new Gym{"PAC",12,&td};
    building.push_back(b13);
    Building *b14 = new AcademicBuilding{140,100,{10,50,150,450,625,750},"Eng","DWE",13,&td};
    building.push_back(b14);
    Building *b15 = new AcademicBuilding{160,100,{12,60,180,500,700,900},"Eng","CPH",14,&td};
    building.push_back(b15);
    Building *b16 = new Residence{"UWP",15,&td};
    building.push_back(b16);
    Building *b17 = new AcademicBuilding{180,100,{14,70,200,550,750,950},"Health","LHI",16,&td};
    building.push_back(b17);
    Building *b18 = new SLC{17,&td};
    building.push_back(b18);
    Building *b19 = new AcademicBuilding{180,100,{14,70,200,550,750,950},"Health","BMH",18,&td};
    building.push_back(b19);
    Building *b20 = new AcademicBuilding{200,100,{16,80,220,600,800,1000},"Health","OPT",19,&td};
    building.push_back(b20);
    Building *b21 = new GooseNesting{20,&td};
    building.push_back(b21);
    Building *b22 = new AcademicBuilding{220,150,{18,90,250,700,875,1050},"Env","EV1",21,&td};
    building.push_back(b22);
    Building *b23 = new NeedlesHall{22,&td};
    building.push_back(b23);
    Building *b24 = new AcademicBuilding{220,150,{18,90,250,700,875,1050},"Env","EV2",23,&td};
    building.push_back(b24);
    Building *b25 = new AcademicBuilding{240,150,{20,100,300,750,925,1100},"Env","EV3",24,&td};
    building.push_back(b25);
    Building *b26 = new Residence{"V1",25,&td};
    building.push_back(b26);
    Building *b27 = new AcademicBuilding{260,150,{22,110,330,800,975,1150},"Sci1","PHYS",26,&td};
    building.push_back(b27);
    Building *b28 = new AcademicBuilding{260,150,{22,110,330,800,975,1150},"Sci1","B1",27,&td};
    building.push_back(b28);
    Building *b29 = new Gym{"CIF",28,&td};
    building.push_back(b29);
    Building *b30 = new AcademicBuilding{280,150,{24,120,360,850,1025,1200},"Sci1","B2",29,&td};
    building.push_back(b30);
    Building *b31 = new GotoTims{30,&td};
    building.push_back(b31);
    Building *b32 = new AcademicBuilding{300,200,{26,130,390,900,1100,1275},"Sci2","EIT",31,&td};
    building.push_back(b32);
    Building *b33 = new AcademicBuilding{300,200,{26,130,390,900,1100,1275},"Sci2","ESC",32,&td};
    building.push_back(b33);
    Building *b34 = new SLC{33,&td};
    building.push_back(b34);
    Building *b35 = new AcademicBuilding{320,200,{28,150,450,1000,1200,1400},"Sci2","C2",34,&td};
    building.push_back(b35);
    Building *b36 = new Residence{"REV",35,&td};
    building.push_back(b36);
    Building *b37 = new NeedlesHall{36,&td};
    building.push_back(b37);
    Building *b38 = new AcademicBuilding{350,200,{35,175,500,1100,1300,1500},"Math","MC",37,&td};
    building.push_back(b38);
    Building *b39 = new CoopFee{38,&td};
    building.push_back(b39);
    Building *b40 = new AcademicBuilding{400,200,{50,200,600,1400,1700,2000},"Math","DC",39,&td};
    building.push_back(b40);////what else to put in except for the 40 

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
	for(int n = 0; n < 40; n++){
		if(building[n]->getName() == name){
			return n;
		}
	}
	return 40;
}


int Board::findplayer(string name){
        for(int n=0; n < NumPlayers; n++){
                if(players[n]->getName() == name){
                        return n;
                }
        }
        return NumPlayers;
}


void Board::attachplayers(string name,char c){   
		Player *p = new Player{name,c, building, players}; //add a field!!
        players.push_back(p);//contained its the player that has the vector, players always being modified??
        cout << "player pointer" << players[NumPlayers] << endl;
        NumPlayers++;
}
void Board::moveplayer(int steps){
    cout << "start moving in board" << endl;
    players[currentplayer]->move(steps);
}

void Board::switchStage(){
    players[currentplayer]->changeRollable();//switch the status of a player who can roll or not?
}
bool Board::playerStatus(){
    return players[currentplayer]->rollable();//return the status of a player who can roll or not
}
    
void Board::nextplayer(){
     if(currentplayer == NumPlayers - 1){
        currentplayer = 0;
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

void Board::printall(){
     for(int n = 0; n < NumPlayers; n++){
         players[n]->printProperties();
     }
}


void Board::saveTo(string filename){
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
    	}
    	
    }//balance or total money
    	for(int j = 0; j < 40; j++){
    		if(building[j]->getOwn()){
    			if(building[j]->getOwner()){
    				savefile << building[j]->getName() << " " << building[j]->getOwner()->getName(); //To get owner of the building;
    				if(building[j]->getMort()){
    					savefile << " -1"  << endl; 
                                }else{
                                        savefile << " " << building[j]->getImproveCount() << endl; // To get number of improvements of the building
                                }
                        }else{
                                savefile << building[j]->getName() << " " << "BANK"; //To get owner of the building;
                                savefile << " " << building[j]->getImproveCount() << endl; // To get number of improvements of the building
                        }
    		}
    	}
    	
}


void Board::loadFrom(ifstream &filename){
	filename >> NumPlayers;
        string name;
        char c;
        int a;
	for(int n = 0; n < NumPlayers; n++){
		string s;
		try{
			getline(filename,s);
		}
		catch(ios::failure&){
			if(filename.eof()) break;
			else{
				cout << "Loading Failed. Please check your file." << endl;
				exit(EXIT_FAILURE);
			}
		}
                istringstream ss(s);
		try{
                    ss >> name;
		    ss >> c;
		    this->attachplayers(name,c);
		    ss >> a;
		    players[n]->setCupsOwn(a); //set cups owned to a; can this method be protected??
		    ss >> a;
		    players[n]->setBalance(a); // set balance to a; can this method be protected;
		    ss >> a;
		    players[n]->setPos(a); // set position to a; can this method be protected;
		}
		catch(ios::failure&){
            cout << "Loading Failed. Please check your file." << endl;
            exit(EXIT_FAILURE);
		}
        if(a == 10){
            ss >> a;
            if(a == 1){
                ss >> a;
                if(a == 2){
                    players[currentplayer]->setTimTime(1);
                    players[currentplayer]->setTimTime(1);
                    players[currentplayer]->setTimTime(1);
                }else if(a == 1){
                     players[currentplayer]->setTimTime(1);
                     players[currentplayer]->setTimTime(1);
                }else{
                    players[currentplayer]->setTimTime(1);;
                }
            }
        }
	}
	while(true){
		string s;
		try{
			getline(filename,s);
		}
		catch(ios::failure&){
			if(filename.eof()) break;
			else{
				cout << "Loading Failed. Please check your file." << endl;
				exit(EXIT_FAILURE);
			}
		}
                istringstream ss(s);
		try{
		    string name;
		    string owner;
		    int improvements;
		    ss >> name;
		    int index = findbuilding(name);
		    ss >> owner;
            if(owner != "BANK"){
                int playerindex = findplayer(owner);
                building[index]->setOwner(players[playerindex]);
            } //set owner to owner; can this method be protected??
		    ss >> improvements;
		    if(improvements == 0){
		    	if(building[index]->getAca()){
		    		building[index]->setImprovements(improvements);
		    	}
		    }else if(improvements == -1){
		    	building[index]->changeMort();
		    }else{
		        building[index]->setImprovements(improvements); //set number of improvements to improvements; can this method be protected??
		    }
		}
		catch(ios::failure&){
			cout << "Loading Failed. Please check your file." << endl;
			exit(EXIT_FAILURE);
		}
	}
}

bool Board::finish(){
    cout << "calling board finish??" << endl;
    cout << "NumPlayers: " << NumPlayers << endl; 
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
    cout << "calling board at_Time" << endl;
    cout << players[currentplayer]->getName() << endl;
    return players[currentplayer]->getTimTime() > 0;
}

void Board::playerGotoTim(){
    players[currentplayer]->gotoSite(10);
}

void Board::clear(){
    NumPlayers = 0;
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
    int receiverIndex;
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
    cout << endl << "Receive: ";
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
        }else if(!building[giveBuildingIndex]->tradable(players[currentplayer])){ // inform building to implement this. Including the case that it is not owned by the currentplayer.
            cout << give << " " << "cannot be traded. Request Rejected." << endl;
        }else if(!building[ReceiveBuildingIndex]->tradable(players[receiverIndex])){
            cout << receive << " " << "cannot be traded. Request Rejected." << endl;
        }else{
            string cmd;
            cout << "Please choose accept or reject this offer?" << endl;
            while(cin >> cmd){                
                if(cmd == "reject") break;
                if(cmd == "accept"){
                    players[currentplayer]->prop_manip(giveBuildingIndex, givemoney, "tradeout");
                    players[currentplayer]->prop_manip(ReceiveBuildingIndex, receivemoney, "tradein");
                    players[receiverIndex]->prop_manip(giveBuildingIndex, givemoney, "tradein");
                    players[receiverIndex]->prop_manip(ReceiveBuildingIndex, receivemoney, "tradeout");
                    break;
                }else{
                    cout << "command not found. Try agian: reject/accept.";
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
        }else if(building[buildingIndex]->getOwn() && players[currentplayer]->own(building[buildingIndex])){// inform player to implement this.
            cout << "You don't have this property. If quit improving, enter quit. Or try again: ";
        }else if(!players[currentplayer]->isBlock(buildingIndex)){//inform building to implement this;
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

void Board::display(){
	cout<<td<<endl;
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
            cout << "Unmorgaging this property costs " << cost << " dollars." << endl;
            players[currentplayer]->prop_manip(buildingIndex, cost, "unmortgage");
        }
    }
}
