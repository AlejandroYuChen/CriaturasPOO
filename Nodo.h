#ifndef NODO_H
#define NODO_H
#include <vector>
#include <memory>

using namespace std;

// Forward declaration
class Criatura;

struct Nodo {
    int x, y;
    Nodo* arriba;
    Nodo* abajo;
    Nodo* izquierda;
    Nodo* derecha;
    vector<shared_ptr<Criatura>> criaturas;

    Nodo(int x_, int y_);
};



#endif //NODO_H
