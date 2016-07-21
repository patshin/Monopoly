#include "player.h"
#include "Building.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

Player::Player(std::string name, char nc, vector &b, vector &p):
  name{name},nameChar{nc},buildings{b},players{p},pos{
    pos = rand() % 40;
    balance = 500;
    cupsOwn = 0;
    gameEnd = false;
    isBankrupt = false;
    rollable = false;
}

string Player::getName(){
  return name;
}

char Player::getChar(){
  return nameChar;
}

int Player::getBalance(){
  return balance;
}

int Player::getPos(){
  return pos;
}

bool Player::rollable(){
  return rollable;
}

void Player::changeRollable(){
  if(rollable == true) {
    rollable = false;
  }else{
    rollable = true;
  }
}

void Player::move(int step){
  (buildings.at(pos))->removePlayer(players.at(pos));
  if (step >= 0) {
    if(pos+step<=39){
      pos += step;
    }else{
      pos = pos+step-39;
    }
    (buildings.at(pos))->setPlayer();
  } else {
    if(pos+step<=0){
      pos = 39+pos-step;
    }else{
      pos += step;
    }
}

void Player::goto(int p){
  buildings[pos]->removePlayer(players.at(pos));
  pos = p;
  buildings[pos]->setPlayer();
  buildings[pos]->method(&);
}

void Player::purchase(string bname){
  pList[bname]=pos;
  (buildings.at(pos))->setOwner(this);
  int pay = 0 - (buildings.at(pos))->getPrice();
  if(canBankrupt(change)) {
    cout << "Warning! You don't have enough money!" << endl;
    return;
  }
  this->changeBalance(pay);
}

void Player::sendProperty(Player* p, int bpos){
  //setBlock(bpos);
  string bname = buildings[bpos]->getName();
  if(this->own(buildings[bpos])){
    pList.erase(bname);
  }
  buildings[bpos]->setOwner(p);
  //add building to player p
  p->addProperty(bpos);
}

void Player::addProperty(int bpos){

  pList[buildings[bpos]->getName()] = bpos;
}

bool Player::isBlock(int bindex){
  string blockname = buildings[bindex]->getblock();
  for (buildings::iterator it = buildings.begin() ; it != buildings.end(); ++it){
    if(it->getOwn()){
      if(it->getAca()){
        if(blockname == it->getblock()){
          if((it->getOwner())->getName() != name){
            return false;
          }
        }
      }
    }
  }
  return true;
}

void Player::changeBalance(int change){
    if(canBankrupt(change)) {
      cout << "Warning! You don't have enough money!" << endl;
      return;
    } else {
    balance += change;
  }
}

int Player::setTimTime(int n) {
  if (n==1){
    ++timeTim;
  } else {
    timeTim = 0;
  }
}

int Player::getTimTime(){
  return timeTim;
}

int Player::getCupsOwn(){
  return cupsOwn;
}

void Player::receiveCup(){
  ++cupsOwn;
}

void Player::useCup(){
  if(cupsOwn <= 0) {
    cout << "You do not have any Cups left!" << endl;
    return;
  }
  --cupsOwn;
}

int Player::netCapital(){
  int money = balance;
  for (pList::iterator it=pList.begin(); it!=plist.end(); ++it){
    if((buildings.at(it->second))->isMort == false &&
     (buildings.at(it->second))->isAcademic == false){
       money += (buildings.at(it->second))->getPrice();
       money += ((buildings.at(it->second))->getImproveCost())*
                 ((buildings.at(it->second))->getImproveCount());
     }
  }
  return money;
}

void Player::bankrupt(){
  cout << name << " is now bankrupted! Cheers!" << endl;
  if (players.size() <= 2){
    gameEnd = true;
    if(players.back() != this){
      (players.back())->isWinner();
    } else {
      (players.front())->isWinner();
    }
  } else {
    //restore rollupCup in tim
    int timIndex = 10;
    int cupRemain = buildings[TimIndex]->getNumRoll();
    buildings[TimIndex]->setNumRoll(cupRemain + cupsOwn);
    string nextCommand;
    cout << "Please choose from the following two options:" << endl;
    cout << "Type <auction> if you want your properties auctioned." << endl;
    cout << "Type <give> to send your properties to the player owed." << endl;
    try{
      while(true){
        cin >> nextCommand;
        if (nextCommand == "auction"){
          for (pList::iterator it=pList.begin(); it!=plist.end(); ++it){
            this->auction(it->first, it->second);
          }
          cout << name << "'s properties were auctioned!" << endl;
          break;
        } else if(nextCommand == "give") {
          string OwedPerson = buildings[pos]->getOwner();
          for (pList::iterator it=pList.begin(); it!=plist.end(); ++it){
            this->sendProperty(OwedPerson,buildings[it->second]);
          }
          cout << "All properties were sent to " << OwedPerson << "!" << endl;
          break;
        } else {
          cout << "Invalid command. Please choose again." << endl;
        }
      }
    } catch (ios::failure &){}
  }
  for (players::iterator it = players.begin() ; it != players.end(); ++it){
    if(it == this){
      players.erase(it);
      delete this;
    }
  }
}

bool Player::getGameStatus(){
  return gameEnd;
}

void Player::auction(string bname, int bpos){ //use map
  if (gameEnd == false) {
    int totalbidders = players.size() - 1;
    int curbid = (buildings.at(pos))->getPrice();
    int cur_index;
    map<int, string> bidderList;
    for(int i=0; i<totalbidders;++i){
      if(players[i]->getName() == this->getName()){
        continue;
      }
      bidderList[players[i]->getName()] = players[i]->getName();
    }
    cout << "Bidding started on " << bname << "!" << endl;
    cout << "Lowest bid is " << (buildings.at(pos))->getPrice() << endl;
    int prevPriceBid;
    while(totalbidders >= 1) {
      if (prevPriceBid == 0){
        bidderList.erase(--bidderList.end());
        prePriceBid = 1;
      }
      for(bidderList::iterator it=bidderList.begin();it!=bidderList.end();++it){
        if(totalbidders == 1){
          cout << "Congrats! " << it->second << " wins the bid for ";
          cout << bname << "!" << endl;
          this->sendProperty(players[it->first],buildings[bpos]);
          players[it->first]->changeBalance(0 - curbid);
          --totalbidders;
          break;
        }
        if (prevPriceBid == 0){
          bidderList.erase(--it);
        }
        cout << it->second << ":" << endl;
        cout << "Please choose from the following two options:" << endl;
        cout << "If bidding, type in an integer greater than the current bid."
        << endl;
        cout << "If quiting, type 0." << endl;
        try {
          int priceBid;
          cin >> priceBid;
          if(players[it->first]->canBankrupt(0 - priceBid)) {
            cout << "Invalid bid! You don't have enough money!" << endl;
            --it;
            continue;
          }
          if(priceBid == 0){
            prevPriceBid = 0;
            --totalbidders;
            continue;
          }else if(priceBid > curbid){
            curbid = priceBid;
            prevPriceBid = curbid;
            continue;
          }else{
            cout << "Invalid price. Please enter your command again." << endl;
            --it;
            continue;
          }
        } catch (ios::failure &){
          cout << "Invalid command entered." << endl;
          --it;
          continue;
        }
      }
    }
    bidderList.clear();
  }
}

void Players::isWinner(){
  cout << name << "wins the game!" << endl;
  cout << "Game Over." << endl;
//  delete players.back();
//  delete players.front();
//  players.clear();
}

void Player::printProperties() {
  if(pList.size()==0) {
    cout << "You don't own any properties right now!" << endl;
    return;
  }
  cout << "Here is the list of your properties:" << endl;
  for (pList::iterator it=pList.begin(); it!=plist.end(); ++it){
    cout << (buildings[it->second])->getName() << endl;
  }
}

void Player::prop_manip(int ppos, int changeMoney, string s){
  string pname = p->getName();
  if(s == "tradein") {
    if(pList.count(pname)!=0){
      cout << name << " already owns " << pname << ". Invalid trade!" << endl;
      return;
    }
    if (changeMoney < 0) {
      (buildings[ppos]->setOwner(this));
      pList[buildings[ppos]->getName()] = ppos;
    } else {
      if(balance - changeMoney < 0){
        cout << "Invalid Trade request. Go get more money!"
        return;
      }
      (buildings[ppos]->setOwner(this));
      pList[buildings[ppos]->getName()] = ppos;
      this->changeBalance(0 - changeMoney);
    }
  } else if (s == "tradeout") {
    if(!(this->own(buildings[ppos]))){
      cout << name << " doesn't own " << pname << ". Invalid trade!" << endl;
      return;
    }
    if (changeMoney < 0) {
  //    buildings[ppos]->setOwner(nullptr));
      pList.erase(buildings[ppos]->getName());
    } else {
//      buildings[ppos]->setOwner(nullptr));
      pList.erase(buildings[ppos]->getName());
      this->changeBalance(changeMoney);
    }
  } else if (s == "mortgage") {
    if(!(this->own(buildings[ppos]))){
      cout << name << " doesn't own " << pname << ". Invalid mortgage!" << endl;
      return;
    }
    if(buildings[ppos]->getMort()) {
      cout << "Invalid command! This building is already mortgaged!" << endl;
      return;
    }
    f(buildings[ppos]->getMort()) {
      cout << "Invalid command! This building is already mortgaged!" << endl;
      return;
    }
    this->changeBalance((buildings[ppos]->getPrice())/2);
    buildings[ppos]->changeMort();
  } else if (s == "unmortgage") {
    if(!(this->own(buildings[ppos]))){
      cout << name << " doesn't own " << pname;
      cout << ". Invalid unmortgage!" << endl;
      return;
    }
    if(!(buildings[ppos]->getMort())) {
      cout << "Invalid command! This building is already unmortgaged!" << endl;
      return;
    }
    int percentToPay = 0.6;
    this->changeBalance(0 - (buildings[ppos]->getPrice())*percentToPay);
    buildings[ppos]->changeMort();
  } else if (s == "improve") {
    this->changeBalance(0 - buildings[ppos]->getImproveCost());
    // remember to switch improvable to false if improvement count reaches max
    buildings[ppos]->setImproveCount(buildings[ppos]->getImproveCount() + 1);
  } else if (s == "unimprove") {
    if(buildings[ppos]->getImproveCount() <= 0){
      cout << "Invalid command! No more improvements to sell!" << endl;
      return;
    }
    this->changeBalance((buildings[ppos]->getImproveCost())/2);
    buildings[ppos]->setImproveCount(buildings[ppos]->getImproveCount() - 1);
  } else {
    cout << "Invalid command, please type again." << endl;
  }
}

bool Player::isBankrupt(){
  return isBankrupt;
}

void Player::makeBankrupt(){
  isBankrupt = true;
}

bool Player::canBankrupt(int change){
  if (balance + change < 0) {
    return true;
  } else {
    return false;
  }
}

bool Player::own(Property* p){
  return (this == p->getOwner());
}

vector<Building*> *Player::getBuildingList(){
  return &buildings;
}

int Player::getNumOwn(string b){
  int count;
  if(b == "gym"){
    count = pList.count("PAC") + pList.count("CIF");
  }else if(b == "res"){
    count = pList.count("MKV") + pList.count("UWP") +
            pList.count("V1") + pList.count("REV");
  }else{
    count = 0;
  }
  return count;
}

Player::~Player(){}
