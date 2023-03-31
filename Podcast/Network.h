#ifndef NET_H
#define NET_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Podcast.h"
#include "PodArray.h"
#include "Subscriber.h"
#include "defs.h"

using namespace std;

class Network {
  public:
    Network(const string& n="A network");  //constructor
    ~Network();                  //destructor
    //member Functions
    bool getPodcast(const string& title, Podcast**);
    bool addPodcast(const string& title,const string& host);
    bool removePodcast(const string& title);
    bool addEpisode(const string& podcast,const string& title,const string& content);
    bool addSubscriber(const string& n,const string& c);
    bool download(const string& sub,const string& podcast,Podcast** );
    bool stream(const string& sub,const string& podcast,int num,Episode** );
    bool hasSubscriber(const string& name);
    void print();




  private:
    string name;
    PodArray* podArr;
    Subscriber* subArr[MAX_SUBS]; //statically allocated array of subscriber pointers
    int numSubs;
};
#endif
