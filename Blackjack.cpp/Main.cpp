#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "Card.h"
#include "Deck.h"
#include <fstream>

using namespace std;

int main(){

  Deck d1;
  Card player;
  Card dealer;
  ofstream myfile;

  myfile.open("BJdata.txt",ios::app);

  int balance = 0;
  char input = ' ';
  int bet = 0;
  int dealerTotal = 0;
  int playerTotal = 0;
  //int count = 0;
  int winnings = 0;
  int shufcount =0;
  bool pAce = false;
  bool dAce = false;
  int totalBet = 0;
  int totalLoss = 0;
  int totalwon = 0;
  int gamesWon =0;
  int gamesLost =0;


d1.newDeck();
d1.Shuffle();
  cout<<"**********************"<<endl;
  cout<<"Welcome to Blackjack"<<endl;
  cout<<"**********************"<<endl;

  cout<<endl;
  cout<<"Enter amount of money in chips: $";
  cin>>balance;
  cout<<endl;
  while(balance<=0)
  {
    balance=1;
    cout<<"You must Deposite an amount greater than zero"<<endl;
    cout<<"Please Enter an Amount: $";
    cin>>balance;
  }


do {


  cout<<"Your balance is: $"<<balance<<endl;

  if(balance <=0)
  {
    cout<<"You are out of money, Thank you for playing"<<endl;
    input = 'q';
    break;
  }// end of if

  cout<<"Place Your bet: $";
  cin>>bet;

  while(bet>balance || bet<=0)
  {

    if(bet<=0)
    {
      bet =1;
      cout<<"Bets must be more than $0.00."<<endl;
      cout<<"Please Re-Enter bet: $";
      cin>>bet;
    }
    else
    {
      bet = balance;
    cout<<"You cant bet more then your balance of $"<<balance<<endl;
    cout<<" please re-enter bet or enter 0 to exit"<<endl;
    cout<<"Bet: $";
    cin>>bet;
    if(bet==0)
    {
      input='q';
      break;
    }// end of if
  }// end of else
}// end of while

  if(input =='q')
  {
    break;
  }
  cout<<"**************************************************"<<endl;
  cout<<"Dealers Hand"<<endl;
  cout<<endl;
  dealerTotal=0;
  dealer = d1.dealCard();
  dealer.printCard();
  if(dealer.getValue()==11)
  {
    dAce = true;
  }
  dealerTotal = dealerTotal + dealer.getValue();
  dealer = d1.dealCard();
  dealerTotal = dealerTotal + dealer.getValue();

  cout<<endl;
  cout<<"**************************************************"<<endl;

  cout<<"Your Hand"<<endl;
  cout<<endl;
  //card one
  playerTotal=0;

  player = d1.dealCard();
  player.printCard();
  if(player.getValue()==11)
  {
    pAce = true;

  }
  playerTotal = playerTotal + player.getValue();
  //card two
  player = d1.dealCard();
  player.printCard();
  if(player.getValue()==11)
  {
    pAce = true;

  }
  playerTotal = playerTotal + player.getValue();

  if(playerTotal == 21)
  {
    if(dealerTotal == 21)
    {
      cout<<"You and the dealer both got a BLACKJACK. . Its a push"<<endl;
    }// end of if
    else{
    winnings = bet*1.5;
    totalwon = totalwon + winnings;
    gamesWon++;
    cout<<"BLACKJACK!! You Win $"<<winnings<<endl;
    balance = balance + winnings;
    cout<<"Balance $"<<balance<<endl;
    myfile<<"Blackjack"<<endl; // write to file
    input = ' ';
    break;
  }// end of else

  }// end of if

  cout<<"Would you like to HIT (h) or STAY (s): ";
  cin>>input;

  while(input == 'h' && playerTotal<=21)
  {

    input = 's';
    player = d1.dealCard();
    cout<<endl;
    player.printCard();
    if(player.getValue()==11)
    {
      pAce = true;
    }
    playerTotal = playerTotal + player.getValue();
    if(playerTotal>21)
    {
      if(pAce ==true) //if you bust with an ace changes the  value to one.
      {
        playerTotal = (playerTotal-10);
        pAce=false; // changes back to false after ace is changed
      }// end of if

      if(playerTotal>21)
      {
        cout<<playerTotal<<" You Bust!!"<<endl;
        cout<<endl;
        balance = balance - bet;
        cout<<"DEALER WINS"<<endl;
        totalLoss = totalLoss +bet;
        gamesLost++;
        myfile<<"DealerWin"<<endl;
        break;
      }//end of else

    }// end of if
    cout<<endl;
    cout<<"Card Total: "<<playerTotal<<endl;
    cout<<"HIT (h) or STAY (s): ";
    cin>>input;
} // end while


cout<<endl;
cout<<"**************************************************"<<endl;
if(input =='s' && playerTotal<=21)
{
cout<<"Dealers Turn"<<endl;
cout<<endl;
cout<<"Flipped Card: ";
dealer.printCard(); // displays dealers second card
cout<<endl;

while(dealerTotal<17)
{
dealer = d1.dealCard();
dealer.printCard();
if(dealer.getValue()==11)
{
  dAce = true;
}// end of if
dealerTotal = dealerTotal + dealer.getValue();

if(dealerTotal>21)
{
  if(dAce ==true)
  {
  dealerTotal = dealerTotal - 10;
  dAce = false;
}// end of if
}// end of else if


}// end of while
}//end if

cout<<endl;

if(dealerTotal>playerTotal && dealerTotal<=21)
{
cout<<endl;
cout<<"**************************************************"<<endl;
cout<<endl;
cout<<"DEALER WINS"<<endl;
totalLoss = totalLoss + bet;
gamesLost++;
myfile<<"DealerWin"<<endl;
cout<<endl;
cout<<"Dealer's Hand value: "<<dealerTotal<<endl;
cout<<"Your Hand Value: "<<playerTotal<<endl;
balance = balance - bet; // lost bet
cout<<endl;
cout<<"You Lost $"<<bet<<endl;
cout<<"Your remaining balance is $"<<balance<<endl;
cout<<"**************************************************"<<endl;
cout<<endl;

}// end if

else if(dealerTotal == playerTotal)
{
  cout<<"Push! Its a draw!"<<endl;
  myfile<<"Push"<<endl;
}// else if

else if(playerTotal > dealerTotal && playerTotal<=21)
{
  winnings = bet;
  balance = balance + winnings;
  cout<<"**************************************************"<<endl;
  cout<<"You Beat the Dealer!! You Win $"<<winnings<<endl;
  gamesWon++;
  totalwon = totalwon + winnings;
  myfile<<"PlayerWin"<<endl;
  cout<<endl;
  cout<<"Your New Balance is $"<<balance<<endl;
  cout<<"**************************************************"<<endl;
  cout<<endl;
}// end of else if


else if(dealerTotal>21)
{
  cout<<endl;
  winnings = bet;
  cout<<"**************************************************"<<endl;
  cout<<"The Dealer Busts"<<endl;
  cout<<"You win $ "<<winnings<<endl;
  myfile<<"PlayerWin"<<endl;
  gamesWon++;
  totalwon =totalwon+winnings;
  balance = balance + winnings;
  cout<<endl;
  cout<<"Your New Balance is: $"<<balance<<endl;
  cout<<"**************************************************"<<endl;

}// end of else if
// cout<<d1.deckSize()<<endl; // this printed the deck size to make sure it worked correctly
cout<<"Play Another Round? (y,n) ";
cin>>input;

while(input!='y'&& input != 'n')
{
  input ='n';
  cout<<"Please enter y or n, enter n to quit."<<endl;
  cin>>input;
}
if(input =='n')
{
  input='q';
}// end if

else
{
  if(d1.deckSize()<=20 && shufcount ==0) // shuffles deck if it has 20  or less cards
  {
  d1.Shuffle();
  shufcount =1;
    input = ' ';
  }

  else if(d1.deckSize()<=5) // creates a new deck if deck  count gets below 5
  {
  d1.newDeck();
  d1.Shuffle();
  }

  else
  {
    pAce = false; // sets aces back to false
    dAce = false;
    input = ' ';
}
}  // end of else

}while(input!='q'); // end of do while // plays until player quits
cout<<endl;
cout<<"*******STATS*********"<<endl;
cout<<"Total Games Played: "<<gamesWon+gamesLost<<endl;
cout<<"Total Games Won: "<<gamesWon<<endl;
cout<<"Total games Lost: "<<gamesLost<<endl;
cout<<"Total Money Won: $"<<totalwon<<endl;
cout<<"Total Money Lost: $"<<totalLoss<<endl;

  return 0;
}
