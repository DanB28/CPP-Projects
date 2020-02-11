#ifndef DECK_H
#define DECK_H
#include "Card.h"
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <vector>

using namespace std;

class Deck
{
public:
  Deck();
  Card dealCard();
  void newDeck();
  int deckSize();
  void Shuffle();
private:

std::vector<Card>newdeck;
Card currentCard;
int newsize;
int random;
int j;

};

Deck::Deck()
{
string names[] = {"Ace","Two","Three","Four","Five","Six","Seven","Eight","Nine",
"Ten","Jack","Queen","King"};
string suits[] = {"Hearts","Diamonds","Hearts","Spades"};
int values[]={11,2,3,4,5,6,7,8,9,10,10,10,10};

newdeck.resize(52);
for(int count = 0; count <newdeck.size();count++)
newdeck.at(count) = Card(names[count % 13], suits[count/13],values[count%13]);

}

void Deck::newDeck()
{
  string names[] = {"Ace","Two","Three","Four","Five","Six","Seven","Eight","Nine",
  "Ten","Jack","Queen","King"};
  string suits[] = {"Hearts","Diamonds","Hearts","Spades"};

  int values[]={11,2,3,4,5,6,7,8,9,10,10,10,10};
  newdeck.resize(52);
  for(int count = 0; count< newdeck.size();count++)
  newdeck.at(count) = Card(names[count % 13], suits[count/13],values[count % 13]);
}

Card Deck::dealCard()
{

  if(0<newdeck.size()){
    currentCard = newdeck.at(0);
    for(int i =0; i<newdeck.size()-1;i++)
    {
      newdeck.at(i) = newdeck.at(i+1);
    }

    newsize = newdeck.size()-1;
    newdeck.resize(newsize);
    return(currentCard);

  }
}

int Deck::deckSize()
{
  return newdeck.size();
}

void Deck::Shuffle()
{

  int currentCard =0;
  for(int i =0; i<deckSize();i++ )
  {
    int j = (rand()+time(0)) % deckSize();
    Card temp = newdeck.at(i);
    newdeck.at(i) = newdeck.at(j);
    newdeck.at(j) = temp;
  }//end of for
}


#endif
