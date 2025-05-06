#ifndef VOLADOR_H
#define VOLADOR_H

#include "Criatura.h"

class Volador : virtual public Criatura {
public:
    Volador(const std::string& nombre, int salud, int fuerza);

    virtual void volar();
};

#endif // VOLADOR_H