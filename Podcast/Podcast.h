#ifndef POD_H
#define POD_H
//#define MAX_PODS 5
//#define MAX_EPS 100

#include <iostream>
#include <string>
#include "defs.h"
#include "Episode.h"

using namespace std;
class Podcast{
  public:
    //constructors
    Podcast();
    Podcast(const string& title,const string& host);
    Podcast(Podcast&);
    ~Podcast();  //Destructor
    //member Functions
    bool addEpisode(const string& title,const string& content);
    bool getEpisode(int index, Episode** ep);
    bool lessThan(Podcast& pod);
    void print();
    //getters
    string getTitle() const;
    string getHost() const;
    int getNumEpisodes();
  private:
    string title;
    string host;
    Episode** arr;  //Dynamically Allocated Array of Episode pointers
    int numEps;

};
#endif
