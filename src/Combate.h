#ifndef COMBATE_H
#define COMBATE_H

#include <iostream>
#include <cstdlib>
#include "Jugador.h"
#include "Archivos.h"
using namespace std;

// Estructura y datos de los jefes
struct Jefe {
    string nombre;
    int vidaBase;
    int ataqueBase;
};
Jefe jefes[] = {
    {"Sr. Cipher", 60, 7},
    {"General Byte", 80, 12},
    {"Reina Algoritmia", 110, 18}
};
const int NUM_JEFES = 3;

// Para asignar jefe según posición en el mapa (debes ajustar según tu mapa real)
int jefeIDporCasilla(int fila, int columna) {
    if (fila == 0 && columna == 5) return 0; // Cambia esto según la posición real de los jefes
    if (fila == 4 && columna == 6) return 1;
    if (fila == 6 && columna == 1) return 2;
    return 0;
}

void subirNivelSiCorresponde() {
    if (jugador.experiencia >= 30) {
        jugador.nivel++;
        jugador.vida = 100 + (jugador.nivel - 1) * 10;
        jugador.experiencia = 0;
        cout << "¡Subiste a nivel " << jugador.nivel << "! Tu vida máxima y fuerza aumentaron.\n";
    }
}

void iniciarCombate(int fila, int columna) {
    int idJefe = jefeIDporCasilla(fila, columna);
    Jefe jefe = jefes[idJefe];
    int vidaJefe = jefe.vidaBase + (jugador.nivel - 1) * 7;
    cout << "\n[Jefe] Aparece " << jefe.nombre << " (Vida: " << vidaJefe << ", Ataque: " << jefe.ataqueBase << ")\n";

    while (jugador.vida > 0 && vidaJefe > 0) {
        cout << "\nTu vida: " << jugador.vida << " | Vida del jefe: " << vidaJefe << endl;
        cout << "1. Atacar\n2. Defender\n> ";
        char op; cin >> op;
        int danioJ = rand() % (jefe.ataqueBase) + 5;
        int danioE = 0;
        int bono = jugador.nivel * 2;

        if (op == '1') {
            danioE = rand() % 13 + 7 + bono; // Tu ataque sube con nivel
            vidaJefe -= danioE;
            cout << "Atacaste a " << jefe.nombre << " e hiciste " << danioE << " de dano!\n";
        } else if (op == '2') {
            danioJ /= 2;
            cout << "Te defendiste! Dano recibido reducido.\n";
        }
        jugador.vida -= danioJ;
        cout << jefe.nombre << " te hizo " << danioJ << " de dano.\n";
    }

    if (jugador.vida <= 0) {
        cout << "\nHas muerto contra " << jefe.nombre << ". ¿Deseas empezar de 0 (0) o seguir con tu último punto de guardado (1)? ";
        int eleccion; cin >> eleccion;
        if (eleccion == 1 && cargarPartida()) {
            cout << "¡Continuando desde tu último guardado!\n";
        } else {
            cout << "¡Comenzando de nuevo!\n";
            crearJugador(2, 0); // Posición inicial
        }
    } else {
        cout << "\n¡Has derrotado a " << jefe.nombre << "!\n";
        jugador.experiencia += 15;
        subirNivelSiCorresponde();
    }
}

#endif