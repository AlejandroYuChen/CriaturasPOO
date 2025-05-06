#include "Acuatica.h"
#include <iostream>

Acuatica::Acuatica(const std::string& nombre, int salud, int fuerza)
    : Criatura(nombre, salud, fuerza) {}

void Acuatica::nadar() {
    std::cout << nombre << " nada velozmente en el agua.\n";
}