#include "Network.h"
#include "Podcast.h"
#include "PodArray.h"
#include "Subscriber.h"
#include "Episode.h"
#include "defs.h"

Network::Network(const string& n){
  name=n;
  numSubs=0;
  podArr = new PodArray;
}

Network::~Network(){
  for(int i=0;i<numSubs;++i){
    delete subArr[i];
  }
  //podArr->~PodArray();
  delete podArr;
}
bool Network::getPodcast(const string& title, Podcast** pod){
  return podArr->getPodcast(title,pod);
}

bool Network::addPodcast(const string& title,const string& host){
  Podcast* p = new Podcast(title,host);
  return podArr->addPodcast(p);
}

bool Network::removePodcast(const string& title){
  Podcast* p;
  if(podArr->removePodcast(title,&p)){
    delete p;
    return true;
  }
  return false;
}

bool Network::addEpisode(const string& podcast,const string& title,const string& content){
  Podcast* p;
  if(podArr->getPodcast(podcast,&p)){
    p->addEpisode(title,content);
    return true;
  }
  return false;
}

bool Network::addSubscriber(const string& n,const string& c){
  if(numSubs < MAX_SUBS){
    subArr[numSubs]= new Subscriber(n,c);
    numSubs++;
    return true;
  }
  return false;
}

bool Network::hasSubscriber(const string& name){
  for(int i=0;i<numSubs;++i){
    if(subArr[i]->getName() == name){
      return true;
    }
  }
  return false;
}

bool Network::download(const string& sub,const string& podcast,Podcast** pod ){
  Podcast* p;
  if(this->hasSubscriber(sub)){
    if(this->getPodcast(podcast,&p)){
      *pod=p;
      return true;
    } else{
      cout<<"No such Podcast"<<endl;
      return false;
    }
  } else{
    cout<<"No such Subscriber"<<endl;
    return false;
  }
  return false;
}

bool Network::stream(const string& sub,const string& podcast,int num,Episode** ep ){
  Podcast* p;
  if(this->hasSubscriber(sub)){
    if(this->getPodcast(podcast,&p)){
       if(p->getEpisode(num,ep)){
         return true;
       } else{
         cout<<"No such episode"<<endl;
         return false;
       }
    } else{
      cout<<"No such Podcast"<<endl;
      return false;
    }
  } else{
    cout<<"No such Subscriber"<<endl;
    return false;
  }

  return false;
}

void Network::print(){
  cout<<"NAME: "<<name<<endl;
  cout<<"PODCASTS: "<<endl;
  podArr->print();
  cout<<"SUBSCRIBERS: "<<endl;
  for(int i=0;i<numSubs;++i){
    subArr[i]->print();
  }
}
