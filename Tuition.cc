#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "Tuition.h"
using namespace std;
void Tuition::method(Player* p){
 cout<<"[pay] 300 or [lose] 10 percents of your total money ?" <<endl;
 string s;
 cin>>s;
 if(s == "pay"){
  p->changeBalance(-300);
 }else if(s == "lose"){
  p->changeBalance((p->totalmoney()/10));
 }else{
  cout << "error input, try again" << endl;
  this.method(p);
 }
}


int totalMoney(){
 int n = balance;
 for(map<string,int>::iterator i = pList.begin(); i!= pList.end();i++){
  n+=(buildings[i->second])->getValue();
 }
 return n;
}
