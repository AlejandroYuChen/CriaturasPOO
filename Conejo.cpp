#include "Conejo.h"
#include <iostream>
#include <random>
#include <algorithm>

using namespace std;

// Constructor que inicializa al conejo con un nombre
Conejo::Conejo(string nombre_) : Criatura(nombre_) {}

// Acción que realiza el conejo en cada turno
void Conejo::actuar(Nodo* nodo, mt19937& rng, vector<shared_ptr<Criatura>>& nuevas_criaturas) {
    edad++;  // El conejo envejece cada turno

    // Se obtiene la lista de nodos vecinos a los que puede moverse
    vector<Nodo*> vecinos;
    if (nodo->arriba) vecinos.push_back(nodo->arriba);
    if (nodo->abajo) vecinos.push_back(nodo->abajo);
    if (nodo->izquierda) vecinos.push_back(nodo->izquierda);
    if (nodo->derecha) vecinos.push_back(nodo->derecha);

    // Movimiento a un nodo vecino aleatorio si hay vecinos disponibles
    if (!vecinos.empty()) {
        uniform_int_distribution<size_t> dist(0, vecinos.size() - 1);
        Nodo* nuevoNodo = vecinos[dist(rng)];
        nuevoNodo->criaturas.push_back(shared_from_this());
        cout << nombre << " salta del nodo (" << nodo->x << "," << nodo->y
                  << ") a (" << nuevoNodo->x << "," << nuevoNodo->y << ")" << endl;
    }

    // Conteo de otros conejos vivos en el nodo para determinar si es posible reproducirse
    int conteo = 0;
    for (auto& c : nodo->criaturas)
        if (c->getTipo() == "Conejo" && c.get() != this && c->estaViva())
            conteo++;

    // Si el conejo es mayor de 3 turnos y hay otro conejo presente, se reproduce
    if (edad > 3 && conteo > 0) {
        auto bebe = make_shared<Conejo>("Gazapo");
        nuevas_criaturas.push_back(bebe);
        cout << nombre << " ayudo a reproducirse en (" << nodo->x << "," << nodo->y << ")" << endl;
    }

    // Probabilidad de morir de causa natural en este turno (1 entre 20)
    uniform_int_distribution<int> muerte(0, 19);
    if (muerte(rng) == 0) {
        morir();
        cout << nombre << " ha muerto de forma natural en (" << nodo->x << "," << nodo->y << ")" << endl;
    }
}

// Devuelve el tipo de la criatura para identificarla como "Conejo"
string Conejo::getTipo() const { return "Conejo"; }