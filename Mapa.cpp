#include "Mapa.h"

using namespace std;

// Constructor: inicializa el grid y enlaza entre sí los nodos adyacentes
Mapa::Mapa(int ancho_, int alto_) : ancho(ancho_), alto(alto_) {
    grid.resize(alto, vector<Nodo*>(ancho, nullptr));
    // Se crean los nodos de la malla, uno por cada posición x,y
    for (int y = 0; y < alto; ++y) {
        for (int x = 0; x < ancho; ++x) {
            grid[y][x] = new Nodo(x, y);
        }
    }
    // Se conectan los nodos creados con sus vecinos (arriba, abajo, izquierda, derecha)
    for (int y = 0; y < alto; ++y) {
        for (int x = 0; x < ancho; ++x) {
            if (y > 0) grid[y][x]->arriba = grid[y - 1][x];
            if (y < alto - 1) grid[y][x]->abajo = grid[y + 1][x];
            if (x > 0) grid[y][x]->izquierda = grid[y][x - 1];
            if (x < ancho - 1) grid[y][x]->derecha = grid[y][x + 1];
        }
    }
}

// Devuelve el puntero al nodo en la posición (x, y), o nullptr si está fuera del mapa
Nodo* Mapa::getNodo(int x, int y) {
    if (x >= 0 && x < ancho && y >= 0 && y < alto)
        return grid[y][x];
    return nullptr;
}

// Permite acceder a la fila y-ésima de la grilla (útil para acceso directo)
vector<Nodo*>& Mapa::operator[](int y) { return grid[y]; }

// Destructor: elimina todos los nodos creados dinámicamente para evitar fugas de memoria
Mapa::~Mapa() {
    for (auto& fila : grid)
        for (auto nodo : fila)
            delete nodo;
}