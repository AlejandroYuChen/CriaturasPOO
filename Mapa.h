#ifndef MAPA_H
#define MAPA_H

#include <vector>
#include "Nodo.h"

using namespace std;

class Mapa {
    int ancho, alto;
    vector<vector<Nodo*>> grid;
public:
    Mapa(int ancho_, int alto_);
    Nodo* getNodo(int x, int y);
    vector<Nodo*>& operator[](int y);
    ~Mapa();
};

#endif //MAPA_H
