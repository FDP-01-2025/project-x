#ifndef COMBATE_H
#define COMBATE_H

#include <iostream>
#include <cstdlib>
#include "Jugador.h"
using namespace std;

// Variables globales para nivel (si tienes niveles)
extern int nivelActual;
extern bool pasarDeNivel;

void iniciarCombate() {
    // Si tienes niveles, puedes cambiar la dificultad aquí
    int vidaJefe = 80;
    cout << "\n[Jefe Final] El Guardian de Secret Con+inen+ aparece.\n";
    while (jugador.vida > 0 && vidaJefe > 0) {
        cout << "\nTu vida: " << jugador.vida << " | Vida del jefe: " << vidaJefe << "\n";
        cout << "1. Atacar\n2. Defender\n> ";
        char op; cin >> op;
        int danioJ = rand() % 11 + 5, danioE = 0;
        if (op == '1') {
            danioE = rand() % 16 + 5;
            vidaJefe -= danioE;
            cout << "Atacaste e hiciste " << danioE << " de dano!\n";
        } else if (op == '2') {
            danioJ /= 2;
            cout << "Te defendiste! Dano recibido reducido.\n";
        }
        jugador.vida -= danioJ;
        cout << "El jefe te hizo " << danioJ << " de dano.\n";
    }
    if (jugador.vida <= 0)
        cout << "\nHas sido derrotado por el jefe final...\n";
    else {
        cout << "\n¡Has salvado Secret Con+inen+! ¡Eres leyenda!\n";
    }
}

#endif