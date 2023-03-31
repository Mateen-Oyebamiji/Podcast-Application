#ifndef EP_H
#define EP_H

#include <iostream>
#include <string>

using namespace std;
class Episode{
  public:
    //Constructors
    Episode();
    Episode(const string& podcast, int number, const string& name,const string& content);
    //Memeber Functions
    void play();
    void print();
    //setters
    void setName(string);
    void setContent(string);
    void setPodcast(string);
    void setNumber(int);
    //Gettters
    string getName();
    string getContent();
    string getPodcast();
    int getNumber();

  private:
    string name;
    string content;
    string podcast;
    int number;
};

#endif
