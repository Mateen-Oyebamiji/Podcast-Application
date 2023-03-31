#ifndef CL_H
#define CL_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Podcast.h"
#include "PodArray.h"
#include "Subscriber.h"
#include "Network.h"
#include "defs.h"

using namespace std;
class Client {
  public:
    Client(const string& n="Mr Client");  //constructor
    ~Client();            //destructor
    //member Functions
    void download(Network* net,const string& podcast);
    void stream(Network* net,const string& podcast,int num);
    void playLocal(const string& podcast,int num);
    void print();


  private:
    string name;
    PodArray* podArr;
};
#endif
