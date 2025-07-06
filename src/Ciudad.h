
#ifndef CIUDAD_H
#define CIUDAD_H

#include <iostream>
#include "Jugador.h"
using namespace std;

void entrarCiudad() {
    cout << "\n[Ciudad] Bienvenido a la ciudad.\n";
    cout << "Puedes descansar y recuperar tu energia.\n";
    cout << "¿Deseas curarte por 5 monedas? (s/n): ";
    char respuesta;
    cin >> respuesta;

    if ((respuesta == 's' || respuesta == 'S') && jugador.monedas >= 5) {
        jugador.vida = 100;
        jugador.monedas -= 5;
        cout << "¡Te has curado completamente!\n";
    } else if (jugador.monedas < 5) {
        cout << "No tienes suficientes monedas.\n";
    } else {
        cout << "Has decidido no curarte.\n";
    }
}

#endif
