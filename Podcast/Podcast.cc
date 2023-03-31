#include "Podcast.h"
#include "defs.h"
#include "Episode.h"

Podcast::Podcast(const string& t,const string& h){
  title=t;
  host=h;
  arr = new Episode*[MAX_EPS];
  numEps=0;
}

Podcast::Podcast(){
  title="The Sync";
  host="Kai";
  arr = new Episode*[MAX_EPS];
}

Podcast::~Podcast(){
  for(int i=0;i<numEps;++i){
    delete arr[i];
  }
  delete [] arr;
}

Podcast::Podcast(Podcast& pod){
  title = pod.title;
  host=pod.host;
  arr = new Episode*[MAX_EPS];
  numEps=pod.numEps;
  for(int i=0;i<pod.numEps;++i){
    arr[i] = new Episode(*pod.arr[i]);
  }
}

string Podcast::getTitle() const{ return title; }
string Podcast::getHost() const{ return host; }
int Podcast::getNumEpisodes(){ return numEps; }

bool Podcast::addEpisode(const string& t,const string& content){
  if(numEps < MAX_EPS){
    //Episode temp(this.title,numEps,t,content);
    arr[numEps] = new Episode(title,numEps,t,content);
    numEps++;
    return true;
  }
  return false;
}

bool Podcast::getEpisode(int index, Episode** ep){
  for(int i=0;i<numEps;++i){
    if(arr[i]->getNumber() == index){
      *ep = arr[i];
      return true;
    }
  }
  return false;
}

bool Podcast::lessThan(Podcast& pod){
  if(title < pod.title){
    return true;
  }
  return false;
}

void Podcast::print(){
  cout<<"Title: "<<title<<" Host: "<<host<<endl;
  cout<<"EPISODES: "<<endl;
  for(int i=0;i<numEps;i++){
    arr[i]->print();
  }
}
