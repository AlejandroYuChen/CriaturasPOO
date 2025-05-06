#include "Criatura.h"

// Constructor por defecto
Criatura::Criatura() : nombre(""), salud(100), fuerza(10) {}

// Constructor con parámetros
Criatura::Criatura(const std::string& nombre, int salud, int fuerza) 
    : nombre(nombre), salud(salud), fuerza(fuerza) {}

// Métodos getter
std::string Criatura::getNombre() const { return nombre; }
int Criatura::getSalud() const { return salud; }
int Criatura::getFuerza() const { return fuerza; }

// Métodos setter
void Criatura::setNombre(const std::string& nuevoNombre) { nombre = nuevoNombre; }
void Criatura::setSalud(int nuevaSalud) { salud = nuevaSalud; }
void Criatura::setFuerza(int nuevaFuerza) { fuerza = nuevaFuerza; }

// Destructor virtual
Criatura::~Criatura() = default;