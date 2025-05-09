#ifndef ZORRO_H
#define ZORRO_H

#include "Criatura.h"

using namespace std;

// Clase derivada de Criatura que representa al zorro dentro del ecosistema
class Zorro : public Criatura {
public:
    // Constructor: inicializa el zorro con un nombre
    Zorro(string nombre_);

    // Implementa la acción que realiza el zorro en cada turno
    void actuar(Nodo* nodo, mt19937& rng, vector<shared_ptr<Criatura>>& nuevas_criaturas) override;

    // Devuelve el tipo de la criatura ("Zorro")
    string getTipo() const override;
};

#endif // ZORRO_H