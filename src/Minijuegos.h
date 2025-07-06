
#ifndef MINIJUEGOS_H
#define MINIJUEGOS_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Jugador.h"
using namespace std;

void jugarAdivinaNumero() {
    int numeroSecreto = rand() % 10 + 1;
    int intento;
    cout << "\n[Adivina] Adivina el número del 1 al 10.\n";
    for (int i = 0; i < 3; ++i) {
        cout << "Intento #" << (i + 1) << ": ";
        cin >> intento;
        if (intento == numeroSecreto) {
            cout << "¡Correcto! Ganaste 5 monedas.\n";
            jugador.monedas += 5;
            return;
        } else {
            cout << "Incorrecto.\n";
        }
    }
    cout << "Perdiste. El número era: " << numeroSecreto << "\n";
}

void jugarTrivia() {
    int puntos = 0;
    char r;
    cout << "\n[Trivia]\n1. ¿Lenguaje actual? (A) Python (B) Java (C) C++\n> "; cin >> r;
    if (r == 'C' || r == 'c') puntos++;
    cout << "2. ¿Capital de El Salvador? (A) San Salvador (B) Santa Ana (C) La Unión\n> "; cin >> r;
    if (r == 'A' || r == 'a') puntos++;
    cout << "3. ¿5 x 3? (A) 15 (B) 10 (C) 20\n> "; cin >> r;
    if (r == 'A' || r == 'a') puntos++;
    if (puntos >= 2) {
        cout << "¡Ganaste! +5 monedas.\n";
        jugador.monedas += 5;
    } else {
        cout << "Fallaste la trivia.\n";
    }
}

void jugarParOImpar() {
    int num = rand() % 10 + 1;
    char eleccion;
    cout << "\n[Par o Impar] Elige P o I: ";
    cin >> eleccion;
    cout << "Número generado: " << num << "\n";
    bool par = (num % 2 == 0);
    if ((par && (eleccion == 'P' || eleccion == 'p')) ||
        (!par && (eleccion == 'I' || eleccion == 'i'))) {
        cout << "¡Ganaste! +3 monedas.\n";
        jugador.monedas += 3;
    } else {
        cout << "Fallaste.\n";
    }
}

#endif
