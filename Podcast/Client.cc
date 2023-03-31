#include "Client.h"
#include "Network.h"
#include "Podcast.h"
#include "PodArray.h"
#include "Subscriber.h"
#include "Episode.h"
#include "defs.h"

Client::Client(const string& n){
  name=n;
  podArr = new PodArray;
}

Client::~Client(){
  delete podArr;
}

void Client::download(Network* net,const string& podcast){
  Podcast* p;
  if(net->download(name,podcast,&p)){
    if(podArr->isFull() == false){
      Podcast* p2 = new Podcast(*p);     //might need to derefrence
      podArr->addPodcast(p2);
    } else{
      cout<<"PodArray is full"<<endl;
    }
  } else{
    cout<<"Could not Download"<<endl;
  }
}

void Client::stream(Network* net,const string& podcast,int num){
  Episode* ep;
  if(net->stream(name,podcast,num,&ep)){
    ep->play();
  }
}

void Client::playLocal(const string& podcast,int num){
  Podcast* p;
  Episode* ep;
  if(podArr->getPodcast(podcast,&p)){
    if(p->getEpisode(num,&ep)){
      ep->play();
    } else{ cout<<"Could not find Episode"<<endl; }
  } else{ cout<<"Could not find podcast"<<endl; }
}

void Client::print(){
  cout<<"Client Name: "<<name<<endl;
  podArr->print();
}
