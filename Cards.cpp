#include "Cards.h"
#include "Global.h"

#include <string>
#include <vector>
#include <algorithm>
#include <random>

std::vector <std::string> createDeckOfCards()
{
	std::vector <std::string> deckOfCards =
	{
		"2  of SPADES",
		"3  of SPADES",
		"4  of SPADES",
		"5  of SPADES",
		"6  of SPADES",
		"7  of SPADES",
		"8  of SPADES",
		"9  of SPADES",
		"10 of SPADES",
		"J  of SPADES",
		"Q  of SPADES",
		"K  of SPADES",
		"A  of SPADES",

		"2  of DIAMONDS",
		"3  of DIAMONDS",
		"4  of DIAMONDS",
		"5  of DIAMONDS",
		"6  of DIAMONDS",
		"7  of DIAMONDS",
		"8  of DIAMONDS",
		"9  of DIAMONDS",
		"10 of DIAMONDS",
		"J  of DIAMONDS",
		"Q  of DIAMONDS",
		"K  of DIAMONDS",
		"A  of DIAMONDS",

		"2  of CLUBS",
		"3  of CLUBS",
		"4  of CLUBS",
		"5  of CLUBS",
		"6  of CLUBS",
		"7  of CLUBS",
		"8  of CLUBS",
		"9  of CLUBS",
		"10 of CLUBS",
		"J  of CLUBS",
		"Q  of CLUBS",
		"K  of CLUBS",
		"A  of CLUBS",

		"2  of HEARTS",
		"3  of HEARTS",
		"4  of HEARTS",
		"5  of HEARTS",
		"6  of HEARTS",
		"7  of HEARTS",
		"8  of HEARTS",
		"9  of HEARTS",
		"10 of HEARTS",
		"J  of HEARTS",
		"Q  of HEARTS",
		"K  of HEARTS",
		"A  of HEARTS"
	};

	 return deckOfCards;
}

std::vector <std::string> shuffleDeckOfCards(std::vector <std::string> deckOfCards)
{
	std::mt19937 rng;
	rng.seed(std::random_device()());

	std::shuffle(deckOfCards.begin(), deckOfCards.end(), rng);

	return deckOfCards;
}

std::vector <int> createPoints(std::vector <std::string> deckOfCards)
{
	std::vector <int> pointsOfDeck;
	int tempI{};
	std::string tempS;

	for (int i = 0; i < deckOfCards.size(); i++)
	{
		tempS = deckOfCards[i][0];

		if (tempS == "1")
			pointsOfDeck.push_back(10);
		else if (tempS == "J" || tempS == "Q" || tempS == "K")
			pointsOfDeck.push_back(10);
		else if (tempS == "A")	//Ace will always be assigned 11 points, but a later function will subtract 10 if a player goes >21 with Ace
			pointsOfDeck.push_back(11);
		else
		{
			tempI = std::stoi(tempS);
			pointsOfDeck.push_back(tempI);
		}
	}

	return pointsOfDeck;
}