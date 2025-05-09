#ifndef CRIATURA_H
#define CRIATURA_H

#include <string>
#include <vector>
#include <memory>
#include <random>
#include "json.hpp"
#include "Nodo.h"

using namespace std;
using json = nlohmann::json;

// Clase base abstracta para todas las criaturas del ecosistema
class Criatura : public enable_shared_from_this<Criatura> {
protected:
    string nombre; // Nombre de la criatura
    int edad = 0;  // Edad de la criatura (incrementa en cada turno)
    bool viva = true; // Indica si la criatura está viva o muerta
public:
    // Constructor que asigna un nombre a la criatura
    Criatura(string nombre_);

    // Método puro virtual: define el comportamiento de la criatura en un turno
    virtual void actuar(Nodo* nodo, mt19937& rng,vector<shared_ptr<Criatura>>& nuevas_criaturas) = 0;

    // Método puro virtual: devuelve el tipo de criatura ("Conejo" o "Zorro")
    virtual string getTipo() const = 0;

    // Devuelve el nombre de la criatura
    virtual string getNombre() const;

    // Indica si la criatura sigue con vida
    bool estaViva() const;

    // Marca la criatura como muerta
    void morir();

    // Destructor virtual
    virtual ~Criatura() {}
};

#endif // CRIATURA_H