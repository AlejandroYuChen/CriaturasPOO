#include "Mapa.h"

using namespace std;

Mapa::Mapa(int ancho_, int alto_) : ancho(ancho_), alto(alto_) {
    grid.resize(alto, vector<Nodo*>(ancho, nullptr));
    for (int y = 0; y < alto; ++y) {
        for (int x = 0; x < ancho; ++x) {
            grid[y][x] = new Nodo(x, y);
        }
    }
    for (int y = 0; y < alto; ++y) {
        for (int x = 0; x < ancho; ++x) {
            if (y > 0) grid[y][x]->arriba = grid[y - 1][x];
            if (y < alto - 1) grid[y][x]->abajo = grid[y + 1][x];
            if (x > 0) grid[y][x]->izquierda = grid[y][x - 1];
            if (x < ancho - 1) grid[y][x]->derecha = grid[y][x + 1];
        }
    }
}

Nodo* Mapa::getNodo(int x, int y) {
    if (x >= 0 && x < ancho && y >= 0 && y < alto)
        return grid[y][x];
    return nullptr;
}

vector<Nodo*>& Mapa::operator[](int y) { return grid[y]; }

Mapa::~Mapa() {
    for (auto& fila : grid)
        for (auto nodo : fila)
            delete nodo;
}
