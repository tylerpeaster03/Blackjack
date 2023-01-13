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
	reset();
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

void Blackjack::reset()
{
	deckOfCards.clear();
	playerCards.clear();
	dealerCards.clear();
	pointsOfPlayer.clear();
	pointsOfDealer.clear();
	cardID = 0;
	totalPoints = 0;
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
	Rules for splitting hands

	It is possible to Split twice within one hand. Say you are originally dealt a 10 and a Jack, 
	and you choose to Split. You now have two hands in play (10 & J). If the next card you are dealt on your 10 is a Queen, 
	you have the option to Split again. You now have three hands in play, all showing equal value (10, J, & Q).

	However, it is not possible to Split again from a hand that was already split. 
	That means that the hands showing 10 and Queen must be played; your options will be Hit, Stand, and Double Down. 
	However, the Jack hand has still only been split once. If a King comes up on the Jack, you will have the option to Split again. 
	If you Split on two Aces, no further splits are allowed. 
	A Split on two Aces acts similarly to a Double Down in that only one card will be added to each half of the split hand.
	*/
	totalPoints = 0;

	for (int i = 0; i < points.size(); i++)
		totalPoints += points[i];

	for (int i = 0; i < points.size(); i++)
	{
		for (int j = 0; j < points.size(); j++)
		{
			if (points[i] == points[j])
			{
				//check for split
			}
		}
	}

	if (totalPoints < 21)
		return 'c';
	else if (totalPoints == 21)
		return 'b';
	else if (totalPoints > 21)
		return 'l';

}