#include "Dragon.h"
#include <iostream>

Dragon::Dragon(const std::string& nombre, int salud, int fuerza)
    : Criatura(nombre, salud, fuerza), Bestia(nombre, salud, fuerza), Volador(nombre, salud, fuerza) {}

void Dragon::actuar() {
    std::cout << nombre << " escupe fuego y vuela.\n";
}

void Dragon::reproducirse() {
    std::cout << nombre << " pone un huevo enorme.\n";
}

void Dragon::moverse() {
    Volador::volar();
}

void Dragon::morir() {
    std::cout << nombre << " cae del cielo envuelto en llamas.\n";
}