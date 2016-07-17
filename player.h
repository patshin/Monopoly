#ifndef _PLAYER_H_
#define _PLAYER_H_
class Building;
class Property;

class Player {
  std::string name;
  char nameChar;
  int balance;
  int pos;
  int timeTim;
  int cupsOwn;
  bool gameEnd;
  std::vector buildings;
  std::vector players;
  std::map<std::string, int> pList;
public:  //roll, trade, finish
  Player(char nc, vector &b, vector &p){};
  std::string getName();
  char getChar();
  int getBalance();
  int getPos();
  void move(int step);// setp/removep
  void goto(int p);
  void purchase(std::string bname);
  void sell(std::string bname);
  void changeBalance(int change);
  int setTimTime(int n);//0 1
  int getTimTime();
  int getCupsOwn();
  void receiveCup();
  void useCup();
  void bankrupt();
  bool getGameStatus();
  void auction(string bname, int bpos);
  void mortgage(Property* p);
  void notify();
  ~Player();
};
//improve, set status, get block, trade, win?
#endif
