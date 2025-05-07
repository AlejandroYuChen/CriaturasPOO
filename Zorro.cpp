#include "Zorro.h"
#include <iostream>
#include <random>
#include <algorithm>

using namespace std;

Zorro::Zorro(string nombre_) : Criatura(nombre_) {}

void Zorro::actuar(Nodo* nodo, mt19937& rng, vector<shared_ptr<Criatura>>& nuevas_criaturas) {
    vector<Nodo*> vecinos;
    if (nodo->arriba) vecinos.push_back(nodo->arriba);
    if (nodo->abajo) vecinos.push_back(nodo->abajo);
    if (nodo->izquierda) vecinos.push_back(nodo->izquierda);
    if (nodo->derecha) vecinos.push_back(nodo->derecha);

    if (!vecinos.empty()) {
        uniform_int_distribution<size_t> dist(0, vecinos.size() - 1);
        Nodo* nuevoNodo = vecinos[dist(rng)];
        nuevoNodo->criaturas.push_back(shared_from_this());
        cout << nombre << " se mueve del nodo (" << nodo->x << "," << nodo->y
                  << ") a (" << nuevoNodo->x << "," << nuevoNodo->y << ")" << endl;
    }

    for (auto& c : nodo->criaturas) {
        if (c.get() != this && c->getTipo() == "Conejo" && c->estaViva()) {
            c->morir();
            cout << nombre << " ha cazado a " << c->getNombre() << "!" << endl;
            break;
        }
    }

    int conteo = 0;
    for (auto& c : nodo->criaturas)
        if (c->getTipo() == "Zorro" && c.get() != this && c->estaViva())
            conteo++;

    if (conteo > 0) {
        auto bebe = make_shared<Zorro>("Cachorro");
        nuevas_criaturas.push_back(bebe);
        cout << nombre << " ayudó a reproducirse en (" << nodo->x << "," << nodo->y << ")" << endl;
    }

    uniform_int_distribution<int> muerte(0, 29);
    if (muerte(rng) == 0) {
        morir();
        cout << nombre << " ha muerto de forma natural en (" << nodo->x << "," << nodo->y << ")" << endl;
    }
}

string Zorro::getTipo() const { return "Zorro"; }