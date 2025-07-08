
#include "Archive.h"
#include "Player.h"
#include <fstream>
#include <iostream>
using namespace std;

extern char map[7][7];

void saveGame() {
    ofstream file("savegame.txt");
    if (file.is_open()) {
        file << player.name << endl;
        file << player.health << endl;
        file << player.coins << endl;
        file << player.exploredPoints << endl;
        file << player.row << endl;
        file << player.col << endl;
        file << player.level << endl;
        file << player.experience << endl;
        for (int i = 0; i < 3; ++i)
            file << player.bossesDefeated[i] << endl;
        for (int i = 0; i < 7; ++i)
            for (int j = 0; j < 7; ++j)
                file << map[i][j];
        file.close();
        cout << "Game saved in Secret Con+inen+!" << endl;
    } else {
        cout << "Error saving the game." << endl;
    }
}

bool loadGame() {
    ifstream file("savegame.txt");
    if (file.is_open()) {
        getline(file, player.name);
        file >> player.health;
        file >> player.coins;
        file >> player.exploredPoints;
        file >> player.row;
        file >> player.col;
        file >> player.level;
        file >> player.experience;
        for (int i = 0; i < 3; ++i)
            file >> player.bossesDefeated[i];
        char dummy = file.get(); // consumir newline
        for (int i = 0; i < 7; ++i)
            for (int j = 0; j < 7; ++j)
                map[i][j] = file.get();
        file.close();
        cout << "Game loaded successfully!\n";
        return true;
    }
    return false;
}
