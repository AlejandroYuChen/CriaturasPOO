#ifndef MAGICA_H
#define MAGICA_H

#include "Criatura.h"

class Magica :  virtual public Criatura {
public:
    Magica(const std::string& nombre, int salud, int fuerza);

    void actuar() override;
    void reproducirse() override;
    void moverse() override;
    void morir() override;
};

#endif // MAGICA_H