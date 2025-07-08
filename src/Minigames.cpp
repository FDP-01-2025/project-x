#include "Minigames.h"
#include "Player.h"
#include "Utilities.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//Subida de nivel segun la experiencia del jugador
void levelUpIfNeeded() {
    if (player.experience >= 30) {
        player.level++;
        player.health = 100 + (player.level - 1) * 10;
        player.experience = 0;
        cout << "You leveled up to " << player.level << "! Max health and strength increased.\n";
        pause();
    }
}
    
void playGuessNumber() {
    int num = rand() % 10 + 1, guess;
    cout << "\n[Guess the Number 1-10]\n";
    for (int i = 0; i < 3; ++i) {
        cout << "Try #" << (i + 1) << ": ";
        cin >> guess;
        if (guess == num) {
            cout << "Correct! +5 coins and +10 XP\n";
            player.coins += 5;
            player.experience += 10;
            levelUpIfNeeded();
            pause();
            return;
        } else {
            cout << "Incorrect\n";
        }
    }
    cout << "You lost. The number was: " << num << endl;
    cout << "You lost all your chances in this minigame.\n";
    pause();
}

void playTrivia() {
    int points = 0;
    char r;
    cout << "\n[Secret Con+inen+ Trivia]\n1. Which language are you using? (A) Python (B) Java (C) C++\n> "; cin >> r;
    if (r == 'C' || r == 'c') points++;
    cout << "2. Capital of El Salvador? (A) San Salvador (B) Santa Ana (C) La Union\n> "; cin >> r;
    if (r == 'A' || r == 'a') points++;
    cout << "3. How much is 5 x 3? (A) 15 (B) 10 (C) 20\n> "; cin >> r;
    if (r == 'A' || r == 'a') points++;
    if (points >= 2) {
        cout << "You won! +5 coins and +10 XP\n";
        player.coins += 5;
        player.experience += 10;
        levelUpIfNeeded();
        pause();
    } else {
        cout << "You failed the trivia.\n";
        cout << "You lost all your chances in this minigame.\n";
        pause();
    }
}

void playEvenOrOdd() {
    int num = rand() % 10 + 1;
    char choice;
    cout << "\n[Even or Odd] Choose E or O: "; cin >> choice;
    cout << "Generated number: " << num << endl;
    bool even = (num % 2 == 0);
    if ((even && (choice == 'E' || choice == 'e')) ||
        (!even && (choice == 'O' || choice == 'o'))) {
        cout << "You won! +3 coins and +10 XP.\n";
        player.coins += 3;
        player.experience += 10;
        levelUpIfNeeded();
        pause();
    } else {
        cout << "You lost.\n";
        cout << "You lost all your chances in this minigame.\n";
        pause();
    }
}
