
#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using namespace std;

struct Player {
    string name;
    int health;
    int coins;
    int exploredPoints;
    int row, col;
    int level;
    int experience;
    bool bossesDefeated[3];  // NUEVO: para saber qué jefes ya fueron vencidos
};

extern Player player;
void createPlayer(int row, int col);
void showStatus();

#endif
