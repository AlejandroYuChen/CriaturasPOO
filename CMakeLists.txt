cmake_minimum_required(VERSION 3.30)
project(CriaturasPOO)

set(CMAKE_CXX_STANDARD 20)

add_executable(CriaturasPOO main.cpp
        criatura.cpp
        criatura.h
        Mapa.cpp
        Mapa.h
        Conejo.cpp
        Conejo.h
        Zorro.cpp
        Zorro.h
        Nodo.cpp
        Nodo.h
)
