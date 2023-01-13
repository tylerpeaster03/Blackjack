#include "GameBJ.h"
#include "Cards.h"
#include "Global.h"

#include <iostream>
#include <string>
#include <vector>

void Blackjack::startBlackjackGame(std::vector <std::string> deckOfCardsPassed)
{
	/*
	Deal from the dealer's left to right (start with the player to your far left.) 
	Deal one up card to each player, followed by a down card to the dealer. 
	Then deal a second up card to each player, followed by the dealer's up card. 
	Make sure the cards are laid out diagonally so that both numbers on each card are visible.
	*/

	//Background Processes
	clearScreen();
	deckOfCards = deckOfCardsPassed;

	//THIS ORDER IS VERY IMPORTANT, FOLLOWS BLACKJACK RULES
	//-------------------------------------
	playerCards = addCard(playerCards);
	dealerCards = addCard(dealerCards);

	playerCards = addCard(playerCards);
	dealerCards = addCard(dealerCards);
	//-------------------------------------

	displayTheFirstCardsPassed();
	menu();
}

std::vector <std::string> Blackjack::addCard(std::vector <std::string> playerOrDealerDeck)
{
	playerOrDealerDeck.push_back("");
	playerOrDealerDeck[playerOrDealerDeck.size() - 1] = deckOfCards[cardID];
	cardID++;

	return playerOrDealerDeck;
}

void Blackjack::displayTheFirstCardsPassed()
{
	separatorUI();
	colorText("brightRed", "Dealer:");
	std::cout << "\n\n";
	colorText("cyan", "THIS CARD IS FLIPPED");
	std::cout << "\n";
	autoDisplayColorForCard(dealerCards[1]);

	separatorUI();
	colorText("brightBlue", "You: ");
	std::cout << "\n\n";

	autoDisplayColorForCard(playerCards[0]);
	std::cout << "\n";
	autoDisplayColorForCard(playerCards[1]);
	std::cout << "\n\n";
}

void Blackjack::menu()
{
	/*
	Hold -- ALways Option
	Hit -- Always Option
	Double Down -- Only if player hasn't hit
	Split -- Only if player gets two indentical cards.
	Split -- Can be done up to FOUR times.

	If player hits blackjack, game must automatically end with a win
	If player gets above 21, game must automatically end with a loss
	If player and dealer have the same amount of cards, a push (tie) happens
	*/

	 pointsOfDealer = createPoints(dealerCards);
	 pointsOfPlayer = createPoints(playerCards);
	 gameStateDealer = pointsCheck(pointsOfDealer);
	 gameStatePlayer = pointsCheck(pointsOfPlayer);
}

char Blackjack::pointsCheck(std::vector <int> points)
{
	/*
	Reminder for me:
	Return 
	'c' for continuing without a winner or loser (both are below 21)
	'w' for player win
	'l' for player loss
	'p' for push (tie)
	you don't need a variable just return raw 'c', 'w', etc
	*/

	/*
	if (win)
	return 'w'
	else if (loss)
	return 'l'
	etc
	*/

	//placeholder
	return 'c';
}