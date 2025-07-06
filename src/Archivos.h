#ifndef ARCHIVOS_H
#define ARCHIVOS_H

#include <fstream>
#include <iostream>
#include "Jugador.h"
using namespace std;

void guardarPartida() {
    ofstream archivo("PartidaSC.txt");
    if (archivo.is_open()) {
        archivo << jugador.nombre << endl;
        archivo << jugador.vida << endl;
        archivo << jugador.monedas << endl;
        archivo << jugador.puntosExplorados << endl;
        archivo << jugador.fila << endl;
        archivo << jugador.columna << endl;
        archivo.close();
        cout << "¡Partida de Secret Con+inen+ guardada!" << endl;
    } else {
        cout << "Error al guardar la partida de Secret Con+inen+." << endl;
    }
}

bool cargarPartida() {
    ifstream archivo("PartidaSC.txt");
    if (archivo.is_open()) {
        getline(archivo, jugador.nombre);
        archivo >> jugador.vida;
        archivo >> jugador.monedas;
        archivo >> jugador.puntosExplorados;
        archivo >> jugador.fila;
        archivo >> jugador.columna;
        archivo.close();
        cout << "¡Partida de Secret Con+inen+ cargada correctamente!\n";
        return true;
    }
    return false;
}

#endif