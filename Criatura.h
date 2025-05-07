#ifndef CRIATURA_H
#define CRIATURA_H

#include <string>
#include <vector>
#include <memory>
#include <random>
#include "Nodo.h"

using namespace std;

class Criatura : public enable_shared_from_this<Criatura> {
protected:
    string nombre;
    bool viva = true;
public:
    Criatura(string nombre_);
    virtual void actuar(Nodo* nodo, mt19937& rng,vector<shared_ptr<Criatura>>& nuevas_criaturas) = 0;
    virtual string getTipo() const = 0;
    virtual string getNombre() const;
    bool estaViva() const;
    void morir();
    virtual ~Criatura() {}
};

#endif // CRIATURA_H