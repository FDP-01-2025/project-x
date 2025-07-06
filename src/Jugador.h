
#ifndef JUGADOR_H
#define JUGADOR_H

#include <iostream>
#include <string>
using namespace std;

struct Jugador {
    string nombre;
    int vida;
    int monedas;
};

Jugador jugador;

void crearJugador() {
    cout << "¡Bienvenido a CódigoLandia!\n";
    cout << "Ingresa tu nombre de aventurero: ";
    cin.ignore();
    getline(cin, jugador.nombre);
    jugador.vida = 100;
    jugador.monedas = 0;
    cout << "Jugador creado exitosamente.\n";
}

void mostrarEstado() {
    cout << "\n--- ESTADO DEL JUGADOR ---\n";
    cout << "Nombre: " << jugador.nombre << endl;
    cout << "Vida: " << jugador.vida << endl;
    cout << "Monedas: " << jugador.monedas << endl;
    cout << "---------------------------\n";
}

#endif
