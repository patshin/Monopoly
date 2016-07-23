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
  static bool gameEnd;
  bool isBankrupted; //
  bool roll;
  std::vector<Building*> buildings;
  std::vector<Player*> players;
  std::map<std::string, int> pList;
public:
  Player(std::string name,char nc, std::vector<Building> &b, std::vector<Player> &p);
  std::string getName();
  char getChar();
  int getBalance();
  int getPos();
  bool rollable();
  bool isBlock(int bindex);
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
  void bankrupt(); //delete p
  bool getGameStatus();
  void auction(std::string bname, int bpos); //gai, bid or quit
  void mortgage(Property* p);
  void printProperties();
  // cannot trade buildings with improvements
  // apply twice if trade building to building
  void prop_manip(int ppos, int changeMoney, std::string s); //s = mortgage, unmortgage, tradein, tradeout, improve, unimprove
  void isWinner();
  bool isBankrupt();
  void makeBankrupt();
  bool canBankrupt(int change); //if true, give warning, cannot 付租金
  bool own(Building* p);
  std::vector<Building*> *getBuildingList();
  //count for gyms or residences owned, b = gym or res
  int getNumOwn(std::string b);
  void setCupsOwn(int cup);
  void setBalance(int bal);
  void setPos(int p);
  ~Player();
};
//improve, set status, get block, trade, win?
#endif
