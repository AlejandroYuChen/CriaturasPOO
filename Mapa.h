#ifndef MAPA_H
#define MAPA_H

#include <vector>
#include "Nodo.h"

using namespace std;

// Clase que representa el mapa del ecosistema, compuesto por una grilla de nodos
class Mapa {
    int ancho, alto;                      // Dimensiones del mapa
    vector<vector<Nodo*>> grid;           // Matriz de punteros a nodos
public:
    // Constructor: crea la grilla y enlaza los nodos vecinos
    Mapa(int ancho_, int alto_);

    // Devuelve un puntero al nodo en la posición (x, y), o nullptr si está fuera de rango
    Nodo* getNodo(int x, int y);

    // Permite el acceso directo a las filas del grid mediante operador []
    vector<Nodo*>& operator[](int y);

    // Destructor: se encarga de liberar la memoria de los nodos creados dinámicamente
    ~Mapa();
};

#endif //MAPA_H