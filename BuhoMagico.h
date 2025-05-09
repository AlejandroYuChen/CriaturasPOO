#ifndef BUHOMAGICO_H
#define BUHOMAGICO_H

#include "Criatura.h"
#include "Magico.h"

using namespace std;

class BuhoMagico : public Criatura, public Magico {
public:
    BuhoMagico(const string& nombre);

    void actuar(Nodo* nodo, mt19937& rng, vector<shared_ptr<Criatura>>& nuevas_criaturas) override;
    string getTipo() const override;
};

#endif // BUHOMAGICO_H