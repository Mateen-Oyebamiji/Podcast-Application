#include "Subscriber.h"

Subscriber::Subscriber(const string& n,const string& c){
  name=n;
  creditcard=c;
}

string Subscriber::getName(){ return name; }
string Subscriber::getCreditcard(){ return creditcard; }

bool Subscriber::matches(const string& n){
  if(name==n){
    return true;
  }
  return false;
}

void Subscriber::print(){
  cout<<"Name: "<<name<<";Credit card: "<<creditcard<<endl;
}
