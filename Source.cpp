//Name: Tyler Peaster
//Start Date: 1/2/2023

/*
C++ Console Blackjack Program
Still early in dev

Small Personal Goals for Program:
Break habit of over-use of "using namespace blah blah"
More consistent use of abstraction
More consistent "UI", make it feel a little nicer than just plain old console
Break habit of using endl when not needed, just use \n

Maybe add?:
Based upon a single standard deck,
maybe add option to use a six-deck shuffle like most casinos?

*/
#include "Cards.h"
#include "GameBJ.h"
#include "Global.h"

#include <iostream>
#include <vector>
#include <string>

class StartUp
{
public:
	void menu()
	{
		separatorUI();
		colorText("brightCyan", "Blackjack");
		separatorUI();
		colorText("cyan", "Credits:");
		std::cout << "\n";
		colorText("cyan", "Creator -- Tyler Peaster");
		separatorUI();
		
		std::cout << "\n\n";

		separatorUI();
		std::cout << "Press Enter to Start!\n";
		std::getline(std::cin, tempS);
	}

private:
	int start{};
	std::string tempS;
};

int main()
{
	StartUp start;
	std::vector <std::string> deckOfCards, shuffledDeck;
	Blackjack bj;

	while (1)
	{
		//preparing the deck
		start.menu();
		deckOfCards = createDeckOfCards();
		shuffledDeck = shuffleDeckOfCards(deckOfCards);

		//the game
		bj.startBlackjackGame(shuffledDeck);
	}
}