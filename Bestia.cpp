#include "Bestia.h"
#include <iostream>

Bestia::Bestia(const std::string& nombre, int salud, int fuerza)
    : Criatura(nombre, salud, fuerza) {}

void Bestia::actuar() {
    std::cout << nombre << " ruge ferozmente.\n";
}

void Bestia::reproducirse() {
    std::cout << nombre << " busca pareja bestial.\n";
}

void Bestia::moverse() {
    std::cout << nombre << " corre rápido por la tierra.\n";
}

void Bestia::morir() {
    std::cout << nombre << " cae con un último rugido.\n";
}