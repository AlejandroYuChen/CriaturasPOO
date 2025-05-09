#include "BuhoMagico.h"
#include <iostream>
#include <random>
#include <algorithm>
#include "Zorro.h"
#include "Conejo.h"

using namespace std;

BuhoMagico::BuhoMagico(const string& nombre)
    : Criatura(nombre), Magico("Hechizo Infravision") {}

void BuhoMagico::actuar(Nodo* nodo, mt19937& rng, vector<shared_ptr<Criatura>>& nuevas_criaturas) {
    edad++;

    // Movimiento aleatorio a un nodo vecino, igual que Zorro/Conejo
    vector<Nodo*> vecinos;
    if (nodo->arriba) vecinos.push_back(nodo->arriba);
    if (nodo->abajo) vecinos.push_back(nodo->abajo);
    if (nodo->izquierda) vecinos.push_back(nodo->izquierda);
    if (nodo->derecha) vecinos.push_back(nodo->derecha);
    if (!vecinos.empty()) {
        uniform_int_distribution<size_t> dist(0, vecinos.size() - 1);
        Nodo* nuevoNodo = vecinos[dist(rng)];
        nuevoNodo->criaturas.push_back(shared_from_this());
        cout << nombre << " vuela del nodo (" << nodo->x << "," << nodo->y
                  << ") a (" << nuevoNodo->x << "," << nuevoNodo->y << ")" << endl;
    }

    // Cazar CONEJOS o ZORROS (solo si no es él mismo y están vivos)
    for (auto& c : nodo->criaturas) {
        if (c.get() != this && (c->getTipo() == "Conejo" || c->getTipo() == "Zorro") && c->estaViva()) {
            c->morir();
            cout << nombre << " ha cazado a " << c->getNombre() << "!" << endl;
            break; // Solo casará uno por turno
        }
    }

    // Reproducción: si hay otro búho mágico vivo en el mismo nodo y el búho tiene más de 3 turnos
    int conteo = 0;
    for (auto& c : nodo->criaturas)
        if (c->getTipo() == "BúhoMágico" && c.get() != this && c->estaViva())
            conteo++;

    if (edad > 3 && conteo > 0) {
        auto bebe = make_shared<BuhoMagico>("PollueloMágico");
        nuevas_criaturas.push_back(bebe);
        cout << nombre << " ayudó a reproducirse en (" << nodo->x << "," << nodo->y << ")" << endl;
    }

    // Magia
    if (puedeUsarMagia()) {
        usarMagia();
    }

    // Probabilidad de morir de causa natural (1 entre 25)
    uniform_int_distribution<int> muerte(0, 24);
    if (muerte(rng) == 0) {
        morir();
        cout << nombre << " ha muerto de forma natural en (" << nodo->x << "," << nodo->y << ")" << endl;
    }
}

string BuhoMagico::getTipo() const {
    return "BúhoMágico";
}