#ifndef ZORRO_H
#define ZORRO_H


#include "Criatura.h"

using namespace std;

class Zorro : public Criatura {
public:
    Zorro(string nombre_);
    void actuar(Nodo* nodo, mt19937& rng, vector<shared_ptr<Criatura>>& nuevas_criaturas) override;
    string getTipo() const override;
};

#endif // ZORRO_H