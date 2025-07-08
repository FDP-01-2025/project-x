#include "Cities.h"
#include "Player.h"
#include "Utilities.h"
#include <iostream>
using namespace std;

string cityNames[] = {
    "Binary City",
    "Stack Port",
    "Recursive Village",
    "Algorithmic Hamlet"
};

void enterCity(int cityId) {
    string cityName = (cityId >= 0 && cityId < 4) ? cityNames[cityId] : "Mysterious City";
    cout << "\n[City] Welcome to " << cityName << " in Secret Con+inen+!\n";
    cout << "You can rest and restore your energy.\n";
    if (player.coins < 5) {
        cout << "Not enough coins. You cannot heal.\n";
        pause();
        return;
    }
    cout << "Do you want to heal for 5 coins? (y/n): ";
    char answer;
    cin >> answer;
    if (answer == 'y' || answer == 'Y') {
        player.health = 100 + (player.level - 1) * 10;
        player.coins -= 5;
        cout << "You are fully healed!\n";
    } else {
        cout << "You chose not to heal.\n";
    }
    pause();
}
