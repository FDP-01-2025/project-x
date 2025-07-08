#include "Game.h"
#include "Player.h"
#include "Cities.h"
#include "Minigames.h"
#include "Battle.h"
#include "Archive.h"
#include "Utilities.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int ROWS = 7;
const int COLS = 7;

char map[ROWS][COLS] = {
    {'.', '.', 'E', '.', '.', 'J', '.'},
    {'.', 'X', '.', '.', 'X', '.', '.'},
    {'P', '.', '.', 'T', '.', '.', 'E'},
    {'.', '.', '.', '.', '.', '.', '.'},
    {'E', '.', 'X', '.', '.', '.', 'J'},
    {'.', '.', '.', '.', 'T', '.', '.'},
    {'.', 'J', '.', 'E', '.', 'X', '.'}
};
//PARA CUANDO SE REINICIA EL JUEGO
const char ORIGINAL_MAP[ROWS][COLS] = {
    {'.', '.', 'E', '.', '.', 'J', '.'},
    {'.', 'X', '.', '.', 'X', '.', '.'},
    {'P', '.', '.', 'T', '.', '.', 'E'},
    {'.', '.', '.', '.', '.', '.', '.'},
    {'E', '.', 'X', '.', '.', '.', 'J'},
    {'.', '.', '.', '.', 'T', '.', '.'},
    {'.', 'J', '.', 'E', '.', 'X', '.'}
};

// City IDs para cada posición en el mapa
int citiesID[ROWS][COLS] = {
    {-1, -1, 0, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1, -1, 1},
    {-1, -1, -1, -1, -1, -1, -1},
    {2,  -1, -1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1, -1, -1},
    {-1, -1, -1,  3, -1, -1, -1}
};

int playerRow = 2;
int playerCol = 0;

void restartGame() {
    for (int i = 0; i < ROWS; ++i)
        for (int j = 0; j < COLS; ++j)
            map[i][j] = ORIGINAL_MAP[i][j];
    playerRow = 2;
    playerCol = 0;
    createPlayer(playerRow, playerCol);
}

void showMap() {
    cout << "\n--- Secret Con+inen+ Map ---\n";
    cout << "P = You   E = City   J = Boss   T = Minigame   X = Obstacle   . = Path\n";
    cout << "---------------------------------------------------------------\n";
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << map[i][j] << "  ";
        }
        cout << endl;
    }
}

void interact(char cellType, int row, int col) {
    switch (cellType) {
        case 'E':
            if (citiesID[row][col] != -1)
                enterCity(citiesID[row][col]);
            else
                enterCity(0);
            break;
        case 'T': {
            int minigame = rand() % 3;
            cout << "\nYou entered a minigame!\n";
            if (minigame == 0) {
                cout << "Guess the Number: Try to guess a number between 1 and 10.\n";
                playGuessNumber();
            } else if (minigame == 1) {
                cout << "Trivia: Answer the questions to win coins.\n";
                playTrivia();
            } else {
                cout << "Even or Odd: Guess if the generated number is even or odd.\n";
                playEvenOrOdd();
            }
            break;
        }
        case 'J':
            startBattle(row, col);
            break;
        default:
            break;
    }
}

bool movePlayer(char direction) {
    int newRow = playerRow;
    int newCol = playerCol;

    switch (direction) {
        case 'w': case 'W': newRow--; break;
        case 's': case 'S': newRow++; break;
        case 'a': case 'A': newCol--; break;
        case 'd': case 'D': newCol++; break;
        default: return false;
    }

    if (newRow < 0 || newRow >= ROWS || newCol < 0 || newCol >= COLS) {
        cout << "\nYou can't leave the Secret Con+inen+ map!\n";
        return false;
    }

    if (map[newRow][newCol] == 'X') {
        cout << "\nThere's an obstacle!\n";
        return false;
    }

    char cellType = map[newRow][newCol];
    map[playerRow][playerCol] = '.';
    playerRow = newRow;
    playerCol = newCol;
    map[playerRow][playerCol] = 'P';

    interact(cellType, playerRow, playerCol);
    return true;
}

void startGame() {
    srand(time(0));
    cout << "Do you want to load a saved game? (y/n): ";
    char answer;
    cin >> answer;
    if (answer == 'y' || answer == 'Y') {
        if (!loadGame()) {
            cout << "No saved game found. Starting from scratch.\n";
            createPlayer(playerRow, playerCol);
        }
    } else {
        createPlayer(playerRow, playerCol);
    }

    char option;
    do {
        showMap();
        showStatus();
        cout << "\nMove (W/A/S/D)\nOr save your progress with 'G' or quit with 'Q'.\n";
        cout << "Choose: ";
        cin >> option;
        if (option == 'g' || option == 'G') {
            saveGame();
            continue;
        }
        if (option == 'q' || option == 'Q') break;
        movePlayer(option);
    } while (true);

    cout << "\nThanks for playing Secret Con+inen+!\n";
}
