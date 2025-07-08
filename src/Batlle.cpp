#include "Battle.h"
#include "Player.h"
#include "Archive.h"
#include "Utilities.h"
#include "Game.h"
#include "Minigames.h"
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

struct Boss {
    string name;
    int baseHealth;
    int baseAttack;
};
Boss bosses[] = {
    {"Mr. Cipher", 60, 7},
    {"General Byte", 80, 12},
    {"Queen Algorithmia", 110, 18}
};
const int NUM_BOSSES = 3;

int bossIDbyCell(int row, int col) {
    if (row == 0 && col == 5) return 0;
    if (row == 4 && col == 6) return 1;
    if (row == 6 && col == 1) return 2;
    return 0;
}

void startBattle(int row, int col) {
    int id = bossIDbyCell(row, col);
    Boss boss = bosses[id];
    int bossHealth = boss.baseHealth + (player.level - 1) * 7;
    cout << "\n[Boss] " << boss.name << " appears (Health: " << bossHealth << ", Attack: " << boss.baseAttack << ")\n";

    while (player.health > 0 && bossHealth > 0) {
        cout << "\nYour health: " << player.health << " | Boss health: " << bossHealth << endl;
        cout << "1. Attack\n2. Defend\n> ";
        char op; cin >> op;
        int dmgToPlayer = rand() % (boss.baseAttack) + 5;
        int dmgToBoss = 0;
        int bonus = player.level * 2;

        if (op == '1') {
            dmgToBoss = rand() % 13 + 7 + bonus;
            bossHealth -= dmgToBoss;
            cout << "You attacked " << boss.name << " and did " << dmgToBoss << " damage!\n";
        } else if (op == '2') {
            dmgToPlayer /= 2;
            cout << "You defended! Damage received reduced.\n";
        }
        player.health -= dmgToPlayer;
        cout << boss.name << " dealt you " << dmgToPlayer << " damage.\n";
    }

    if (player.health <= 0) {
        cout << "\nYou died against " << boss.name << ". Start from zero (0) or load your last save (1)? ";
        int choice; cin >> choice;
        if (choice == 1) {
            if (loadGame()) {
                cout << "Resuming from your last save!\n";
            } else {
                cout << "No saved game. Starting from scratch.\n";
                restartGame();
            }
        } else {
            cout << "Starting from scratch!\n";
            restartGame();
        }
    } else {
        cout << "\nYou defeated " << boss.name << "!\n";
        player.experience += 15;
        levelUpIfNeeded();
    }
}
