#ifndef GAMEBJ_H
#define GAMEBJ_H

#include <string>
#include <vector>

class Blackjack {
public:
	void startBlackjackGame(std::vector <std::string> deckOfCardsPassed);
	std::vector <std::string> addCard(std::vector <std::string> playerOrDealerDeck);
	void displayTheFirstCardsPassed();
	void menu();
	char pointsCheck(std::vector <int> points);

private:
	std::vector <std::string> deckOfCards, playerCards, dealerCards;
	std::vector <int> pointsOfPlayer, pointsOfDealer;
	std::string tempS;
	int cardID{};
	char gameStatePlayer, gameStateDealer;
};

#endif

