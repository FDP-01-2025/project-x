#ifndef COMBATE_H
#define COMBATE_H

#include <iostream>
#include <cstdlib>
#include "Jugador.h"
using namespace std;

// Variables globales para nivel
extern int nivelActual;
extern bool pasarDeNivel;

void iniciarCombate() {
    int vidaJefe = (nivelActual == 1 ? 80 : 150);
    int ataqueJefe = (nivelActual == 1 ? 20 : 35);
    cout << "\n[Jefe Final] El Guardian de CodigoLandia aparece.\n";
    while (jugador.vida > 0 && vidaJefe > 0) {
        cout << "\nTu vida: " << jugador.vida << " | Vida del jefe: " << vidaJefe << "\n";
        cout << "1. Atacar\n2. Defender\n> ";
        char op; cin >> op;
        int danioJ = rand() % (ataqueJefe / 2) + 5, danioE = 0;
        if (op == '1') {
            danioE = rand() % (ataqueJefe) + 10;
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
        cout << "\nDerrotaste al jefe final!\n";
        if (nivelActual == 1) {
            cout << "Te entrega un mapa misterioso... ¡Pasas al siguiente nivel!\n";
            pasarDeNivel = true;
        } else {
            cout << "¡Has salvado CodigoLandia! ¡Eres leyenda!\n";
        }
    }
}

#endif
