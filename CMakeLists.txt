cmake_minimum_required(VERSION 3.30)
project(CriaturasPOO)

set(CMAKE_CXX_STANDARD 20)

add_executable(CriaturasPOO main.cpp
        criatura.cpp
        criatura.h
        Nodo.cpp
        Nodo.h
        Mapa.cpp
        Mapa.h
        Bestia.cpp
        Bestia.h
        Magica.cpp
        Magica.h
        Volador.cpp
        Volador.h
        Acuatica.cpp
        Acuatica.h
        Dragon.cpp
        Dragon.h
        Sirena.cpp
        Sirena.h
        Hipogrifo.cpp
        Hipogrifo.h
)
