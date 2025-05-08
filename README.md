## 🦊🐇 Simulación de Ecosistema en C++

Este proyecto es una simulación básica de un ecosistema con conejos y zorros, implementada en C++. Utiliza una estructura de grilla (mapa) donde cada celda puede contener múltiples criaturas. Estas interactúan de manera aleatoria en cada turno, reproduciéndose, moviéndose y, en el caso de los zorros, cazando.

### 📦 Características

* Ecosistema representado como una grilla bidimensional (`Mapa`) de `Nodos` conectados.
* Dos tipos de criaturas:
    * **Conejos:** se reproducen si hay otro conejo en la misma celda y pueden morir aleatoriamente.
    * **Zorros:** cazan conejos, se reproducen si hay otro zorro, y también pueden morir aleatoriamente.
* Movimiento aleatorio entre celdas vecinas (arriba, abajo, izquierda, derecha).
* Lógica de reproducción y muerte integrada.
* Simulación por turnos con salida por consola.

### 📁 Estructura del Código

* **Nodo:** representa una celda del mapa, con punteros a vecinos y una lista de criaturas.
* **Criatura:** clase abstracta base para las criaturas.
* **Conejo y Zorro:** subclases con comportamiento específico para cada tipo de criatura.
* **Mapa:** genera una grilla conectada de nodos y facilita el acceso a ellos.
* **main():** inicializa el mapa, las criaturas y corre la simulación por 10 turnos.

### 🛠️ Requisitos

* Compilador C++ compatible con C++11 o superior (recomendado: `g++`, `clang++`, MSVC).
* Sistema con consola/terminal para ver la salida de la simulación.

### ▶️ Compilación y Ejecución

**Usando g++**

```bash
g++ -std=c++11 -o ecosistema CriaturasPOO
./ecosistema
```

🔄 Ejemplo de Salida

```
Bugs salta del nodo (2,2) a (1,2)
Foxy se mueve del nodo (2,2) a (3,2)
Foxy ayudó a reproducirse en (3,2)
```
