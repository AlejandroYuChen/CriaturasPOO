#include "Magica.h"
#include <iostream>

Magica::Magica(const std::string& nombre, int salud, int fuerza)
    : Criatura(nombre, salud, fuerza) {}

void Magica::actuar() {
    std::cout << nombre << " lanza un hechizo.\n";
}

void Magica::reproducirse() {
    std::cout << nombre << " crea magia para reproducirse.\n";
}

void Magica::moverse() {
    std::cout << nombre << " se desplaza flotando por el aire.\n";
}

void Magica::morir() {
    std::cout << nombre << " desaparece en una nube de polvo mágico.\n";
}