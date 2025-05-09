#ifndef NODO_H
#define NODO_H
#include <vector>
#include <memory>

using namespace std;

// Declaración adelantada para evitar dependencias circulares
class Criatura;

// Estructura que representa una celda (nodo) en el mapa
struct Nodo {
    int x, y; // Coordenadas de este nodo dentro del mapa

    // Punteros a los nodos vecinos, permiten la navegación entre celdas adyacentes
    Nodo* arriba;
    Nodo* abajo;
    Nodo* izquierda;
    Nodo* derecha;

    // Contenedor de criaturas presentes en este nodo
    vector<shared_ptr<Criatura>> criaturas;

    // Constructor, inicializa las coordenadas y los punteros de vecinos en nullptr
    Nodo(int x_, int y_);
};

#endif //NODO_H