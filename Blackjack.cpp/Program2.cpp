#include <iostream>
#include <string>
#include <fstream>

using namespace std;

main(){
  int blackjack=0;
  double push=0.0;
  double win=0.0;
  double loss=0.0;
  int gamesplayed=0;
  string aline;
  double percentage=0.0;
  double bjPErcentage =0.0;

ifstream statfile;

statfile.open("BJdata.txt");

while(statfile.good())
{
  getline(statfile,aline);
  if(aline=="DealerWin")
  {
  loss++;
  gamesplayed++;
  }
  else if (aline == "PlayerWin"){
    win++;
    gamesplayed++;
  }
  else if(aline=="Blackjack")
  {
  blackjack++;
  gamesplayed++;
  win++;
  }
  else if (aline=="Push")
    {
    gamesplayed++;
    push++;
    }


}

  percentage = win/(gamesplayed-push);
  bjPErcentage = blackjack/(gamesplayed-push);
cout<<"Wins: "<<win<<endl<<endl;
cout<<"Losses: "<<loss<<endl<<endl;
cout<<"Blackjacks: "<<blackjack<<endl<<endl;
cout<<"Pushes: "<<push<<endl<<endl;
cout<<"Win Percentage: "<<percentage<<" %"<<endl;
cout<<"Blackjack Percentage: "<<bjPErcentage<<" %"<<endl;


}
