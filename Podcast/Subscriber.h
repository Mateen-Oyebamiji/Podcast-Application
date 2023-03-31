#ifndef SUB_H
#define SUB_H

#include <iostream>
#include <string>

using namespace std;
class Subscriber{
  public:
    //Constructors
    //Subscriber();
    Subscriber(const string& n="Customer",const string& c="VISA");
    //Gettters
    string getName();
    string getCreditcard();
    //member Functions
    bool matches(const string& name);
    void print();

  private:
    string name;
    string creditcard;
};
#endif
