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

const int FILAS = 7;
const int COLUMNAS = 7;

// El mapa actual de juego
char mapa[FILAS][COLUMNAS] = {
    {'.', '.', 'E', '.', '.', 'J', '.'},
    {'.', 'X', '.', '.', 'X', '.', '.'},
    {'P', '.', '.', 'T', '.', '.', 'E'},
    {'.', '.', '.', '.', '.', '.', '.'},
    {'E', '.', 'X', '.', '.', '.', 'J'},
    {'.', '.', '.', '.', 'T', '.', '.'},
    {'.', 'J', '.', 'E', '.', 'X', '.'}
};

// El mapa original fijo (para reiniciar)
const char MAPA_ORIGINAL[FILAS][COLUMNAS] = {
    {'.', '.', 'E', '.', '.', 'J', '.'},
    {'.', 'X', '.', '.', 'X', '.', '.'},
    {'P', '.', '.', 'T', '.', '.', 'E'},
    {'.', '.', '.', '.', '.', '.', '.'},
    {'E', '.', 'X', '.', '.', '.', 'J'},
    {'.', '.', '.', '.', 'T', '.', '.'},
    {'.', 'J', '.', 'E', '.', 'X', '.'}
};

// Para saber cuál ciudad es cada 'E', creamos una matriz auxiliar con IDs:
int ciudadesID[FILAS][COLUMNAS] = {
    {-1, -1, 0, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1, -1, 1},
    {-1, -1, -1, -1, -1, -1, -1},
    {2,  -1, -1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1, -1, -1},
    {-1, -1, -1,  3, -1, -1, -1}
};

int jugadorFila = 2;
int jugadorColumna = 0;


void reiniciarJuego() {
    for (int i = 0; i < FILAS; ++i)
        for (int j = 0; j < COLUMNAS; ++j)
            mapa[i][j] = MAPA_ORIGINAL[i][j];
    jugadorFila = 2;
    jugadorColumna = 0;
    crearJugador(jugadorFila, jugadorColumna);
}

void mostrarMapa() {
    system("cls"); // Cambia por "clear" en Linux/Mac
    cout << "\n--- Mapa de Secret Con+inen+ ---\n";
    cout << "P = Tú   E = Ciudad   J = Jefe   T = Minijuego   X = Obstáculo   . = Camino\n";
    cout << "---------------------------------------------------------------\n";
    for (int i = 0; i < FILAS; ++i) {
        for (int j = 0; j < COLUMNAS; ++j) {
            cout << mapa[i][j] << "  ";
        }
        cout << endl;
    }
}

void interactuar(char tipoCasilla, int fila, int columna) {
    switch (tipoCasilla) {
        case 'E':
            if (ciudadesID[fila][columna] != -1)
                entrarCiudad(ciudadesID[fila][columna]);
            else
                entrarCiudad(0);
            break;
        case 'T': {
            int minijuego = rand() % 3;
            cout << "\n¡Entraste a un minijuego!\n";
            if (minijuego == 0) {
                cout << "Adivina el número: Debes adivinar un número entre 1 y 10.\n";
                jugarAdivinaNumero();
            } else if (minijuego == 1) {
                cout << "Trivia: Responde correctamente preguntas para ganar monedas.\n";
                jugarTrivia();
            } else {
                cout << "Par o Impar: Adivina si el número generado es par o impar.\n";
                jugarParOImpar();
            }
            break;
        }
        case 'J':
            iniciarCombate(fila, columna);
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

    if (mapa[nuevaFila][nuevaColumna] == 'X') {
        cout << "\nHay un obstáculo!\n";
        return false;
    }

    char tipoCasilla = mapa[nuevaFila][nuevaColumna];
    mapa[jugadorFila][jugadorColumna] = '.';
    jugadorFila = nuevaFila;
    jugadorColumna = nuevaColumna;
    mapa[jugadorFila][jugadorColumna] = 'P';

    interactuar(tipoCasilla, nuevaFila, nuevaColumna);
    return true;
}

void iniciarJuego() {
    srand(time(0));
    cout << "¿Deseas cargar una partida guardada? (s/n): ";
    char respuesta;
    cin >> respuesta;
    if (respuesta == 's' || respuesta == 'S') {
        if (!cargarPartida()) {
            cout << "No existe partida guardada. Se comenzará de 0.\n";
            crearJugador(jugadorFila, jugadorColumna);
        }
    } else {
        crearJugador(jugadorFila, jugadorColumna);
    }

    char opcion;
    do {
        mostrarMapa();
        mostrarEstado();
        cout << "\nMoverse (W/A/S/D)\nO puedes guardar tu progreso presionando 'G' (Guardar) o salir con 'Q'.\n";
        cout << "Elige: ";
        cin >> opcion;
        if (opcion == 'g' || opcion == 'G') {
            guardarPartida();
            continue;
        }
        if (opcion == 'q' || opcion == 'Q') break;
        moverJugador(opcion);
    } while (true);

    cout << "\nGracias por jugar Secret Con+inen+!\n";
}

#endif
