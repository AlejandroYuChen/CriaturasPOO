#include "Magico.h"
#include <iostream>

Magico::Magico(const std::string& poder) : poder_magico(poder) {}

bool Magico::puedeUsarMagia() const {
    return magia_disponible;
}

void Magico::usarMagia() {
    if (magia_disponible) {
        std::cout << "¡Usando magia: " << poder_magico << "!" << std::endl;
        // Lógica de magia...
        magia_disponible = false; // Ejemplo: solo puede usarse una vez
    }
}