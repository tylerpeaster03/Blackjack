#include "GameBJ.h"
#include "Global.h"

#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>

void Blackjack::startBlackjackGame(std::vector <std::string> deckOfCardsPassed, int numberOfPlayers)
{
	/*
	Deal from the dealer's left to right (start with the player to your far left.) 
	Deal one up card to each player, followed by a down card to the dealer. 
	Then deal a second up card to each player, followed by the dealer's up card. 
	Make sure the cards are laid out diagonally so that both numbers on each card are visible.

	Remember to reset all vars to allow multiple games
	*/

	//background processes
	cardID = 0;
	deckOfCards = deckOfCardsPassed;
	playerCount = numberOfPlayers;
	giveAllEntitiesCards();	//first pass of cards
	giveAllEntitiesCards(); //second pass of cards

	//delays and hidden cards for visual flair
	clearScreen();

	separatorUI();
	colorText("brightRed", "Dealer: ");
	std::cout << "No cards dealt\n";

	colorText("brightBlue", "Players: ");



	std::this_thread::sleep_for(std::chrono::milliseconds(500));
}

void Blackjack::giveAllEntitiesCards()
{
	if (playerCount >= 1)
		giveCard(pCards1);
	if (playerCount >= 2)
		giveCard(pCards2);
	if (playerCount >= 3)
		giveCard(pCards3);
	if (playerCount >= 4)
		giveCard(pCards4);
	if (playerCount >= 5)
		giveCard(pCards5);
	if (playerCount >= 6)
		giveCard(pCards6);
	if (playerCount >= 7)
		giveCard(pCards7);

	giveCard(dealerCards);
}

void Blackjack::giveCard(std::vector <std::string> pCards)
{
	tempS = deckOfCards[cardID];
	pCards.push_back(tempS);
	cardID++;
}

void Blackjack::showCardUp(std::vector <std::string> entityCards, int num)
{
	
}