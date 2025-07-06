#ifndef JUEGO_H
#define JUEGO_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Ciudad.h"
#include "Minijuegos.h"
#include "Combate.h"
#include "Jugador.h"
using namespace std;

const int FILAS = 7;
const int COLUMNAS = 7;
char mapa[FILAS][COLUMNAS] = {
    {'.', '.', 'E', '.', '.', 'J', '.'},
    {'.', 'X', '.', '.', 'X', '.', '.'},
    {'P', '.', '.', 'T', '.', '.', 'E'},
    {'.', '.', '.', '.', '.', '.', '.'},
    {'E', '.', 'X', '.', '.', '.', 'J'},
    {'.', '.', '.', '.', 'T', '.', '.'},
    {'.', 'J', '.', 'E', '.', 'X', '.'}
};

int jugadorFila = 2;
int jugadorColumna = 0;

void interactuar(char tipoCasilla) {
    switch (tipoCasilla) {
        case 'E':
            entrarCiudad();
            break;
        case 'T': {
            int minijuego = rand() % 3;
            if (minijuego == 0)
                jugarAdivinaNumero();
            else if (minijuego == 1)
                jugarTrivia();
            else
                jugarParOImpar();
            break;
        }
        case 'J':
            iniciarCombate();
            break;
        default:
            break;
    }
}

void mostrarMapa() {
    system("cls"); // Cambia por "clear" en Linux/Mac
    cout << "\n--- Mapa de Secret Con+inen+ ---\n";
    for (int i = 0; i < FILAS; ++i) {
        for (int j = 0; j < COLUMNAS; ++j) {
            cout << mapa[i][j] << "  ";
        }
        cout << endl;
    }
    cout << "\nUsa W/A/S/D para moverte, Q para salir\n";
}

bool moverJugador(char direccion) {
    int nuevaFila = jugadorFila;
    int nuevaColumna = jugadorColumna;

    switch (direccion) {
        case 'w': case 'W': nuevaFila--; break;
        case 's': case 'S': nuevaFila++; break;
        case 'a': case 'A': nuevaColumna--; break;
        case 'd': case 'D': nuevaColumna++; break;
        default: return false;
    }

    if (nuevaFila < 0 || nuevaFila >= FILAS || nuevaColumna < 0 || nuevaColumna >= COLUMNAS) {
        cout << "\nNo puedes salir del mapa de Secret Con+inen+!\n";
        return false;
    }

    if (mapa[nuevaFila][nuevaColumna] == 'X') {
        cout << "\nHay un obstáculo!\n";
        return false;
    }

    char tipoCasilla = mapa[nuevaFila][nuevaColumna];
    mapa[jugadorFila][jugadorColumna] = '.';
    jugadorFila = nuevaFila;
    jugadorColumna = nuevaColumna;
    mapa[jugadorFila][jugadorColumna] = 'P';

    interactuar(tipoCasilla);
    return true;
}

void iniciarJuego() {
    srand(time(0));
    crearJugador(jugadorFila, jugadorColumna);

    char opcion;
    do {
        mostrarMapa();
        mostrarEstado();
        cout << "\nMovimiento: ";
        cin >> opcion;
        if (opcion == 'q' || opcion == 'Q') break;
        moverJugador(opcion);
    } while (true);

    cout << "\nGracias por jugar Secret Con+inen+!\n";
}

#endif