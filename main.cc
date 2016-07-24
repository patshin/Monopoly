#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>
#include "controller.h"
#include "board.h"
#include "player.h"
#include "textdisplay.h"
#include <stdlib.h>
using namespace std;

int main(int argc, const char * argv[]) {
  cin.exceptions(ios::eofbit|ios::failbit);
  string cmd;
  vector <Player*> players;
  Textdisplay td;
  Board b{td,players};
  Controller con{b,0};
  if(argc > 4){
    cout << "Too many arguments. Loading failure." << endl;
  }


  if(argc == 4){
    string arg1 = argv[1];
    string arg2 = argv[2];
    string arg3 = argv[3];
    if(arg1 == "-load" || arg2 == "-load"){

      if(arg1 == "-load"){
        ifstream infile{arg2};
        try{
          con.load(infile);
        }
        catch(ios::failure&){
          cout << "Loading failure. Unknown file";
          exit(EXIT_FAILURE);
        }
      }else{
        ifstream infile{arg3};
        try{
          con.load(infile);
        }
        catch(ios::failure&){
          cout << "Loading failure. Unknown file";
          exit(EXIT_FAILURE);
        }
      }
    }else{
      cout << "Invalid arguments." << endl;
    }
    if(arg1 == "-testing" || arg3 == "-testing"){
      con.turnonTestingMode();
    }else{
      cout << "One invalid argument." << endl;
    }
  }

  if(argc == 3){
//   cout << "2 arguments" << endl;
   string arg1 = argv[1];
   string arg2 = argv[2];
    if(arg1 == "-load"){
  //    cout << "start" << endl;
      ifstream infile{arg2};
      try{
        con.load(infile);
      }
      catch(ios::failure&){
        cout << "Loading failure. Unknown file";
        exit(EXIT_FAILURE);
      }
    }else{
      cout << "Invalid argument." << endl;
      exit(EXIT_FAILURE);
    }
  }


  if(argc == 2){
    string arg1 = argv[1];
    if(arg1 == "-testing"){
      con.turnonTestingMode();
    }else{
      cout << "Invalid argument." << endl;
      exit(EXIT_FAILURE);
    }
  }


  if(argc == 1 || argc > 4){
    cout << "Welcome to the game." << endl;
    con.gamestart();
  }

  while (true) {
//    cout << "in the loop" << endl;
    if(con.win()){
  //      cout << "win!!" << endl;
        cout << con.getwinner() << "is the winner" << endl;
        con.clearboard();
        cout << "Game over. Would you like to play again? Y/N";
        char c;
        while(cin >> c){
                if(c == 'N') {exit(EXIT_SUCCESS);}
            if(c == 'Y'){
                con.gamestart();
                break;
            }else{
                cout << "Command not found. Try agian:";
            }
        }
    }
    if(con.rollStage()){
       cout << "It's "<< con.playername() << "'s turn to play" << endl;
       cout << "Choose of the commands: roll|trade <name> <give> <receieve>|improve <property> buy/sell|mortgage <property>|unmortgage <property>|bankrupt|asset|all|save <filename>" << endl; 
     }else{
        cout << "You finished rolling." << endl;
        cout << "Choose of the commands: next|trade <name> <give> <receieve>|improve <property> buy/sell|mortgage <property>|unmortgage <property>|bankrupt|asset|all|save <filename>" << endl;
     }
      try{
        cin >> cmd;
      }
      catch(ios::failure&){}
      if (cmd == "roll") {
        if(con.getMode()){
          int n1;
          int n2;
          cin >> n1 >> n2;
          con.roll(n1,n2);
        }else{
          con.roll();
        }
//        con.display();
      }else if (cmd == "next") {
        con.next();
  //      con.display();
      }else if (cmd == "bankrupt") {
        con.dropout();
    //    con.display();
      }else if (cmd == "asset") {
        con.asset();
      //  con.display();
      }else if (cmd == "all"){
        con.all();
     //   con.display();
      }else if(cmd == "save"){
        string filename;
        cin >> filename;
        con.save(filename);
        cout << "Game saved. Would you like to end the game? Y/N" << endl;
        string s;
        cin >> s;
        if(s == "Y") {exit(EXIT_SUCCESS);}
      }else if(cmd == "trade"){
        con.trade();
     //   con.display();
      }else if(cmd == "improve"){
        con.improve();
    //    con.display();
      }else if(cmd == "mortgage"){
        con.mortgage(true);
     //   con.display();
      }else if(cmd == "unmortgage"){
        con.mortgage(false);
       // con.display();
      }else{
        cout << cmd << " Command not found. Try again:" << endl;
      }
  }
}
