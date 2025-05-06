#include "Sirena.h"
#include <iostream>

Sirena::Sirena(const std::string& nombre, int salud, int fuerza)
    : Criatura(nombre, salud, fuerza), Magica(nombre, salud, fuerza), Acuatica(nombre, salud, fuerza) {}

void Sirena::actuar() {
    std::cout << nombre << " entona un canto mágico y nada.\n";
}

void Sirena::reproducirse() {
    std::cout << nombre << " canta para atraer pareja.\n";
}

void Sirena::moverse() {
    Acuatica::nadar();
}

void Sirena::morir() {
    std::cout << nombre << " se disuelve en espuma sobre el mar.\n";
}