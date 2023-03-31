#include "Episode.h"

Episode::Episode(){
  podcast = "A Podcast";
  number = 1;
  name="An Episode";
  content ="Random Content";
}

Episode::Episode(const string& p,int num,const string& n,const string& c){
  podcast = p;
  number = num;
  name = n;
  content = c;
}

void Episode::play(){
  cout<<"Podcast: "<<podcast<<endl;
  cout<<"Name: "<<name<<"; Number: "<<number<<endl;
  cout<<"Content: "<<content<<endl;
  //std::cout
}

void Episode::print(){
  cout<<"Podcast: "<<podcast<<endl;
  cout<<"Name: "<<name<<"; Number: "<<number<<endl;
  cout<<"Content: "<<content<<endl;
  //std::cout
}
string Episode::getName(){ return name;}
string Episode::getContent(){ return content;}
string Episode::getPodcast(){ return podcast;}
int Episode::getNumber(){return number;}

/*
int main(){
  Episode one("The sync",5,"100th","Entertainment");
  one.play();
  return 0;
}*/
