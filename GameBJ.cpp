#include "GameBJ.h"
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

}