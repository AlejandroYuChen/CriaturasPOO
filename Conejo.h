#ifndef CONEJO_H
#define CONEJO_H

#include "Criatura.h"

using namespace std;

class Conejo : public Criatura {
public:
    Conejo(string nombre_);
    void actuar(Nodo* nodo,mt19937& rng, vector<shared_ptr<Criatura>>& nuevas_criaturas) override;
    std::string getTipo() const override;
};

#endif // CONEJO_H