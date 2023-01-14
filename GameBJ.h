#ifndef GAMEBJ_H
#define GAMEBJ_H

#include <string>
#include <vector>

class Blackjack {
public:
	void startBlackjackGame(std::vector <std::string> deckOfCardsPassed, int deckAmount);
	std::vector <std::string> addCard(std::vector <std::string> playerOrDealerDeck);
	void menu();
	char pointsCheck(std::vector <int> points);
	void reset();
	void dealerAi();
	void amountOfDeckMessage();

private:
	std::vector <std::string> deckOfCards, playerCards, dealerCards;
	std::vector <int> pointsOfPlayer, pointsOfDealer;
	std::string tempS, cardThatAllowsSplit1, cardThatAllowsSplit2;
	int cardID{}, totalPoints{}, amountOfDecks;
	char gameStatePlayer, gameStateDealer;
	bool allowSplit{}, allowAceSplit{};
};

#endif

