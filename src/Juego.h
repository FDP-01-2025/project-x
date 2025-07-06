#ifndef JUEGO_H
#define JUEGO_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Ciudad.h"
#include "Minijuegos.h"
#include "Combate.h"
#include "Jugador.h"
#include "Archivos.h"
using namespace std;

const int FILAS = 12;
const int COLUMNAS = 20;
char mapa[FILAS][COLUMNAS];

int jugadorFila = 1;
int jugadorColumna = 1;

void inicializarMapa() {
    // Bordes y paredes internas
    for (int i = 0; i < FILAS; ++i)
        for (int j = 0; j < COLUMNAS; ++j)
            mapa[i][j] = (i==0 || i==FILAS-1 || j==0 || j==COLUMNAS-1) ? '#' : '.';
    for (int i = 3; i < 9; ++i) mapa[i][5] = '#';
    for (int j = 5; j < 16; ++j) mapa[4][j] = '#';
    // Elementos
    mapa[jugadorFila][jugadorColumna] = 'P';
    mapa[6][17] = 'J';
    mapa[2][10] = 'T';
    mapa[10][15] = 'T';
    mapa[3][16] = 'E';
    mapa[7][3] = 'E';
    mapa[6][7] = 'X';
}

void mostrarMapaBonito() {
    cout << "   ╔";
    for (int c = 0; c < COLUMNAS; ++c) cout << "═══";
    cout << "╗\n";
    for (int i = 0; i < FILAS; ++i) {
        cout << (i % 10) << " ║";
        for (int j = 0; j < COLUMNAS; ++j) {
            if (mapa[i][j] == '#')
                cout << "███";
            else if (mapa[i][j] == '.')
                cout << " · ";
            else if (mapa[i][j] == 'P')
                cout << " @ ";
            else if (mapa[i][j] == 'J')
                cout << " ☠ ";
            else if (mapa[i][j] == 'E')
                cout << " $ ";
            else if (mapa[i][j] == 'T')
                cout << " ? ";
            else if (mapa[i][j] == 'X')
                cout << " X ";
            else
                cout << "   ";
        }
        cout << "║\n";
    }
    cout << "   ╚";
    for (int c = 0; c < COLUMNAS; ++c) cout << "═══";
    cout << "╝\n";
    static bool leyenda = true;
    if (leyenda) {
        cout << "\n--- LEYENDA ---\n";
        cout << "@=Tú  ☠=Jefe  $=Ciudad  ?=Minijuego  X=Obstáculo  ·=Camino  █=Pared\n";
        cout << "----------------\n";
        leyenda = false;
    }
}

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

    if (mapa[nuevaFila][nuevaColumna] == '#' || mapa[nuevaFila][nuevaColumna] == 'X') {
        cout << "\nNo puedes pasar, hay una pared o un obstáculo!\n";
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
    inicializarMapa();
    crearJugador(jugadorFila, jugadorColumna);

    char opcion;
    do {
        mostrarMapaBonito();
        mostrarEstado();
        cout << "\nMovimiento: ";
        cin >> opcion;
        if (opcion == 'q' || opcion == 'Q') break;
        moverJugador(opcion);
    } while (true);

    cout << "\n¡Gracias por jugar Secret Con+inen+!\n";
}

#endif