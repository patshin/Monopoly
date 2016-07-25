#include "player.h"
#include "Building.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

Player::Player(std::string name, char nc, vector<Building*> &b, vector<Player*> &p):
  name{name},nameChar{nc},buildings{b},players{p}{
    pos = rand() % 40;
    while(pos == 30){
     pos = rand()%40;
    }
    balance = 500;
    timeTim = 0;
    cupsOwn = 0;
    isBankrupted = false;
    roll = true;
    buildings[pos]->setPlayer(this);
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
  return roll;
}

void Player::changeRollable(){
  if(roll == true) {
    roll = false;
  }else{
    roll = true;
  }
}

void Player::move(int step){
  buildings[pos]->removePlayer(this);  
  if(timeTim == 1 || timeTim == 2){
    gotoSite(10);
    return;
  }
  if (step >= 0) {
    if(pos+step<=39){
      pos += step;
    }else{
      pos = pos+step-40;
    }
  } else {
    if(pos+step<=0){
      pos = 40+pos-step;
    }else{
      pos += step;
    }
  }
  cout << name << " was moved to " << buildings[pos]->getName() << endl;
  //cout << "player::start setting player" << endl;
  buildings[pos]->setPlayer(this);
  //cout << "player::finish setting" << endl;
  buildings[pos]->method(this);
  //cout << "player::finishing this building" << endl;
}

void Player::gotoSite(int p){
  cout << "go to " << p << endl;
  buildings[pos]->removePlayer(this);
  //cout << "player::finish removing" << endl;
  pos = p;
  buildings[pos]->setPlayer(this);
  buildings[pos]->method(this);
}

void Player::purchase(string bname){
  pList[bname]=pos;
  (buildings.at(pos))->setOwner(this);
  int pay = 0 - (buildings.at(pos))->getPrice();
  if(canBankrupt(pay)) {
    cout << "Warning! You don't have enough money!" << endl;
    return;
  }
  this->changeBalance(pay);
  cout << name << " now owns " << bname << "!" << endl;
}

void Player::sendProperty(Player* p, int bpos){
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
  for (auto it = buildings.begin() ; it != buildings.end(); ++it){
    if((*it)->getOwn()){
      if((*it)->getAca()){
        if(blockname == (*it)->getblock()){
          if(((*it)->getOwner())->getName() != name){
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
    cout << "Warning! You are going to be bankrupted!" << endl;
  }
  balance += change;  
  if(change > 0){
  cout << change << " dollar added into " << name << "'s balance!" << endl;
  }else{
    int i = 0 - change;
    cout << i << " dollar removed from " << name << "'s balance!" << endl;
  }
}

void Player::setTimTime(int n) {
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
  for (auto it=pList.begin(); it!=pList.end(); ++it){
    if((buildings.at(it->second))->getMort() == false &&
     (buildings.at(it->second))->getAca() == false){
       money += (buildings.at(it->second))->getPrice();
       money += ((buildings.at(it->second))->getImproveCost())*
                 ((buildings.at(it->second))->getImproveCount());
     }
  }
  return money;
}

void Player::bankrupt(){
  cout << name << " is now bankrupted! HAHAHA!" << endl;
  //restore rollupCup in tim
  int timIndex = 10;
  int cupRemain = buildings[timIndex]->getNumRoll();
  buildings[timIndex]->setNumRoll(cupRemain + cupsOwn);
  string nextCommand;
  cout << "Please choose from the following two options:" << endl;
  cout << "Type <auction> if you want your properties auctioned." << endl;
  cout << "Type <give> to send your properties to the player owed." << endl;
  try{
    while(cin >> nextCommand){
      if (nextCommand == "auction"){
        for (auto it=pList.begin(); it!=pList.end(); ++it){
          this->auction(it->first, it->second);
        }
        cout << name << "'s properties were successfully auctioned!" << endl;
        break;
      } else if(nextCommand == "give") {
        Player* OwedPerson = buildings[pos]->getOwner();
        for (auto it=pList.begin(); it!=pList.end(); ++it){
          this->sendProperty(OwedPerson,it->second);
        }
        cout << "All properties were sent to " << OwedPerson->getName() << "!" << endl;
        break;
      } else {
        cout << "Invalid command. Please choose again." << endl;
        continue;
      }
    }
  } catch (ios::failure &){}
  //delete every player's TBD
  for (auto it = players.begin() ; it != players.end(); ++it){
    if((*it)->getName() == name){
      players.erase(it);
    }
  }
//  cout << "Number of players remain:" << endl;
  delete this;
}

void Player::auction(string bname, int bpos){ //use map
  int totalbidders = players.size() - 1;
  cout << "total bidder is " << totalbidders << endl;
  int curbid = (buildings.at(pos))->getPrice();
  map<int, string> bidderList;
  for(int i=0; i<totalbidders+1;++i){
    if(players[i]->getName() == this->getName()){
      continue;
    }
    bidderList[i] = players[i]->getName();
  }
  cout << "Bidding started on " << bname << "!" << endl;
  cout << "Lowest bid is " << (buildings.at(pos))->getPrice() << endl;
  int prevPriceBid = 1;
  while(totalbidders >= 1) {
    if (prevPriceBid == 0){
      bidderList.erase(--bidderList.end());
      prevPriceBid = 1;
    }
    for(auto it=bidderList.begin();it!=bidderList.end();++it){
      if(totalbidders == 1){
        cout << "Congrats! " << it->second << " wins the bid for ";
        cout << bname << "!" << endl;
        this->sendProperty(players[it->first],bpos);
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
      --curbid;
      try {
	int priceBid = 1;
	while(cin >> priceBid){
          if(players[it->first]->canBankrupt(0 - priceBid)) {
            cout << "Invalid bid! You don't have enough money!" << endl;
            continue;
          }
          if(priceBid == 0){
            prevPriceBid = 0;
            --totalbidders;
            break;
          }else if(priceBid > curbid){
            curbid = priceBid;
            prevPriceBid = curbid;
            break;
          }else{
            cout << "Invalid price. Please enter your command again." << endl;
            continue;
          }
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

void Player::printProperties() {
  if(pList.size()==0) {
    cout << "You don't own any properties right now!" << endl;
    return;
  }
  cout << name << "'s balance: " << balance << endl;
  cout << name << " owns:" << endl;
  for (map<string,int>::iterator it=pList.begin(); it!=pList.end(); ++it){
    cout << (buildings[it->second])->getName() << " ";
  }
  cout << endl;
}

void Player::prop_manip(int ppos, int changeMoney, string s){
  string pname = getName();
  if(s == "tradein") {
    if(pList.count(pname)!=0){
      cout << name << " already owns " << pname << ". Invalid trade!" << endl;
      return;
    }
    if (changeMoney < 0) {
      buildings[ppos]->setOwner(this);
      this->addProperty(ppos);
    } else {
      if(balance - changeMoney < 0){
        cout << "Invalid Trade request. Go get more money!" << endl;
        return;
      }
      buildings[ppos]->setOwner(this);
      this->addProperty(ppos);
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
    if(balance - changeMoney < 0){
      cout << "Invalid Improve request. Go get more money!" << endl;
      return;
    }
    this->changeBalance(0 - buildings[ppos]->getImproveCost());
    // remember to switch improvable to false if improvement count reaches max
    buildings[ppos]->setImprovements(buildings[ppos]->getImproveCount() + 1);
  } else if (s == "unimprove") {
    if(buildings[ppos]->getImproveCount() <= 0){
      cout << "Invalid command! No more improvements to sell!" << endl;
      return;
    }
    this->changeBalance((buildings[ppos]->getImproveCost())/2);
    buildings[ppos]->setImprovements(buildings[ppos]->getImproveCount() - 1);
  } else {
    cout << "Invalid command, please type again." << endl;
  }
}

bool Player::isBankrupt(){
  return isBankrupted;
}

void Player::makeBankrupt(){
  isBankrupted = true;
}

bool Player::canBankrupt(int change){
  if (balance + change < 0) {
    return true;
  } else {
    return false;
  }
}

bool Player::own(Building* p){
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

void Player::setCupsOwn(int cup){
  cupsOwn = cup;
}

void Player::setBalance(int bal){
  balance = bal;
}

void Player::setPos(int p){
  pos = p;
  buildings[pos]->setPlayer(this);
}

void Player::setPlayerList(vector<Player*> &pv){
  players = pv;
}

Player::~Player(){}
