#ifndef GLOVAL_H
#define GLOBAL_H

#include <string>

void separatorUI();
void clearScreen();
void colorText(std::string color, std::string text);
void autoDisplayColorForCard(std::string card);
int cinIntCheckPlusBounds(int num, int lowestBound, int greatestBound);

#endif
