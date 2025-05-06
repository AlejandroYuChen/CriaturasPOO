#ifndef DRAGON_H
#define DRAGON_H

#include "Bestia.h"
#include "Volador.h"

class Dragon : public Bestia, public Volador {
public:
    Dragon(const std::string& nombre, int salud, int fuerza);

    void actuar() override;
    void reproducirse() override;
    void moverse() override;
    void morir() override;
};

#endif // DRAGON_H