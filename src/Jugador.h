#ifndef JUGADOR_H
#define JUGADOR_H

#include <iostream>
#include <string>
using namespace std;

struct Jugador {
    std::string nombre;
    int vida;
    int monedas;
    int puntosExplorados;
    int fila, columna;
};

Jugador jugador;

void crearJugador(int fila, int columna) {
    cout << "Ingresa tu nombre de aventurero de Secret Con+inen+: ";
    cin.ignore();
    getline(cin, jugador.nombre);
    jugador.vida = 100;
    jugador.monedas = 0;
    jugador.puntosExplorados = 0;
    jugador.fila = fila;
    jugador.columna = columna;
    cout << "¡Jugador creado exitosamente en Secret Con+inen+!" << endl;
}

void mostrarEstado() {
    cout << "\n--- ESTADO DEL JUGADOR EN SECRET CON+INEN+ ---\n";
    cout << "Nombre: " << jugador.nombre << "\n";
    cout << "Vida: " << jugador.vida << "\n";
    cout << "Monedas: " << jugador.monedas << "\n";
    cout << "Puntos explorados: " << jugador.puntosExplorados << "\n";
    cout << "Posicion: (" << jugador.fila << ", " << jugador.columna << ")\n";
    cout << "---------------------------\n";
}

#endif