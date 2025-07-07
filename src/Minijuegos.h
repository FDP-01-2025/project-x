#ifndef MINIJUEGOS_H
#define MINIJUEGOS_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Jugador.h"
using namespace std;

void subirNivelSiCorresponde() {
    if (jugador.experiencia >= 30) {
        jugador.nivel++;
        jugador.vida = 100 + (jugador.nivel - 1) * 10;
        jugador.experiencia = 0;
        cout << "¡Subiste a nivel " << jugador.nivel << "! Tu vida máxima y fuerza aumentaron.\n";
    }
}

// Minijuegos nivel 1
void jugarAdivinaNumero() {
    int num = rand() % 10 + 1, intento;
    cout << "\n[Adivina el Numero 1-10]\n";
    for (int i = 0; i < 3; ++i) {
        cout << "Intento #" << (i + 1) << ": ";
        cin >> intento;
        if (intento == num) {
            cout << "Correcto! +5 monedas y +10 de experiencia\n";
            jugador.monedas += 5;
            jugador.experiencia += 10;
            subirNivelSiCorresponde();
            return;
        } else {
            cout << "Incorrecto\n";
        }
    }
    cout << "Perdiste. El número era: " << num << endl;
    cout << "Has perdido este minijuego.\n";
}

void jugarTrivia() {
    int puntos = 0;
    char r;
    cout << "\n[Trivia Secret Con+inen+]\n1. Que lenguaje estas usando? (A) Python (B) Java (C) C++\n> "; cin >> r;
    if (r == 'C' || r == 'c') puntos++;
    cout << "2. Capital de El Salvador? (A) San Salvador (B) Santa Ana (C) La Union\n> "; cin >> r;
    if (r == 'A' || r == 'a') puntos++;
    cout << "3. ¿Cuanto es 5 x 3? (A) 15 (B) 10 (C) 20\n> "; cin >> r;
    if (r == 'A' || r == 'a') puntos++;
    if (puntos >= 2) {
        cout << "¡Ganaste! +5 monedas y +10 de experiencia\n";
        jugador.monedas += 5;
        jugador.experiencia += 10;
        subirNivelSiCorresponde();
    } else {
        cout << "Fallaste la trivia.\n";
        cout << "Has perdido este minijuego.\n";
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
        cout << "¡Ganaste! +3 monedas y +10 de experiencia.\n";
        jugador.monedas += 3;
        jugador.experiencia += 10;
        subirNivelSiCorresponde();
    } else {
        cout << "Fallaste.\n";
        cout << "Has perdido este minijuego.\n";
    }
}

// Minijuegos nivel 2 
void minijuegoReflejos() {
    string secuencias[] = {"asd", "qwe", "zxc", "wsad"};
    int idx = rand() % 4;
    string input;
    cout << "[Reflejos Secret Con+inen+] Escribe esta secuencia lo más rapido posible: " << secuencias[idx] << endl;
    cin >> input;
    if (input == secuencias[idx]) {
        cout << "¡Perfecto! +10 monedas y +15 de experiencia" << endl;
        jugador.monedas += 10;
        jugador.experiencia += 15;
        subirNivelSiCorresponde();
    } else {
        cout << "Fallaste, intenta ser mas rapido y exacto." << endl;
        cout << "Has perdido este minijuego.\n";
    }
}

void minijuegoDados() {
    int tuTiro = rand() % 6 + 1;
    int jefeTiro = rand() % 6 + 1;
    cout << "[Batalla de Dados Secret Con+inen+] Lanzando dados..." << endl;
    cout << "Tu dado: " << tuTiro << " | Dado del jefe: " << jefeTiro << endl;
    if (tuTiro > jefeTiro) {
        cout << "¡Ganaste la ronda! +5 monedas y +15 de experiencia." << endl;
        jugador.monedas += 5;
        jugador.experiencia += 15;
        subirNivelSiCorresponde();
    } else if (tuTiro < jefeTiro) {
        cout << "Perdiste la ronda. Sin recompensa." << endl;
        cout << "Has perdido este minijuego.\n";
    } else {
        cout << "Empate, lanza de nuevo la proxima vez." << endl;
        cout << "Has perdido este minijuego.\n";
    }
}

#endif