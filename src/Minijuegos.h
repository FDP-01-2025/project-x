#ifndef MINIJUEGOS_H
#define MINIJUEGOS_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Jugador.h"
using namespace std;

// Minijuegos nivel 1
void jugarAdivinaNumero() {
    int num = rand() % 10 + 1, intento;
    cout << "\n[Adivina el Numero 1-10]\n";
    for (int i = 0; i < 3; ++i) {
        cout << "Intento #" << (i + 1) << ": ";
        cin >> intento;
        if (intento == num) {
            cout << "Correcto! +5 monedas\n";
            jugador.monedas += 5;
            return;
        } else {
            cout << "Incorrecto\n";
        }
    }
    cout << "Perdiste. El numero era: " << num << endl;
}

void jugarTrivia() {
    int puntos = 0;
    char r;
    cout << "\n[Trivia]\n1. Que lenguaje estas usando? (A) Python (B) Java (C) C++\n> "; cin >> r;
    if (r == 'C' || r == 'c') puntos++;
    cout << "2. Capital de El Salvador? (A) San Salvador (B) Santa Ana (C) La Union\n> "; cin >> r;
    if (r == 'A' || r == 'a') puntos++;
    cout << "3. Cuanto es 5 x 3? (A) 15 (B) 10 (C) 20\n> "; cin >> r;
    if (r == 'A' || r == 'a') puntos++;
    if (puntos >= 2) {
        cout << "Ganaste! +5 monedas\n";
        jugador.monedas += 5;
    } else {
        cout << "Fallaste la trivia.\n";
    }
}

void jugarParOImpar() {
    int num = rand() % 10 + 1;
    char eleccion;
    cout << "\n[Par o Impar] Elige P o I: "; cin >> eleccion;
    cout << "Numero generado: " << num << endl;
    bool par = (num % 2 == 0);
    if ((par && (eleccion == 'P' || eleccion == 'p')) ||
        (!par && (eleccion == 'I' || eleccion == 'i'))) {
        cout << "Ganaste! +3 monedas.\n";
        jugador.monedas += 3;
    } else {
        cout << "Fallaste.\n";
    }
}

// Minijuegos nivel 2
void minijuegoReflejos() {
    string secuencias[] = {"asd", "qwe", "zxc", "wsad"};
    int idx = rand() % 4;
    string input;
    cout << "[Reflejos] Escribe esta secuencia lo más rápido posible: " << secuencias[idx] << endl;
    cin >> input;
    if (input == secuencias[idx]) {
        cout << "¡Perfecto! +10 monedas" << endl;
        jugador.monedas += 10;
    } else {
        cout << "Fallaste, intenta ser más rápido y exacto." << endl;
    }
}

void minijuegoDados() {
    int tuTiro = rand() % 6 + 1;
    int jefeTiro = rand() % 6 + 1;
    cout << "[Batalla de Dados] Lanzando dados..." << endl;
    cout << "Tu dado: " << tuTiro << " | Dado del jefe: " << jefeTiro << endl;
    if (tuTiro > jefeTiro) {
        cout << "¡Ganaste la ronda! +5 monedas." << endl;
        jugador.monedas += 5;
    } else if (tuTiro < jefeTiro) {
        cout << "Perdiste la ronda. Sin recompensa." << endl;
    } else {
        cout << "Empate, lanza de nuevo la próxima vez." << endl;
    }
}

#endif