#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>
#include "controller.h"
#include "board.h"
#include "textdisplay.h"
using namespace std;

int main(int argc, const char * argv[]) {
  cin.exceptions(ios::eofbit|ios::failbit);
  string cmd;
  Board b;
  Textdisplay td;
  Controller con{b,td,0};
  if(argc > 4){
    cout << "Too many arguments. Loading failure." << endl;
  }


  if(argc == 4){

    if(argv[1] == "-load" || argv[2] == "-load"){

      if(argv[1] == "-load"){
        ifstream infile{argv[2]};
        try{
          con.load(infile);
        }
        catch(ios::failure&){
          cout << "Loading failure. Unknown file";
          exit;
        }
      }else{
        ifstream infile{argv[3]};
        try{
          con.load(infile);
        }
        catch(ios::failure&){
          cout << "Loading failure. Unknown file";
          exit;
        }
      }
    }else{
      cout << "Invalid arguments." << endl;
    }
    if(argv[1] == "-testing" || argv[3] == "-testing"){
      con.turnonTestingMode();
    }else{
      cout << "One invalid argument." << endl;
    }
  }

  if(argc == 3){
    if(argv[1] == "-load"){
      ifstream infile{argv[2]};
      try{
        con.load(infile);
      }
      catch(ios::failure&){
        cout << "Loading failure. Unknown file";
        exit;
      }
    }else{
      cout << "Invalid argument." << endl;
      exit;
    }
  }


  if(argc == 2){
    if(argv[1] == "-testing"){
      con.turnonTestingMode();
    }else{
      cout << "Invalid argument." << endl;
      exit;
    }
  }


  if(argc == 1 || argc > 4){
    con.gamestart();
  }

  while (true) {
    if(con.win()){
        cout << con.getwinner() << "is the winner" << endl;
        con.clearboard();
        cout << "Game over. Would you like to play again? Y/N";
        char c;
        while(cin >> c){
                if(c == 'N') {exit;}
            if(c == 'Y'){
                con.gamestart();
                break;
            }else{
                cout << "Command not found. Try agian:";
            }
        }
    }
    if(con.is_atTimline()){//see player.h
      con.stuckAtTimline();
    }else{
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
        con.display();
      }else if (cmd == "next") {
        con.next();
        con.display();
      }else if (cmd == "bankrupt") {
        con.dropout();
        con.display();
      }else if (cmd == "asset") {
        con.asset();
        con.display();
      }else if (cmd == "all"){
        con.all();
        con.display();
      }else if(cmd == "save"){
        string filename;
        cin >> filename;
        con.save(filename);
        cout << "Game saved. Would you like to end the game? Y/N";
        char c;
        cin >> c;
        if(c == 'Y') break;
      }else if(cmd == "trade"){
        con.trade();
        con.display();
      }else if(cmd == "improve"){
        con.improve();
        con.display();
      }else if(cmd == "mortgage"){
        con.mortgage(true);
        con.display();
      }else if(cmd == "unmortgage"){
        con.mortgage(false);
        con.display();
      }else{
        cout << cmd << " Command not found. Try again:" << endl;
      }
    }
  }
}


