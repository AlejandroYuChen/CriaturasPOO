#include "Zorro.h"
#include <iostream>
#include <random>
#include <algorithm>

using namespace std;

// Constructor: inicializa el nombre del zorro
Zorro::Zorro(string nombre_) : Criatura(nombre_) {}

// Acción del zorro en cada turno
void Zorro::actuar(Nodo* nodo, mt19937& rng, vector<shared_ptr<Criatura>>& nuevas_criaturas) {
    edad++; // El zorro envejece con cada turno

    // Recopila los nodos vecinos a los que el zorro puede moverse
    vector<Nodo*> vecinos;
    if (nodo->arriba) vecinos.push_back(nodo->arriba);
    if (nodo->abajo) vecinos.push_back(nodo->abajo);
    if (nodo->izquierda) vecinos.push_back(nodo->izquierda);
    if (nodo->derecha) vecinos.push_back(nodo->derecha);

    // Movimiento aleatorio a uno de los nodos vecinos si existen
    if (!vecinos.empty()) {
        uniform_int_distribution<size_t> dist(0, vecinos.size() - 1);
        Nodo* nuevoNodo = vecinos[dist(rng)];
        nuevoNodo->criaturas.push_back(shared_from_this());
        cout << nombre << " se mueve del nodo (" << nodo->x << "," << nodo->y
                  << ") a (" << nuevoNodo->x << "," << nuevoNodo->y << ")" << endl;
    }

    // Búsqueda de un conejo en el nodo actual para cazarlo
    for (auto& c : nodo->criaturas) {
        if (c.get() != this && c->getTipo() == "Conejo" && c->estaViva()) {
            c->morir(); // El zorro caza (elimina) al conejo
            cout << nombre << " ha cazado a " << c->getNombre() << "!" << endl;
            break; // Sólo caza un conejo por turno
        }
    }

    // Cuenta los zorros vecinos vivos en el nodo para determinar si puede reproducirse
    int conteo = 0;
    for (auto& c : nodo->criaturas)
        if (c->getTipo() == "Zorro" && c.get() != this && c->estaViva())
            conteo++;

    // Reproducción: si es mayor de 3 turnos y hay otro zorro, crea un cachorro
    if (edad > 3 && conteo > 0) {
        auto bebe = make_shared<Zorro>("Cachorro");
        nuevas_criaturas.push_back(bebe);
        cout << nombre << " ayudo a reproducirse en (" << nodo->x << "," << nodo->y << ")" << endl;
    }

    // Probabilidad de morir de forma natural (1 entre 30) en cada turno
    uniform_int_distribution<int> muerte(0, 29);
    if (muerte(rng) == 0) {
        morir();
        cout << nombre << " ha muerto de forma natural en (" << nodo->x << "," << nodo->y << ")" << endl;
    }
}

// Devuelve el tipo de criatura para identificarla como "Zorro"
string Zorro::getTipo() const { return "Zorro"; }