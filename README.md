# CriaturasPOO

## 📘 Descripción del proyecto

**CriaturasPOO** es una simulación de ecosistema interactivo programada en C++ donde diferentes criaturas, como conejos, zorros y un búho mágico, coexisten y compiten en un mapa cuadrado. Cada criatura tiene capacidades y comportamientos distintos, lo que permite observar cómo diversos agentes interactúan bajo reglas sencillas.  
Este proyecto está dirigido a estudiantes, docentes y entusiastas de la programación orientada a objetos y simulación de sistemas, especialmente aquellos interesados en aprender conceptos de herencia, polimorfismo y diseño de ecosistemas artificiales.

---

## 🧑‍💻 Manual del usuario

### Funcionalidades principales

- Simula un ecosistema con diferentes criaturas en un mapa de tamaño fijo (5x5).
- Cada tipo de criatura (conejo, zorro, búho mágico) tiene comportamiento propio por turno.
- El usuario puede observar la evolución del sistema durante 10 turnos, presentando mensajes de estado por consola.
- Las criaturas pueden moverse, interactuar entre sí, desaparecer al morir y, en ciertos casos, usar habilidades especiales (como la magia).
- Se pueden añadir más criaturas o cambiar su comportamiento fácilmente ampliando el código.

### Uso paso a paso

1. **Compila y ejecuta la aplicación** siguiendo las instrucciones de más abajo según tu sistema operativo.
2. Al ejecutar el programa, verás una serie de mensajes en la consola organizados por "Turno", donde se observa lo que ocurre en el ecosistema paso a paso.
3. Observa cómo evolucionan las poblaciones de criaturas turno a turno.

### Ejemplo de salida de consola

```
Bugs salta del nodo (2,2) a (1,2)
Foxy se mueve del nodo (2,2) a (3,2)
Foxy ayudó a reproducirse en (3,2)
```

### Requisitos mínimos

- Sistema operativo con soporte para C++ moderno (Windows, Linux o macOS).
- Compilador compatible con C++20 (por ejemplo, GCC 10+, Clang 11+, MSVC 2019+).
- Al menos 2 GB de RAM.
- No se requieren permisos especiales ni una interfaz gráfica; todo sucede en consola.

---

## 🛠️ Instrucciones de compilación y ejecución

### Clonar el repositorio

```
sh git clone <URL_DEL_REPOSITORIO> cd CriaturasPOO
```


### Instalación de dependencias

No se requieren librerías ni dependencias externas más allá de un compilador moderno de C++. Puedes usar [CMake](https://cmake.org/) para gestionar la compilación.

### Compilación con CMake

1. Crea una carpeta para los archivos generados:
   ```sh
   mkdir build
   cd build
   ```
2. Genera los archivos del proyecto y compila:
   ```sh
   cmake ..
   cmake --build .
   ```
   Esto generará el ejecutable `CriaturasPOO` en la carpeta `build`.

### Ejecución

- En Windows:
  ```sh
  .\CriaturasPOO.exe
  ```
- En Linux/macOS:
  ```sh
  ./CriaturasPOO
  ```

La aplicación correrá mostrando la simulación por consola durante 10 turnos.

---

## 🗂️ Estructura del código fuente

- **main.cpp**  
  Punto de entrada principal, donde se inicializa el mapa, las criaturas y se ejecuta la simulación turno a turno.

- **CMakeLists.txt**  
  Archivo de configuración de CMake para gestionar la compilación del proyecto.

- **Criatura.h / Criatura.cpp**  
  Clase base abstracta para todas las criaturas. Define interfaz y comportamiento común.

- **Conejo.h / Conejo.cpp**  
  Clase derivada que modela los conejos y sus acciones como presas.

- **Zorro.h / Zorro.cpp**  
  Clase derivada para los zorros, que actúan como predadores en el ecosistema.

- **BuhoMagico.h / BuhoMagico.cpp**  
  Clase derivada que representa un búho con habilidades mágicas especiales.

- **Magico.h / Magico.cpp**  
  Interfaz y lógica común para criaturas con habilidades mágicas.

- **Mapa.h / Mapa.cpp**  
  Clase que modela el mapa bidimensional y gestiona el acceso y manipulación de los nodos.

- **Nodo.h / Nodo.cpp**  
  Estructura/nodo de cada celda del mapa, incluye las criaturas que la ocupan y conexiones con vecinos.

---

### Créditos

Shi Jian Alejandro Yu Chen
