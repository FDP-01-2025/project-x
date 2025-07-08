#ifndef GAME_H
#define GAME_H

void restartGame();
void showMap();
void interact(char cellType, int row, int col);
bool movePlayer(char direction);
void startGame();

#endif
