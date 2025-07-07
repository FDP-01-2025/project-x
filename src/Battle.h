#ifndef COMBATE_H
#define COMBATE_H

#include <iostream>
#include <cstdlib>
#include "Jugador.h"
#include "Archivos.h"
#include "Juego.h" 
using namespace std;

extern void subirNivelSiCorresponde();

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

// Para asignar jefe según posición en el mapa
int jefeIDporCasilla(int fila, int columna) {
    if (fila == 0 && columna == 5) return 0;
    if (fila == 4 && columna == 6) return 1;
    if (fila == 6 && columna == 1) return 2;
    return 0;
}

extern void reiniciarJuego();
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
            danioE = rand() % 13 + 7 + bono;
            vidaJefe -= danioE;
            cout << "Atacaste a " << jefe.nombre << " e hiciste " << danioE << " de daño!\n";
        } else if (op == '2') {
            danioJ /= 2;
            cout << "Te defendiste! Daño recibido reducido.\n";
        }
        jugador.vida -= danioJ;
        cout << jefe.nombre << " te hizo " << danioJ << " de daño.\n";
    }

    if (jugador.vida <= 0) {
        cout << "\nHas muerto contra " << jefe.nombre << ". ¿Deseas empezar de 0 (0) o seguir con tu último punto de guardado (1)? ";
        int eleccion; cin >> eleccion;
        if (eleccion == 1) {
            if (cargarPartida()) {
                cout << "¡Continuando desde tu último guardado!\n";
            } else {
                cout << "No tienes ninguna partida guardada. Comenzando de nuevo.\n";
                reiniciarJuego();
            }
        } else {
            cout << "¡Comenzando de nuevo!\n";
            reiniciarJuego();
        }
    } else {
        cout << "\n¡Has derrotado a " << jefe.nombre << "!\n";
        jugador.experiencia += 15;
        subirNivelSiCorresponde();
    }
}

#endif
