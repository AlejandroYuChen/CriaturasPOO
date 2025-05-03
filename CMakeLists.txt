cmake_minimum_required(VERSION 3.30)
project(CriaturasPOO)

set(CMAKE_CXX_STANDARD 20)

add_executable(CriaturasPOO main.cpp
        criatura.cpp
        criatura.h
        Nodo.cpp
        Nodo.h
        Metamorfita.cpp
        Metamorfita.h
        LentoDeRaiz.cpp
        LentoDeRaiz.h
        Albo.cpp
        Albo.h
        Mapa.cpp
        Mapa.h
        Centella.cpp
        Centella.h)
