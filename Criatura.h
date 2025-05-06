//
// Created by Aleja on 5/3/2025.
//

#ifndef CRIATURA_H
#define CRIATURA_H

#include <string>
#include <iostream>

using namespace std;

class Criatura {
protected:
    string nombre;
    int salud;
    int fuerza;

public:
    // Constructor por defecto
    Criatura();

    // Constructor con parámetros
    Criatura(const std::string& nombre, int salud, int fuerza);

    // Métodos getter
    std::string getNombre() const;
    int getSalud() const;
    int getFuerza() const;

    // Métodos setter
    void setNombre(const std::string& nuevoNombre);
    void setSalud(int nuevaSalud);
    void setFuerza(int nuevaFuerza);

    // Métodos virtuales puros
    virtual void actuar() = 0;
    virtual void reproducirse() = 0;
    virtual void moverse() = 0;
    virtual void morir() = 0;

    // Destructor virtual
    virtual ~Criatura();
};




#endif //CRIATURA_H
