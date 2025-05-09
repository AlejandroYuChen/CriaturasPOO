#include "Criatura.h"
#include "Zorro.h"
#include "Conejo.h"

using namespace std;

// Constructor: inicializa el nombre de la criatura
Criatura::Criatura(string nombre_) : nombre(nombre_) {}

// Devuelve el nombre de la criatura
string Criatura::getNombre() const { return nombre; }

// Indica si la criatura está viva
bool Criatura::estaViva() const { return viva; }

// Marca la criatura como muerta
void Criatura::morir() { viva = false; }