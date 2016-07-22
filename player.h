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
  Player(char nc, std::vector<Building> &b, std::vector<Player> &p);
  std::string getName();
  char getChar();
  int getBalance();
  int getPos();
  bool rollable();
  void changeRollable();
  void move(int step);// setp/removep
  void gotoSite(int p);
  void purchase(std::string bname);
  void sendProperty(Player* p, Building* b); //newly added
  void addProperty(int bpos);
  void setBlock(int bpos);
  void changeBalance(int change);//give warning if bankrupt
  int setTimTime(int n);//0 1
  int getTimTime();
  int getCupsOwn();
  void receiveCup();
  void useCup();
  int netCapital();
  void bankrupt();
  void auction(std::string bname, int bpos);
  void mortgage(Property* p);
  void printProperties();
  //s = mortgage, unmortgage, tradein, tradeout, improve, unimprove
  void prop_manip(int ppos, int changeMoney, std::string s);
  bool isBankrupt();
  void makeBankrupt();
  bool canBankrupt(int change);
  bool own(Property* p);
  std::vector<Building*> *getBuildingList();
  int getNumOwn(std::string b);
  ~Player();
};
#endif
