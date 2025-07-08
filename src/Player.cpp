#include "Player.h"
#include <iostream>
using namespace std;

Player player;

void createPlayer(int row, int col) {
    cout << "Enter your adventurer's name for Secret Con+inen+: ";
    getline(cin >> ws, player.name);
    player.health = 100;
    player.coins = 0;
    player.exploredPoints = 0;
    player.row = row;
    player.col = col;
    player.level = 1;
    player.experience = 0;
    cout << "Player created successfully in Secret Con+inen+!\n";
}

void showStatus() {
    cout << "\n--- PLAYER STATUS IN SECRET CON+INEN+ ---\n";
    cout << "Name: " << player.name << "\n";
    cout << "Level: " << player.level << " (XP: " << player.experience << ")\n";
    cout << "Health: " << player.health << "\n";
    cout << "Coins: " << player.coins << "\n";
    cout << "Explored points: " << player.exploredPoints << "\n";
    cout << "Position: (" << player.row << ", " << player.col << ")\n";
    cout << "---------------------------\n";
}
