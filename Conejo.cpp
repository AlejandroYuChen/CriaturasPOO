#include "Conejo.h"
#include <iostream>
#include <random>
#include <algorithm>

using namespace std;

Conejo::Conejo(string nombre_) : Criatura(nombre_) {}

void Conejo::actuar(Nodo* nodo, mt19937& rng, vector<shared_ptr<Criatura>>& nuevas_criaturas) {
    vector<Nodo*> vecinos;
    if (nodo->arriba) vecinos.push_back(nodo->arriba);
    if (nodo->abajo) vecinos.push_back(nodo->abajo);
    if (nodo->izquierda) vecinos.push_back(nodo->izquierda);
    if (nodo->derecha) vecinos.push_back(nodo->derecha);

    if (!vecinos.empty()) {
        uniform_int_distribution<size_t> dist(0, vecinos.size() - 1);
        Nodo* nuevoNodo = vecinos[dist(rng)];
        nuevoNodo->criaturas.push_back(shared_from_this());
        cout << nombre << " salta del nodo (" << nodo->x << "," << nodo->y
                  << ") a (" << nuevoNodo->x << "," << nuevoNodo->y << ")" << endl;
    }

    int conteo = 0;
    for (auto& c : nodo->criaturas)
        if (c->getTipo() == "Conejo" && c.get() != this && c->estaViva())
            conteo++;

    if (conteo > 0) {
        auto bebe = make_shared<Conejo>("Gazapo");
        nuevas_criaturas.push_back(bebe);
        cout << nombre << " ayudó a reproducirse en (" << nodo->x << "," << nodo->y << ")" << endl;
    }

    uniform_int_distribution<int> muerte(0, 19);
    if (muerte(rng) == 0) {
        morir();
        cout << nombre << " ha muerto de forma natural en (" << nodo->x << "," << nodo->y << ")" << endl;
    }
}

string Conejo::getTipo() const { return "Conejo"; }