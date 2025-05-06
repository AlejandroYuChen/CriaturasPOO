#ifndef ACUATICA_H
#define ACUATICA_H

#include "Criatura.h"

class Acuatica : virtual public Criatura {
public:
    Acuatica(const std::string& nombre, int salud, int fuerza);

    virtual void nadar();
};

#endif // ACUATICA_H