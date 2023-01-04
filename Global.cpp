#include "Global.h"

#include <iostream>
#include <string>

void separatorUI() { std::cout << "\n-------------------------------------\n"; }

void clearScreen() { std::cout << "\033[2J\033[1;1H"; }

void colorText (std::string color, std::string text)
{
	int colorID{};

	if (color == "black" || color == "Black")
		colorID = 30;
	else if (color == "red" || color == "Red")
		colorID = 31;
	else if (color == "green" || color == "Green")
		colorID = 32;
	else if (color == "yellow" || color == "Yellow")
		colorID = 33;
	else if (color == "blue" || color == "Blue")
		colorID = 34;
	else if (color == "magenta" || color == "Magenta" || color == "purple" || color == "Purple")
		colorID = 35;
	else if (color == "cyan" || color == "Cyan")
		colorID = 36;
	else if (color == "white" || color == "White")
		colorID = 37;
	else if (color == "brightBlack" || color == "BrightBlack")
		colorID = 90;
	else if (color == "brightRed" || color == "BrightRed")
		colorID = 91;
	else if (color == "brightGreen" || color == "BrightGreen")
		colorID = 92;
	else if (color == "brightYellow" || color == "BrightYellow")
		colorID = 93;
	else if (color == "brightBlue" || color == "BrightBlue")
		colorID = 94;
	else if (color == "brightMagenta" || color == "BrightMagenta" || color == "brightPurple" || color == "BrightPurple")
		colorID = 95;
	else if (color == "brightCyan" || color == "BrightCyan")
		colorID = 96;
	else if (color == "brightWhite" || color == "BrightWhite")
		colorID = 97;
	else
		colorID = 37;


	std::cout << "\x1B[";
	std::cout << colorID;
	std::cout << "m";
	std::cout << text;
	std::cout << "\033[0m\t\t";
}

void autoDisplayColorForCard(std::string card)
{
	if (card[6] == 'S' || card[6] == 'C')
		colorText("brightWhite", card);
	else if (card[6] == 'D' || card[6] == 'H')
		colorText("brightRed", card);
}