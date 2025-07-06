#ifndef CIUDAD_H
#define CIUDAD_H

#include <iostream>
#include "Jugador.h"
using namespace std;

// Nombres de las ciudades
string nombresCiudades[] = {
    "Ciudad Binaria",
    "Puerto Stack",
    "Villa Recursiva",
    "Aldea Algoritmica"
};

void entrarCiudad(int idCiudad) {
    string nombreCiudad = (idCiudad >= 0 && idCiudad < 4) ? nombresCiudades[idCiudad] : "Ciudad Misteriosa";
    cout << "\n[Ciudad] Bienvenido a " << nombreCiudad << " de Secret Con+inen+!\n";
    cout << "Puedes descansar y recuperar tu energia.\n";
    if (jugador.monedas < 5) {
        cout << "Monedas insuficientes. No puedes curarte.\n";
        return;
    }
    cout << "Deseas curarte por 5 monedas? (s/n): ";
    char respuesta;
    cin >> respuesta;
    if (respuesta == 's' || respuesta == 'S') {
        jugador.vida = 100 + (jugador.nivel - 1) * 10; // Si subió de nivel, cura hasta la nueva vida máxima
        jugador.monedas -= 5;
        cout << "Te has curado completamente!\n";
    } else {
        cout << "Has decidido no curarte.\n";
    }
}

#endif