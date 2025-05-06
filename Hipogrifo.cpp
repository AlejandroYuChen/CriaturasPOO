#include "Hipogrifo.h"
#include <iostream>

Hipogrifo::Hipogrifo(const std::string& nombre, int salud, int fuerza)
    : Criatura(nombre, salud, fuerza), Volador(nombre, salud, fuerza), Acuatica(nombre, salud, fuerza) {}

void Hipogrifo::actuar() {
    std::cout << nombre << " alterna entre volar y nadar hábilmente.\n";
}

void Hipogrifo::reproducirse() {
    std::cout << nombre << " baila en la orilla para cortejar.\n";
}

void Hipogrifo::moverse() {
    std::cout << nombre << " puede tanto volar como nadar:\n";
    Volador::volar();
    Acuatica::nadar();
}

void Hipogrifo::morir() {
    std::cout << nombre << " se desvanece ante la tormenta.\n";
}