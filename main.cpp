#include <iostream>
#include <random>
#include <memory>
#include <algorithm>
#include <vector>

#include "BuhoMagico.h"
#include "Criatura.h"
#include "Mapa.h"
#include "Conejo.h"
#include "Zorro.h"
#include "Nodo.h"

using namespace std;

int main() {
    // Se crea un objeto Mapa de tamaño 5x5
    Mapa mapa(5, 5);

    // Inicializa el generador de números aleatorios
    random_device rd;
    mt19937 rng(rd());

    // Crea dos objetos Conejo con nombres "Bugs" y "Lola"
    auto conejo1 = make_shared<Conejo>("Bugs");
    auto conejo2 = make_shared<Conejo>("Lola");

    // Crea dos objetos Zorro con nombres "Foxy" y "Zorro"
    auto zorro1 = make_shared<Zorro>("Foxy");
    auto zorro2 = make_shared<Zorro>("Zorro");

    // Crea un objeto BuhoMagico con nombre "Buho"
    auto buho1 = make_shared<BuhoMagico>("Buho");

    // Coloca el búho en la posición (2,2) del mapa
    mapa.getNodo(2, 2)->criaturas.push_back(buho1);


    mapa.getNodo(1, 1)->criaturas.push_back(conejo1); // Bugs en (1,1)
    mapa.getNodo(1, 3)->criaturas.push_back(conejo2); // Lola en (1,3)


    mapa.getNodo(4, 0)->criaturas.push_back(zorro1); // Foxy en (4,0)
    mapa.getNodo(0, 4)->criaturas.push_back(zorro2); // Zorro en (0,4)

    // Bucle principal de simulación, para 10 turnos
    for (int turno = 1; turno <= 10; ++turno) {
        cout << "\n--- Turno " << turno << " ---" << endl;
        // Vector para almacenar nuevas criaturas creadas durante el turno
        vector<shared_ptr<Criatura>> nuevas_criaturas;

        // Recorre todos los nodos del mapa para que cada criatura realice su acción
        for (int y = 0; y < 5; ++y)
            for (int x = 0; x < 5; ++x) {
                Nodo* n = mapa.getNodo(x, y);
                // Hace una copia de la lista de criaturas, para evitar problemas si alguna se elimina o añade nuevas
                auto criaturas_copia = n->criaturas;
                // Cada criatura actúa si está viva
                for (auto& c : criaturas_copia) {
                    if (c->estaViva())
                        c->actuar(n, rng, nuevas_criaturas);
                }
            }

        // Elimina criaturas muertas de todos los nodos
        for (int y = 0; y < 5; ++y)
            for (int x = 0; x < 5; ++x) {
                Nodo* n = mapa.getNodo(x, y);
                n->criaturas.erase(
                    remove_if(n->criaturas.begin(), n->criaturas.end(),
                        [](const shared_ptr<Criatura>& c) { return !c->estaViva(); }),
                    n->criaturas.end());
            }

        // Añade todas las nuevas criaturas creadas durante el turno al nodo central (2,2)
        for (auto& c : nuevas_criaturas) {
            mapa.getNodo(2, 2)->criaturas.push_back(c);
        }
    }
    return 0;
}