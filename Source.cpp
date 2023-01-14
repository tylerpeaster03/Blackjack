//Name: Tyler Peaster
//Start Date: 1/2/2023

/*
C++ Console Blackjack Program

Small Personal Goals for Program:
Break habit of over-use of "using namespace blah blah"
More consistent use of abstraction
More consistent "UI", make it feel a little nicer than just plain old console
Break habit of using endl when not needed, just use \n

Add:
--How to Play section (Either in menu OR in home page)
--Home Style that shuffles one deck
--Casino Style that shuffles multiple decks together
(
	Current Idea: 
	Shuffle Deck 
	After each shuffle, add to a "full five deck" vector
	Rinse Repeat 6 times
	Then, shuffle the big 6 deck vector
	Boom Shaka Laka
)
--Custom Style that allows for between 1 and 8 decks
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

		//PLACEHOLDER
		amountOfDecks = 1;

		/*
		Casino Style -- Six Decks
		Home Style -- One Deck
		*/
	}
	int getAmountOfDecks() { return amountOfDecks; }

private:
	int start{}, amountOfDecks{};
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
		bj.startBlackjackGame(shuffledDeck, start.getAmountOfDecks());
	}
}