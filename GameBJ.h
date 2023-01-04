#ifndef GAMEBJ_H
#define GAMEBJ_H

#include <string>
#include <vector>

class Blackjack {
public:
	void startBlackjackGame(std::vector <std::string> deckOfCardsPassed);
	std::vector <std::string> addCard(std::vector <std::string> playerOrDealerDeck);
	void displayTheFirstCardsPassed();

private:
	std::vector <std::string> deckOfCards, playerCards, dealerCards;
	std::string tempS;
	int cardID{};
};

#endif

