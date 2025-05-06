#ifndef SIRENA_H
#define SIRENA_H

#include "Magica.h"
#include "Acuatica.h"
#include <string>

class Sirena : public Magica, public Acuatica {
public:
    Sirena(const std::string& nombre, int salud, int fuerza);

    void actuar() override;
    void reproducirse() override;
    void moverse() override;
    void morir() override;
};



#endif //SIRENA_H