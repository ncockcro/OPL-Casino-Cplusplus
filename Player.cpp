#include "Player.h"


// Default constructor
Player::Player()
{
}

// Default destructor
Player::~Player()
{
}

/* *********************************************************************
Function Name: MakeMove
Purpose: For each player to make a move in a round
Parameters: None
Return Value: Void
Local Variables: None
Algorithm:
1) This is a virtual function so the actualfunction is used in the child classes
Assistance Received: none
********************************************************************* */
void Player::MakeMove() {
}

/* *********************************************************************
Function Name: SetHand
Purpose: At the beginning of a round and when the players run out of cards, this function deals four cards to them
Parameters:
fourCards, a vector of cards passed by value. It holds the four cards to be added to a players hand
Return Value: Void
Local Variables: None
Algorithm:
1) Go through the deck of 52 cards and the four cards passed in
2) If the cards that were passed in match any of the cards in the deck, the card will be pushed to the players hand
Assistance Received: none
********************************************************************* */
void Player::SetHand(vector<Card> fourCards) {

		hand.push_back(fourCards[0]);
		hand.push_back(fourCards[1]);
		hand.push_back(fourCards[2]);
		hand.push_back(fourCards[3]);

}

/* *********************************************************************
Function Name: IsEmpty
Purpose: To check if a player's hand is empty
Parameters: None
Return Value: Returns true if the player's hand is empty, false otherwise, a boolean value
Local Variables: None
Algorithm:
1) If the hand vector is empty, return true
2) Otherwise, return false
Assistance Received: none
********************************************************************* */
bool Player::IsEmpty() {

	if (hand.empty()) {
		return true;
	}
	else {
		return false;
	}
}

/* *********************************************************************
Function Name: GetHand
Purpose: Return a player's hand
Parameters: None
Return Value: The player's hand, a constant vector of cards value
Local Variables: None
Algorithm:
1) Return the player's hand
Assistance Received: none
********************************************************************* */
const vector<Card> Player::GetHand() {
	return hand;
}

/* *********************************************************************
Function Name: GetPlayerCard
Purpose: To return the card the player want to use for either a build or capture
Parameters: None
Return Value: The player's card for a build or capture, a constant card value
Local Variables: None
Algorithm:
1) Return the player's card for a build or capture
Assistance Received: none
********************************************************************* */
const Card Player::GetPlayerCard() {
	return playerCard;
}

/* *********************************************************************
Function Name: GetBuildCards
Purpose: To retrieve the cards a player wants to use for a build
Parameters: None
Return Value: The build cards, a vector of cards value
Local Variables: None
Algorithm:
1) Return the cards used for a build
Assistance Received: none
********************************************************************* */
const vector<Card> Player::GetBuildCards(){
	return buildCards;
}

/* *********************************************************************
Function Name: GetNewOrExistingBuild
Purpose: To retrieve the indicator if the user wants to make a new or add to existing build
Parameters: None
Return Value: The string indicating new or existing build, a char value
Local Variables: None
Algorithm:
1) Return the char indicating a new or existing build
Assistance Received: none
********************************************************************* */
const char Player::GetNewOrExistingBuild() {
	return newOrExistingBuild;
}

/* *********************************************************************
Function Name: GetExistingBuildCard
Purpose: To retrieve the card of a build the human wants to add to
Parameters: None
Return Value: The card from an existing build, a card value
Local Variables: None
Algorithm:
1) Return the card of an existing build
Assistance Received: none
********************************************************************* */
const Card Player::GetExistingBuildCard() {
	return existingBuildCard;
}

/* *********************************************************************
Function Name: GetPlayerMove
Purpose: To retrieve the move that the player wants to make (build, capture, or trail
Parameters: None
Return Value: The character of the move the player want to make, a char value
Local Variables: None
Algorithm:
1) Return the playerMove variable
Assistance Received: none
********************************************************************* */
const char Player::GetPlayerMove() {
	return playerMove;
}

/* *********************************************************************
Function Name: RemoveCard
Purpose: To remove a specific card from a player's hand
Parameters:
card, a card passed by value. It holds the card to be removed
Return Value: The average grade in the class, a real value
Local Variables: None
Algorithm:
1) Iterate through a player's hand and if the card passed in matches with one of the cards
2) Remove the card
Assistance Received: none
********************************************************************* */
void Player::RemoveCard(Card card) {
	bool notFound = false;
	for (size_t i = 0; i < hand.size(); i++) {
		if (hand[i].GetCard() == card.GetCard()) {
			hand.erase(hand.begin() + i);
			notFound = true;
		}
	}

	if (notFound == false) {
		cerr << "Error in removing a card in the player class." << endl;
	}
}

/* *********************************************************************
Function Name: SetPile
Purpose: Given a pile of cards, set that to a player
Parameters:
passedPile, a vector of cards passed by value. It holds the cards to be set to the pile
size, an integer. It refers to the number of students in the class
Return Value: Void
Local Variables:
count, an integer used for tracking if all the cards in a pile are actual cards in a deck
Algorithm:
1) Iterate through all 52 cards in a deck and the cards in the passed pile
2) If there is a match, increment the counter
3) If the count in the end matches the size of the passed cards, then set the pile equal to the passed pile
Assistance Received: none
********************************************************************* */
void Player::SetPile(vector<Card> passedPile) {
	int count = 0;
	for (size_t i = 0; i < uniqueCards.size(); i++) {
		for (size_t j = 0; j < passedPile.size(); j++) {
			if (uniqueCards[i].GetCard() == passedPile[j].GetCard()) {
				count++;
			}
		}
	}

	if (count == passedPile.size()) {
		pile = passedPile;
	}
}

/* *********************************************************************
Function Name: AddToPile
Purpose: To add a certain amount of cards to a player's pile
Parameters:
passedPile, a vector of cards passed by value. It holds the pile to be added to a player's existing pile
Return Value: Void
Local Variables: None
Algorithm:
1) Iterate through the 52 cards deck and through the passed in pile
2) If there is a match, add the card to the existing pile
Assistance Received: none
********************************************************************* */
void Player::AddToPile(vector<Card> passedPile) {
	
	for (int i = 0; i < uniqueCards.size(); i++) {
		for (size_t j = 0; j < passedPile.size(); j++) {
			if (uniqueCards[i].GetCard() == passedPile[j].GetCard()) {
				pile.push_back(passedPile[j]);
			}
		}
	}
}

/* *********************************************************************
Function Name: GetPile
Purpose: To retrieve a player's pile
Parameters: None
Return Value: The pile of a players pile, a constant vector of cards value
Local Variables: None
Algorithm:
1) Returns a player's pile
Assistance Received: none
********************************************************************* */
const vector<Card> Player::GetPile() {
	return pile;
}

/* *********************************************************************
Function Name: PrintPile
Purpose: To print out a player's pile to the console
Parameters: None
Return Value: Void
Local Variables: None
Algorithm:
1) Iterate through a player's pile and print each card to the screen
Assistance Received: none
********************************************************************* */
void Player::PrintPile() {
	for (size_t i = 0; i < pile.size(); i++) {
		cout << pile[i].GetCard() << " ";
	}
	cout << endl;
}

/* *********************************************************************
Function Name: GetPlayerWantSet
Purpose: To retrieve the character indicating if a player wants to make a set or not
Parameters: None
Return Value: The character either being 'y' or 'n', a constant char value
Local Variables: None
Algorithm:
1) Return the playerWantSet variable
Assistance Received: none
********************************************************************* */
const char Player::GetPlayerWantSet() {
	return playerWantSet;
}

/* *********************************************************************
Function Name: MakeSet
Purpose: Has the user enter more kids for capturing a set
Parameters: None
Return Value: The cards being used for a set, a vector of cards value
Local Variables:
userInput, an string used to get user input
count, an int for keeping track of how many cards they entered
Algorithm:
1) Prompt the user to enter two cards used for a set
2) Return the value to be used in another function
Assistance Received: none
********************************************************************* */
vector<Card> Player::MakeSet() {
	string userInput;
	int count = 0;

	do {
		cout << "Enter the two cards that make up a set for you to capture (Type a card and hit enter): ";
		cin >> userInput;

		if (CheckCard(userInput)) {
			setCards.push_back(Card());
			setCards[count].SetCard(userInput);
			count++;
		}

	} while (count < 2);

	return setCards;
}

/* *********************************************************************
Function Name: CheckCard
Purpose: Takes a card in as input and checks to see if it is one of the 52 in a deck
Parameters: None
Return Value: True if the card is valid, false otherwise, a boolean value
Local Variables:
validCard, a boolean for tracking if a card is valid or not
count, an int for keeping track of how many cards they entered
Algorithm:
1) Iterate through the 52 card deck and see if the passed in card matches one of them
2) If it does, return true, otherwise, return false
Assistance Received: none
********************************************************************* */
bool Player::CheckCard(string card) {

	bool validCard = false;

	for (size_t i = 0; i < uniqueCards.size(); i++) {
		if (uniqueCards[i].GetCard() == card) {
			validCard = true;
		}
	}

	return validCard;
}