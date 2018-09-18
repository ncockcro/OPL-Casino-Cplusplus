#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <vector>
#include "Card.h"
#include "Deck.h"

using namespace std;

/*
Joseph Allen, in CMPS 366-01, helped answer some questions about inheritance and how it works for me.
I showed him some parts of my code such as the MakeMove() function in the player class as well as in
the human class so he can have an understanding of what I was trying to do and how he could explain it
to me. He looked at my code but I did not look at his.
*/

class Player
{
public:
	// Public functions
	Player();
	~Player();
	virtual void MakeMove(); // Virtual function so both types of players can share certain moves
	void SetHand(vector<Card> fourCards);
	bool IsEmpty();
	vector<Card> GetHand() const;
	Card GetPlayerCard() const;
	vector<Card> GetBuildCards() const;
	char GetNewOrExistingBuild() const;
	Card GetExistingBuildCard() const;
	char GetPlayerMove() const;
	void RemoveCard(Card card);

	void SetPile(vector<Card> passedPile);
	void AddToPile(vector<Card> passedPile);
	vector<Card> GetPile() const;
	void AddToPlayerBuildCards(Card buildCard);
	vector<Card> GetPlayerBuildCards() const;
	void PrintPile();
	char GetPlayerWantBuild() const;
	char GetPlayerWantSet() const;
	vector<Card> MakeSet();


protected:
	// Current hand and pile of the player
	vector<Card> hand;
	vector<Card> pile;
	vector<Card> playerBuildCards;

	Deck deck = Deck();
	vector<Card> uniqueCards = deck.GetDeck();

	Card playerCard;
	vector<Card> buildCards;
	char newOrExistingBuild;
	Card existingBuildCard;
	char playerMove;
	char playerWantBuild;
	char playerWantSet;
	vector<Card> setCards;
	bool CheckCard(string card);

private:
	// Private functions


	// Private variables

};

#endif