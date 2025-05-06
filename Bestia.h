#ifndef BESTIA_H
#define BESTIA_H

#include "Criatura.h"

class Bestia :  virtual public Criatura {
public:
    Bestia(const std::string& nombre, int salud, int fuerza);

    void actuar() override;
    void reproducirse() override;
    void moverse() override;
    void morir() override;
};

#endif // BESTIA_H