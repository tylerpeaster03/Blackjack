#ifndef GAMEBJ_H
#define GAMEBJ_H

#include <string>
#include <vector>

class Blackjack {
public:
	void startBlackjackGame(std::vector <std::string> deckOfCards, int playerCount);
	void giveAllEntitiesCards();
	void giveCard(std::vector <std::string> pCards);
	void showCardUp(std::vector <std::string> entityCards, int num);

private:
	std::vector <std::string> deckOfCards, dealerCards;
	std::vector <std::string> pCards1, pCards2, pCards3, pCards4, pCards5, pCards6, pCards7;	//player cards
	int playerCount{}, cardID{};
	std::string tempS;
};

#endif

