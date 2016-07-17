#include <iostream>
#include <string>
#include <fstream>
#include "controller.h"
#include "board.h"
#include "display.h"
using namespace std;

int main(int argc, const char * argv[]) {
  cin.exceptions(ios::eofbit|ios::failbit);
  string cmd;
  Board b;
  Textdisplay td;
  Controller c{&b,&td,0};
  if(arg > 4){
    cout << "Too many arguments, program terminated." << endl;
    exit;
  }


  if(argc == 4){

    if(arg[1] == "-load" || arg[2] == "-load"){

      if(arg[1] == "-load"){
        ifstream infile{arg[2]};
        try{
          c.load(infile);
        }
        catch(ios::failure&){
          cout << "Loading failure. Unknown file";
          exit;
        }
      }else{
        ifstream infile{arg[3]};
        try{
          c.load(infile);
        }
        catch(ios::failure&){
          cout << "Loading failure. Unknown file";
          exit;
        }
      }
    }else{
      cout << "Invalid arguments." << endl;
    }
    if(arg[1] == "-testing" || arg[3] == "-testing"){
      c.turnonTestingMode();
    }else{
      cout << "One invalid argument." << endl;
    }
  }

  if(argc == 3){
    if(argv[1] == "-load"){
      ifstream infile{arg[2]};
      try{
        c.load(infile);
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
      c.turnonTestingMode();
    }else{
      cout << "Invalid argument." << endl;
      exit;
    }
  }


  if(argc == 1){
    c.gamestart();
  }

  while (true) {
    if(c.win()){
      cout << c.getwinner() << "is the winner" << endl;
      if(c.win()) break;
    }
    if(c.playerstatus() == stuck){
      c.stuckAtTimline();
    }else{
      try{
        cin >> cmd;
      }
      catch(ios::failure&){}
      if (cmd == "roll") {
        if(c.getMode()){
          int n1;
          int n2;
          cin >> n1 >> n2;
          c.roll(n1,n2);
        }else{
          c.roll();
        }
        c.display();
      }else if (cmd == "next") {
        c.next();
        c.display();
      }else if (cmd == "bankrupt") {
        c.dropout();
        c.display();
        c.auction();
      }else if (cmd == "asset") {
        c.asset();
      }else if (cmd == "all"){
        c.all();
      }else if(cmd == "save"){
        string filename;
        cin >> filename;
        c.save(string filename);
        c.display();
        cout << "Game saved. Would you like to end the game? Y/N"
        char c;
        cin >> c;
        if(c = 'Y') break;
      }
    }
  }
}

 

