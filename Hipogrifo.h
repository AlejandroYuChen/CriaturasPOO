#ifndef HIPOGRIIFO_H
#define HIPOGRIIFO_H

#include "Volador.h"
#include "Acuatica.h"

class Hipogrifo : public Volador, public Acuatica {
public:
    Hipogrifo(const std::string& nombre, int salud, int fuerza);

    void actuar() override;
    void reproducirse() override;
    void moverse() override;
    void morir() override;
};

#endif // HIPOGRIIFO_H