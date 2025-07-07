#ifndef ARCHIVE_H
#define ARCHIVE_H

#include <fstream>
#include <iostream>
#include "Player.h"
using namespace std;

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
        file.close();
        cout << "Game loaded successfully!\n";
        return true;
    }
    return false;
}

#endif
