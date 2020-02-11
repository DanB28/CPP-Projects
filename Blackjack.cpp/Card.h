#ifndef CARD_H
#define CARD_H
#include <string>
#include <iostream>

using namespace std;

class Card
{
public:
  Card();
  Card(string cardName, string cardSuit, int cardValue);
  void printCard();
  string getName();
  string getSuit();
  int getValue();


private:
  string name;
  string suit;
  int value;

};
Card::Card()
{
}

Card::Card(string cardName,string cardSuit, int cardValue)
{
  name = cardName;
  suit = cardSuit;
  value = cardValue;
}

void Card::printCard()
{
  cout<<name + " of " + suit<<endl;
}
string Card::getName()
{
  return name;
}
string Card::getSuit()
{
  return suit;
}

int Card::getValue()
{
  return value;
}

#endif
