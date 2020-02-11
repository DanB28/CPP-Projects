
#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <iostream>
#include <cstddef>

using namespace std;

class player
{
//private:
public:
  string Number;
  string lastname;
  string firstname;
  string gamesPlayed;
  string gamesStarted;
  string minutes;
  string averageMin;
  string fg;
  string fga;
  string fgPercent;
  string threefg;
  string threefga;
  string threefgPercent;
  string ft;
  string fta;
  string FO;
  string favg;
  string off;
  string def;
  string pf;
  string totf;
  string assist;
  string TO;
  string blocks;
  string steals;
  string pts;
  string AVG;
  string ftPercent;
//public:
    string getNumber();
    string getLname();
    string getFname();
    string getGamesPlayed();
    string getGamesStarted();
    string getMinutes();
    string getAvgmin();
    string getFg();
    string getFga();
    string getFgPercentage();
    string get3fg();
    string get3fga();
    string get3fgPercent();
    string getft();
    string getfta();
    string getftPercent();
    string getoff();
    string getdef();
    string gettot();
    string getfavg();
    string getpf();
    string getfo();
    string getassist();
    string getto();
    string getblocks();
    string getsteals();
    string getpts();
    string getAVG();

    void setNumber(string);
    void setlname(string);
    void setfname(string);
    void setgamesplayed(string);
    void setminutes(string);
    void setgamesstarted(string);
    void setaveragemin(string );
    void setfg(string);
    void setfga(string);
    void setfgpercent(string);
    void setthreefg(string);
    void setthreefga(string);
    void setthreefgpercent(string);
    void setft(string);
    void setfta(string);
    void setftpercent(string );
    void setoff(string);
    void setdef(string);
    void settotf(string);
    void setfavg(string);
    void setpf(string);
    void setfo(string);
    void setassist(string);
    void setto(string);
    void setblocks(string);
    void setsteals(string);
    void setpts(string);
    void setAVG(string);
    player();

};

player::player()
{
  Number= ' ' ;
  lastname = " ";
  firstname = " ";
  gamesPlayed = " ";
  gamesStarted = " ";
  minutes = " ";
  averageMin = " ";
  fg = " ";
  fga = " ";
  fgPercent = " ";
  threefg = " ";
  threefga = " ";
  threefgPercent = " ";
  ft = " ";
  fta = " ";
  FO = " ";
  favg = " ";
  off = " ";
  def = " ";
  pf = " ";
  totf = " ";
  assist = " ";
  TO = " ";
  blocks = " ";
  steals = " ";
  pts = " ";
  AVG = " ";
  ftPercent = " ";
  return;
}


void player::setNumber(string a){
  Number = a;
}
void player::setlname(string b){
  lastname = b;
}
void player::setfname(string c){
  firstname = c;
}
void player::setgamesplayed(string d){
  gamesPlayed = d;
}
void player::setgamesstarted(string e){
  gamesStarted = e;
}
void player::setminutes(string f){
  minutes = f;
}
void player::setaveragemin(string g){
  averageMin = g;
}
void player::setfg(string h){
  fg = h;
}
void player::setfga(string i){
  fga = i;
}
void player::setfgpercent(string e){
  fgPercent = e;
}
void player::setthreefg(string f){
  threefg = f;
}
void player::setthreefga(string g){
  threefga = g;
}
void player::setthreefgpercent(string e){
  threefgPercent = e;
}
void player::setft(string f){
  ft = f;
}
void player::setfta(string g){
  fta = g;
}
void player::setftpercent(string h){
  ftPercent = h;
}
void player::setoff(string i){
  off = i;
}
void player::setdef(string j){
  def = j;
}
void player::settotf(string k){
  totf = k;
}
void player::setfavg(string l){
  favg = l;
}
void player::setpf(string m){
  pf = m;
}
void player::setfo(string n){
  FO = n;

}
void player::setassist(string o){
  assist = o;
}
void player::setto(string p){
  TO= p;
}
void player::setblocks(string q){
  blocks = q;
}
void player::setsteals(string r){
  steals = r;
}
void player::setpts(string s){
  pts = s;
}
void player::setAVG(string t){
  AVG= t;
}

  string player::getNumber(){
    return Number;
  }

  string player::getLname(){
  return lastname;
  }
  string player::getFname(){
    return firstname;
  }
  string player::getGamesPlayed(){
    return gamesPlayed;
  }
  string player::getGamesStarted(){
    return gamesStarted;
  }
  string player::getMinutes(){
    return minutes;
  }
  string player::getAvgmin(){
    return averageMin;
  }
  string player::getFg(){
    return fg;
  }
  string player::getFga(){
    return fga;
  }
  string player::getFgPercentage(){
    return fgPercent;
  }
  string player::get3fg(){
    return threefg;
  }
  string player::get3fga(){
    return threefga;
  }
  string player::get3fgPercent(){
    return threefgPercent;
  }
  string player::getft(){
    return ft;
  }
  string player::getfta(){
    return fta;
  }
  string player::getftPercent(){
    return ftPercent;
  }
  string player::getoff(){
    return off;
  }
  string player::getdef(){
    return def;
  }
  string player::gettot(){
    return totf;
  }
  string player::getfavg(){
    return favg;
  }
  string player::getpf(){
    return pf;
  }
  string player::getfo(){
    return FO;
  }
  string player::getassist(){
    return assist;
  }
  string player::getto(){
    return TO;
  }
  string player::getblocks(){
    return blocks;
  }
  string player::getsteals(){
    return steals;
  }
  string player::getpts(){
    return pts;
  }
  string player::getAVG(){
    return AVG;
  }

#endif
