#include "Criatura.h"

using namespace std;

Criatura::Criatura(string nombre_) : nombre(nombre_) {}

string Criatura::getNombre() const { return nombre; }

bool Criatura::estaViva() const { return viva; }

void Criatura::morir() { viva = false; }