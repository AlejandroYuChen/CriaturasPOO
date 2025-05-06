#include "Volador.h"
#include <iostream>

Volador::Volador(const std::string& nombre, int salud, int fuerza)
    : Criatura(nombre, salud, fuerza) {}

void Volador::volar() {
    std::cout << nombre << " vuela alto en el cielo.\n";
}