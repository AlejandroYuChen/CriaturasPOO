#include "Nodo.h"
#include "Criatura.h"

// Constructor: asigna las coordenadas e inicializa los vecinos a nullptr
Nodo::Nodo(int x_, int y_)
    : x(x_), y(y_), arriba(nullptr), abajo(nullptr), izquierda(nullptr), derecha(nullptr) {}