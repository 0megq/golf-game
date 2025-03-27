#include "core.h"

#ifndef GOLF_GAME
#define GOLF_GAME

// Initializes game
bool initGame();

// Updates the game
bool gameUpdate(float delta, int w, int h);

// Draws the current game frame
void gameDraw(sf::RenderWindow &window);

// Closes the game
void closeGame();

#endif