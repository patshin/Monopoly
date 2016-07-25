#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <map>
#include <vector>
class Building;
class Property;

class Player {
  std::string name;
  char nameChar;
  int balance;
  int pos;   //0-39
  int timeTim;
  int cupsOwn;
  bool isBankrupted; 
  bool roll;
  std::vector<Building*> buildings;
  std::vector<Player*> players;
  std::map<std::string, int> pList;
public:
  Player(std::string name,char nc, std::vector<Building*> &b, std::vector<Player*> &p);
  std::string getName();
  //get player character
  char getChar();
  //get player balance
  int getBalance();
  //get player position
  int getPos();
  //check if player can roll
  bool rollable();
  //check is bindex owned created a block
  bool isBlock(int bindex);
  //switch roll: T/F
  void changeRollable();
  //move player by step
  void move(int step);
  //move player to position p
  void gotoSite(int p);
  //buy property using money
  void purchase(std::string bname);
  //send property without getting paid
  void sendProperty(Player* p, int bpos);
  //receive property at bpos, without paying
  void addProperty(int bpos);
  //change player balance
  void changeBalance(int change);
  //set timeTim to 0 if n=0, increment if n=1
  void setTimTime(int n);
  //get timeTim
  int getTimTime();
  //get Rollup Cups owned
  int getCupsOwn();
  //add one to cups owned
  void receiveCup();
  //subtract one from cups owned
  void useCup();
  //net worth of player's properties
  int netCapital();
  //declare bankruptcy
  void bankrupt(); 
  //auction starts for building bname
  void auction(std::string bname, int bpos); 
  //print properties owned
  void printProperties();
  //property manipulations
  //s = mortgage, unmortgage, tradein, tradeout, improve, unimprove
  void prop_manip(int ppos, int changeMoney, std::string s);
  //check if bankrupted
  bool isBankrupt();
  //switch bankrupt status
  void makeBankrupt();
  //check if player can be bankrupted after balance is changed
  bool canBankrupt(int change); 
  //check if owns building p
  bool own(Building* p);
  //check if a building can trade
  bool canTrade(int bindex);
  //count for gyms or residences owned, b = gym or res
  int getNumOwn(std::string b);
  //set RollupCups owned
  void setCupsOwn(int cup);
  //set player balance
  void setBalance(int bal);
  //set player position
  void setPos(int p);
  //reset the player vector in a player
  void setPlayerList(std::vector<Player*> &pv);
  //remove a player from the player vector
  //void removePlayer(std::string n);
  ~Player();
};
#endif
