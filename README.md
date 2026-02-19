# EDA - Algoritmos de Ordenación

## 📖 Descripción

Este repositorio es una recopilación de **algoritmos de ordenación** implementados en **C++**. Cada algoritmo ha sido desarrollado con fines educativos para comprender su funcionamiento, eficiencia y aplicaciones prácticas.

## 🎯 Objetivo

El objetivo de este proyecto es proporcionar una guía completa y estructurada de los algoritmos de ordenación más comunes, facilitando el aprendizaje mediante:

- **Implementaciones claras** en C++
- **Análisis detallado** de cada algoritmo
- **Documentación paso a paso** para comprender su funcionamiento

## 📂 Estructura del Repositorio

Cada algoritmo de ordenación se encuentra en su propia carpeta, la cual contiene:

1. **`main.cpp`**: Implementación del algoritmo en C++
2. **`README.md`**: Documentación detallada con un análisis en 4 pasos:
   - **Paso 1**: Descripción textual del algoritmo
   - **Paso 2**: Lista de operaciones paso a paso
   - **Paso 3**: Diagrama de flujo visual
   - **Paso 4**: Pseudocódigo del algoritmo

## 📋 Algoritmos Implementados

A continuación se presenta la lista de algoritmos de ordenación disponibles en este repositorio:

- [**BubbleSort** (Ordenación por Burbuja)](./BubbleSort/)
- [**OptimizedBubbleSort** (Ordenación por Burbuja Optimizada)](./OptimizedBubbleSort/)
- [**CocktailSort** (Ordenación Cocktail)](./CocktailSort/)
- [**InsertionSort** (Ordenación por Inserción)](./InsertionSort/)
- [**SelectionSort** (Ordenación por Selección)](./SelectionSort/)

## 🚀 Cómo Usar

Cada carpeta de algoritmo contiene su propia implementación independiente. Para compilar y ejecutar un algoritmo específico, navega a su carpeta correspondiente y sigue las instrucciones de compilación estándar de C++.

### Compilación con CMake

El proyecto incluye un archivo `CMakeLists.txt` para facilitar la compilación:

```bash
mkdir build
cd build
cmake ..
make
```

### Compilación Individual

También puedes compilar cada algoritmo de forma individual:

```bash
cd BubbleSort
g++ main.cpp -o bubblesort
./bubblesort
```

## 📚 Recursos Adicionales

- **Common**: Carpeta con utilidades comunes compartidas entre los algoritmos
- **img**: Carpeta con diagramas de flujo y recursos visuales

## 🤝 Contribuciones

Este proyecto tiene fines educativos. Si deseas contribuir con más algoritmos de ordenación o mejorar los existentes, ¡las contribuciones son bienvenidas!

## 📄 Licencia

Este proyecto es de código abierto y está disponible para uso educativo.
