#include <iostream>
#include <random>
#include <memory>
#include <algorithm>
#include <vector>

#include "Criatura.h"
#include "Mapa.h"
#include "Conejo.h"
#include "Zorro.h"
#include "Nodo.h"


int main() {
    Mapa mapa(5, 5);
    std::random_device rd;
    std::mt19937 rng(rd());

    auto conejo = std::make_shared<Conejo>("Bugs");
    auto zorro = std::make_shared<Zorro>("Foxy");

    Nodo* nodo = mapa.getNodo(2, 2);
    nodo->criaturas.push_back(conejo);
    nodo->criaturas.push_back(zorro);

    for (int turno = 1; turno <= 10; ++turno) {
        std::cout << "\n--- Turno " << turno << " ---" << std::endl;
        std::vector<std::shared_ptr<Criatura>> nuevas_criaturas;
        for (int y = 0; y < 5; ++y)
            for (int x = 0; x < 5; ++x) {
                Nodo* n = mapa.getNodo(x, y);
                auto criaturas_copia = n->criaturas;
                for (auto& c : criaturas_copia) {
                    if (c->estaViva())
                        c->actuar(n, rng, nuevas_criaturas);
                }
            }

        for (int y = 0; y < 5; ++y)
            for (int x = 0; x < 5; ++x) {
                Nodo* n = mapa.getNodo(x, y);
                n->criaturas.erase(
                    std::remove_if(n->criaturas.begin(), n->criaturas.end(),
                        [](const std::shared_ptr<Criatura>& c) { return !c->estaViva(); }),
                    n->criaturas.end());
            }

        for (auto& c : nuevas_criaturas) {
            mapa.getNodo(2, 2)->criaturas.push_back(c);
        }
    }
    return 0;
}