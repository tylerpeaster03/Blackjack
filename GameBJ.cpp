#include "GameBJ.h"
#include "Cards.h"
#include "Global.h"

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

void Blackjack::startBlackjackGame(std::vector <std::string> deckOfCardsPassed, int deckAmount)
{
	/*
	Deal from the dealer's left to right (start with the player to your far left.) 
	Deal one up card to each player, followed by a down card to the dealer. 
	Then deal a second up card to each player, followed by the dealer's up card. 
	Make sure the cards are laid out diagonally so that both numbers on each card are visible.
	*/

	//Background Processes
	amountOfDecks = deckAmount;
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
	allowSplit = false;
	allowAceSplit = false;
	hasHit = false;
}

std::vector <std::string> Blackjack::addCard(std::vector <std::string> playerOrDealerDeck)
{
	playerOrDealerDeck.push_back("");
	playerOrDealerDeck[playerOrDealerDeck.size() - 1] = deckOfCards[cardID];
	cardID++;

	return playerOrDealerDeck;
}

void Blackjack::menu()
{
	/*
	Hold -- ALways Option, can no longer hit after hold
	Hit -- Always Option
	Double Down -- Only if player hasn't hit
	Split -- Only if player gets two indentical cards.
	Split -- Can be done up to FOUR times.

	If player hits blackjack, game must automatically end with a win
	If player gets above 21, game must automatically end with a loss
	If player and dealer have the same amount of cards, a push (tie) happens

	The dealer does not have the option of splitting or doubling down
	*/

	 
	while (1)
	{
		pointsOfDealer = createPoints(dealerCards);
		gameStateDealer = pointsCheck(pointsOfDealer);

		//Visual Menu Begins
		//-------------------------------------
		clearScreen();
		amountOfDeckMessage();

		//Dealer
		//-------------------------------------
		separatorUI();
		colorText("brightRed", "Dealer:");
		std::cout << "\n\n";
		colorText("cyan", "THIS CARD IS FLIPPED");
		std::cout << "\n";

		for (int i = 1; i < dealerCards.size(); i++)
		{
			autoDisplayColorForCard(dealerCards[i]);
			std::cout << "\n";
		}
		//-------------------------------------


		//Player
		//-------------------------------------
		separatorUI();
		colorText("brightBlue", "Player: ");
		std::cout << "\n\n";

		for (int i = 0; i < playerCards.size(); i++)
		{
			autoDisplayColorForCard(playerCards[i]);
			std::cout << "\n";
		}

		/*
		Split Decks Display
		*/

		//-------------------------------------

		separatorUI();
		if (gameStateDealer == 'l' && gameStatePlayer == 'l' || gameStateDealer == 'b' && gameStatePlayer == 'b')
		{
			std::cout << "\nIt's a Push!\n";
			separatorUI();
			break;
		}
		if (gameStateDealer == 'l')
		{
			std::cout << "\nDealer busted!\n";
			separatorUI();
			break;
		}
		if (gameStateDealer == 'b')
		{
			std::cout << "\nDealer got Blackjack!\n";
			separatorUI();
			break;
		}
		if (gameStatePlayer == 'l')
		{
			std::cout << "\nPlayer busted!\n";
			separatorUI();
			break;
		}
		if (gameStatePlayer == 'b')
		{
			std::cout << "\nPlayer got Blackjack!\n";
			separatorUI();
		}

		//-------------------------------------
		// Player Menu

		//Always Options
		std::cout
			<< "H --- Hit\n"
			<< "S --- Stand\n";
			
		//Conditional Options
		if (hasHit == false)
			std::cout << "DD -- Double Down\n";
		if (allowSplit == true || allowAceSplit == true)
			std::cout << "SP -- Split\n";

	menuStart:
		std::getline(std::cin >> std::ws, choice);	//didn't get to test

		if (choice == "H" || choice == "h")
		{
			hasHit == true;
		}
		else if (choice == "S" || choice == "s")
		{

		}
		else if (choice == "DD" || choice == "dd" || choice == "Dd" || choice == "dD")
		{
			if (hasHit == true)
			{
				std::cout << "\nInvalid Input!\n";
				goto menuStart;
			}
		}
		else if (choice == "SP" || choice == "sp" || choice == "Sp" || choice == "sP")
		{
			if (allowSplit == true || allowAceSplit == true)
			{

			}
			else
				goto menuStart;
		}
		else
		{
			std::cout << "\nInvalid Input!\n";
			goto menuStart;
		}

		/*
		Player can keep hitting until they either bust, stand, or Blackjack
		*/

		//-------------------------------------

		
		dealerAi();	//This needs to go after player makes hit/stand/etc option
	}
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
				if (points[i] == 1 || points[i] == 10)
					allowAceSplit = true;
				else
				{
					allowSplit = true;
					cardThatAllowsSplit1 = playerCards[i];
					cardThatAllowsSplit2 = playerCards[j];
				}
			}
		}
	}

	if (totalPoints > 21)
	{
		for (int i = 0; i < points.size(); i++)
		{
			if (points[i] == 11)
				totalPoints -= 10;
		}
	}

	if (totalPoints < 21)
		return 'c';
	else if (totalPoints == 21)
		return 'b';
	else if (totalPoints > 21)
		return 'l';
}

void Blackjack::dealerAi()
{
	totalPoints = 0;
	for (int i = 0; i < pointsOfDealer.size(); i++)
		totalPoints += pointsOfDealer[i];

	if (totalPoints < 17)
	{
		dealerCards = addCard(dealerCards);
	}
}

void Blackjack::amountOfDeckMessage()
{
	if (amountOfDecks == 1)
		std::cout << "Home Style -- 1 Deck";
	else if (amountOfDecks == 6)
		std::cout << "Casino Style -- 6 Decks";
	else
		std::cout << "Custom Style -- " << amountOfDecks << " Decks";
}