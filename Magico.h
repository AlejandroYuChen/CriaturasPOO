#ifndef MAGICO_H
#define MAGICO_H

#include <string>

using namespace std;

class Magico {
protected:
    string poder_magico;
    bool magia_disponible = true;
public:
    Magico(const string& poder);

    bool puedeUsarMagia() const;
    void usarMagia();
    virtual ~Magico() = default;
};

#endif // MAGICO_H