
#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>
#include "player.h"
#include <stdlib.h>

using namespace std;
int input=0; // change 0 this to nothing
string player1;
string player2;
vector<string>lines;
ifstream statfile;
string aline;
vector<player>Players;
vector<string>stats;
int count =0;
string a;
int player1pos =0;
int player2pos =0;
bool playerfound1 = false;
bool playerfound2=false;


// following functions are for comparisons
void compareGames(int player1pos,int player2pos)
{
  string name1 = Players.at(player1pos).getFname()+ " " + Players.at(player1pos).getLname();
  string name2 = Players.at(player2pos).getFname()+" "+Players.at(player2pos).getLname();


    cout<< left<< setw(25)  << name1<< "|";
    cout<< right<<setw(25) << name2 << endl;
    cout << setfill('-') << setw(52) << "" << endl;
    cout<<setfill(' ');
    cout<<left<<setw(20)<<Players.at(player1pos).getGamesPlayed()<<"Games Played";
    cout<<right<<setw(20)<<Players.at(player2pos).getGamesPlayed()<<endl;
    cout<< right<< setw(26) << "|";
    cout<< left<<setw(26) <<endl;
    cout<<left<<setw(20)<<Players.at(player1pos).getGamesStarted()<<"Games Started";
    cout<<right<<setw(20)<<Players.at(player2pos).getGamesStarted()<<endl<<endl;

} // end of compare Games

void compareMinutes(int player1pos,int player2pos)
{
  string name1 = Players.at(player1pos).getFname()+ " " + Players.at(player1pos).getLname();
  string name2 = Players.at(player2pos).getFname()+" "+Players.at(player2pos).getLname();


    cout<< left<< setw(25)  << name1<< "|";
    cout<< right<<setw(25) << name2 << endl;
    cout << setfill('-') << setw(52) << "" << endl;
    cout<<setfill(' ');
    cout<<left<<setw(20)<<Players.at(player1pos).getMinutes()<<"Minutes Played";
    cout<<right<<setw(20)<<Players.at(player2pos).getMinutes()<<endl;
    cout<< right<< setw(26) << "|";
    cout<< left<<setw(26) <<endl;
    cout<<left<<setw(20)<<Players.at(player1pos).getAvgmin()<<"Avg Min played";
    cout<<right<<setw(20)<<Players.at(player2pos).getAvgmin()<<endl<<endl;

}

void compareFieldgoals(int player1pos,int player2pos)
{
  string name1 = Players.at(player1pos).getFname()+ " " + Players.at(player1pos).getLname();
  string name2 = Players.at(player2pos).getFname()+" "+Players.at(player2pos).getLname();


    cout<< left<< setw(25)  << name1<< "|";
    cout<< right<<setw(25) << name2 << endl;
    cout << setfill('-') << setw(52) << "" << endl;
    cout<<setfill(' ');
    cout<<left<<setw(20)<<Players.at(player1pos).getFg()<<"Feild Goals";
    cout<<right<<setw(20)<<Players.at(player2pos).getFg()<<endl;
    cout<< right<< setw(26) << "|";
    cout<< left<<setw(26) <<endl;
    cout<<left<<setw(15)<<Players.at(player1pos).getFga()<<"Field Goals Attempted";
    cout<<right<<setw(15)<<Players.at(player2pos).getFga()<<endl<<endl;
    cout<< right<< setw(26) << "|";
    cout<< left<<setw(26) <<endl;
    cout<<left<<setw(15)<<Players.at(player1pos).getFgPercentage()<<"Field Goals Percent";
    cout<<right<<setw(18)<<Players.at(player2pos).getFgPercentage()<<endl<<endl;

}

void compareThreePointers(int player1pos,int player2pos)
{

  string name1 = Players.at(player1pos).getFname()+ " " + Players.at(player1pos).getLname();
  string name2 = Players.at(player2pos).getFname()+" "+Players.at(player2pos).getLname();


    cout<< left<< setw(25)  << name1<< "|";
    cout<< right<<setw(25) << name2 << endl;
    cout << setfill('-') << setw(52) << "" << endl;
    cout<<setfill(' ');
    cout<<left<<setw(20)<<Players.at(player1pos).get3fg()<<"Three Pointers";
    cout<<right<<setw(20)<<Players.at(player2pos).get3fg()<<endl;
    cout<< right<< setw(26) << "|";
    cout<< left<<setw(26) <<endl;
    cout<<left<<setw(15)<<Players.at(player1pos).get3fga()<<"Three pointers Attempted";
    cout<<right<<setw(15)<<Players.at(player2pos).get3fga()<<endl<<endl;
    cout<< right<< setw(26) << "|";
    cout<< left<<setw(26) <<endl;
    cout<<left<<setw(15)<<Players.at(player1pos).get3fgPercent()<<"Three Pointer Percent";
    cout<<right<<setw(18)<<Players.at(player2pos).get3fgPercent()<<endl<<endl;

}

void compareFreeThrows(int player1pos,int player2pos)
{
  string name1 = Players.at(player1pos).getFname()+ " " + Players.at(player1pos).getLname();
  string name2 = Players.at(player2pos).getFname()+" "+Players.at(player2pos).getLname();

  cout<< left<< setw(25)  << name1<< "|";
  cout<< right<<setw(25) << name2 << endl;
  cout << setfill('-') << setw(52) << "" << endl;
  cout<<setfill(' ');
  cout<<left<<setw(20)<<Players.at(player1pos).getft()<<"Free Throws";
  cout<<right<<setw(20)<<Players.at(player2pos).getft()<<endl;
  cout<< right<< setw(26) << "|";
  cout<< left<<setw(26) <<endl;
  cout<<left<<setw(15)<<Players.at(player1pos).getfta()<<"Free Throws Attempted";
  cout<<right<<setw(15)<<Players.at(player2pos).getfta()<<endl<<endl;
  cout<< right<< setw(26) << "|";
  cout<< left<<setw(26) <<endl;
  cout<<left<<setw(15)<<Players.at(player1pos).getftPercent()<<"Free Throw Percent";
  cout<<right<<setw(18)<<Players.at(player2pos).getftPercent()<<endl<<endl;
}


void compareRebounds(int player1pos,int player2pos)
{
  string name1 = Players.at(player1pos).getFname()+ " " + Players.at(player1pos).getLname();
  string name2 = Players.at(player2pos).getFname()+" "+Players.at(player2pos).getLname();

  cout<< left<< setw(25)  << name1<< "|";
  cout<< right<<setw(25) << name2 << endl;
  cout << setfill('-') << setw(52) << "" << endl;
  cout<<setfill(' ');
  cout<<left<<setw(15)<<Players.at(player1pos).getoff()<<"Offensive Rebounds";
  cout<<right<<setw(15)<<Players.at(player2pos).getoff()<<endl;
  cout<< right<< setw(26) << "|";
  cout<< left<<setw(26) <<endl;
  cout<<left<<setw(15)<<Players.at(player1pos).getdef()<<"Deffensive Rebounds";
  cout<<right<<setw(15)<<Players.at(player2pos).getdef()<<endl<<endl;
  cout<< right<< setw(26) << "|";
  cout<< left<<setw(26) <<endl;
  cout<<left<<setw(17)<<Players.at(player1pos).gettot()<<"Total Rebounds";
  cout<<right<<setw(18)<<Players.at(player2pos).gettot()<<endl<<endl;
  cout<< right<< setw(26) << "|";
  cout<< left<<setw(26) <<endl;
  cout<<left<<setw(16)<<Players.at(player1pos).getfavg()<<"Rebound Percentage";
  cout<<right<<setw(16)<<Players.at(player2pos).getfavg()<<endl<<endl;

}

void compareFouls(int player1pos, int player2pos)
{
  string name1 = Players.at(player1pos).getFname()+ " " + Players.at(player1pos).getLname();
  string name2 = Players.at(player2pos).getFname()+" "+Players.at(player2pos).getLname();


    cout<< left<< setw(25)  << name1<< "|";
    cout<< right<<setw(25) << name2 << endl;
    cout << setfill('-') << setw(52) << "" << endl;
    cout<<setfill(' ');
    cout<<left<<setw(18)<<Players.at(player1pos).getpf()<<"Personal Fouls";
    cout<<right<<setw(18)<<Players.at(player2pos).getpf()<<endl;
    cout<< right<< setw(26) << "|";
    cout<< left<<setw(26) <<endl;
    cout<<left<<setw(20)<<Players.at(player1pos).getfo()<<"Fouled out";
    cout<<right<<setw(20)<<Players.at(player2pos).getfo()<<endl<<endl;
}

void compareAssist_TO_BL_St(int player1pos, int player2pos)
{
  string name1 = Players.at(player1pos).getFname()+ " " + Players.at(player1pos).getLname();
  string name2 = Players.at(player2pos).getFname()+" "+Players.at(player2pos).getLname();

  cout<< left<< setw(25)  << name1<< "|";
  cout<< right<<setw(25) << name2 << endl;
  cout << setfill('-') << setw(52) << "" << endl;
  cout<<setfill(' ');
  cout<<left<<setw(22)<<Players.at(player1pos).getassist()<<"Assists";
  cout<<right<<setw(22)<<Players.at(player2pos).getassist()<<endl;
  cout<< right<< setw(26) << "|";
  cout<< left<<setw(26) <<endl;
  cout<<left<<setw(21)<<Players.at(player1pos).getto()<<"Turn Overs";
  cout<<right<<setw(20)<<Players.at(player2pos).getto()<<endl<<endl;
  cout<< right<< setw(26) << "|";
  cout<< left<<setw(26) <<endl;
  cout<<left<<setw(22)<<Players.at(player1pos).getblocks()<<"Blocks";
  cout<<right<<setw(23)<<Players.at(player2pos).getblocks()<<endl<<endl;
  cout<< right<< setw(26) << "|";
  cout<< left<<setw(26) <<endl;
  cout<<left<<setw(22)<<Players.at(player1pos).getsteals()<<"Steals";
  cout<<right<<setw(23)<<Players.at(player2pos).getsteals()<<endl<<endl;

}

void comparePoints(int player1pos,int player2pos)
{
  string name1 = Players.at(player1pos).getFname()+ " " + Players.at(player1pos).getLname();
  string name2 = Players.at(player2pos).getFname()+" "+Players.at(player2pos).getLname();


    cout<< left<< setw(25)  << name1<< "|";
    cout<< right<<setw(25) << name2 << endl;
    cout << setfill('-') << setw(52) << "" << endl;
    cout<<setfill(' ');
    cout<<left<<setw(23)<<Players.at(player1pos).getpts()<<"Points";
    cout<<right<<setw(23)<<Players.at(player2pos).getpts()<<endl;
}



int main() {



  statfile.open ("gonzaga.txt"); // opens file
  if(statfile.fail()){
    cout<<"File cannot be found or opened"<<endl; // alerts if cannot open

  }

  while(statfile.good()) // while file is open
  {
    getline(statfile,aline);
    lines.push_back(aline);// gets the line in file and puts them into a vector
      count++;
  }

for(int i =3; i < count;i++)
{
  if(i!=count-1){
  stats.clear();
}
  istringstream line_stream(lines.at(i)); //gets the strings in line and puts them into a vector

// populates the class with whats in the vector and then clears the vector when it gets a new line.
// and keepspopulating the vector of string while there is a line in he lines vector, each line is a new player.

  while(line_stream>>a)
  {
    stats.push_back(a);
  }

  player Player;
    Player.setNumber(stats.at(0));
    Player.setlname(stats.at(1));
    Player.setfname(stats.at(2));
    Player.setgamesplayed(stats.at(3));
    Player.setgamesstarted(stats.at(4));
    Player.setminutes(stats.at(5));
    Player.setaveragemin(stats.at(6));
    Player.setfg(stats.at(7));
    Player.setfga(stats.at(8));
    Player.setfgpercent(stats.at(9));
    Player.setthreefg(stats.at(10));
    Player.setthreefga(stats.at(11));
    Player.setthreefgpercent(stats.at(12));
    Player.setft(stats.at(13));
    Player.setfta(stats.at(14));
    Player.setftpercent(stats.at(15));
    Player.setoff(stats.at(16));
    Player.setdef(stats.at(17));
    Player.settotf(stats.at(18));
    Player.setfavg(stats.at(19));
    Player.setpf(stats.at(20));
    Player.setfo(stats.at(21));
    Player.setassist(stats.at(22));
    Player.setto(stats.at(23));
    Player.setblocks(stats.at(24));
    Player.setsteals(stats.at(25));
    Player.setpts(stats.at(26));
    Player.setAVG(stats.at(27));

    Players.push_back(Player);
} // end of for

statfile.close();
  cout<<"Gonzaga Bulldogs"<<endl<<endl;
  // do while loop for the menu, will execute as long as the player is in the roster and corect inputs are enters or as long
  // user does not enter 0;
do{

  cout<<"What would you like to compare (Enter a number)"<<endl; // asks for what you would like to compare

  cout<<"0) Quit"<<endl<<"1) Games"<<endl<<"2) Minutes"<<endl // menu
  <<"3) Field Goals"<<endl<<"4) 3 Pointers"<<endl<<"5 Free Throws"<<endl
  << "6) Rebounds"<<endl<<"7) Fouls"<<endl<< "8) Assists, Turn Overs, Blocks and steals"<<endl
  <<"9) Points"<<endl;
cout<<"Option: ";
cin>>input;

if(input>9) // checks for invalid input
{
  cout<<"Invalid input"<<endl;
  exit(1);
}


if(input ==0){
  break;
}
player1 =' ';

cout<<"Enter Number of player to compare: "; // gets player 1
cin>>player1;
playerfound1=false; // sets player found back to false

cout<<endl;
player2 = ' ';
cout<<"Enter number of player to compare to: "; // gerts player 2
cin>>player2;
playerfound2 = false; // sets playerfound2 back to false
cout<<endl<<endl;

for(int i=0;i<Players.size();i++) // checks for user in the player vector
{
  if(player1 == Players.at(i).getNumber())
  {
    player1pos =i;
    playerfound1 = true;
    break;
  }
  if(playerfound1==false&&i==Players.size()-1)
  {
    cout<<"Player1 does not exist"<<endl;
    exit(1);
  }

}// end of for

  for(int i=0;i<Players.size();i++)
  {

    if(player2 == Players.at(i).getNumber()) // checks for user in player vector
    {
      player2pos =i;
      playerfound2 =true; // if player is found sets to true
      break;
    }
    if(playerfound2==false && i == Players.size()-1)
    {
      cout<<"Player2 does not exist"<<endl;
      exit(1); // exits program if player not found
    }

  } // end of for

// if statements that will execute to the appropiate input from menu.
if(input ==1)
{
  compareGames(player1pos,player2pos);
}
else if(input ==2)
{
  compareMinutes(player1pos,player2pos);
}
else if(input ==3)
{
  compareFieldgoals(player1pos,player2pos);
}
else if(input ==4)
{
  compareThreePointers(player1pos,player2pos);
}
else if(input ==5)
{
  compareFreeThrows(player1pos,player2pos);
}
else if(input ==6)
{
  compareRebounds(player1pos,player2pos);
}
else if(input == 7)
{
  compareFouls(player1pos,player2pos);
}
else if(input== 8)
{
  compareAssist_TO_BL_St(player1pos,player2pos);
}
else if(input==9)
{
  comparePoints(player1pos,player2pos);
}

}while(input!=0);


  return 0;

}
