#ifndef _PLAYER_H_
#define _PLAYER_H_
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
  bool isBankrupt; //
  bool rollable;
  std::vector buildings;
  std::vector players;
  std::map<std::string, int> pList;
public:
  Player(char nc, vector &b, vector &p);
  std::string getName();
  char getChar();
  int getBalance();
  int getPos();
  bool rollable();
  void changeRollable();
  void move(int step);// setp/removep
  void goto(int p);
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
  void auction(string bname, int bpos); //gai, bid or quit
  void mortgage(Property* p);
  void printProperties();
  // cannot trade buildings with improvements
  // apply twice if trade building to building
  void prop_manip(int ppos, int changeMoney, string s); //s = mortgage, unmortgage, tradein, tradeout, improve, unimprove
  void isWinner();
  bool isBankrupt();
  void makeBankrupt();
  bool canBankrupt(int change); //if true, give warning, cannot 付租金
  bool own(Property* p);
  vector<Building*> *getBuildingList();
  int getNumOwn(string b);
  ~Player();
};
//improve, set status, get block, trade, win?
#endif
