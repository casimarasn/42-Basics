*Este proyecto ha sido creado como parte del currículo de 42 por msedeno-.*

# Push_swap

![Language](https://img.shields.io/badge/Language-C-blue)
![School](https://img.shields.io/badge/School-42-black)
![Norminette](https://img.shields.io/badge/Style-Norminette-success)
![Success](https://img.shields.io/badge/Success-125%2F100-success)

**Push_swap** is a highly efficient sorting algorithm project developed as part of the 42 School curriculum. The goal is to sort a stack of integers using a limited set of operations and an auxiliary stack, optimizing for the minimum number of moves.

This repository includes the mandatory sorting program and the **bonus** checker to verify the results.

---

## 🇬🇧 English Version

### 📖 Table of Contents
- [Overview](#overview)
- [The Algorithm](#the-algorithm)
- [Installation](#installation)
- [Usage](#usage)
- [OperationsReference](#operations-reference)

### <a name="overview"></a>Overview
The challenge is simple: given a set of random integers on Stack A, sort them using only Stack A and Stack B with specific commands (swap, push, rotate). The real complexity lies in the algorithmic efficiency required to obtain a perfect score (e.g., sorting 500 numbers in fewer than 5500 operations).

### <a name="the-algorithm"></a>The Algorithm
This project implements a **Hybrid Chunk Sort & Greedy Insertion** strategy, designed to handle large datasets efficiently.

1.  **Phase 1: Pre-sorting (Chunks to Stack B)**
    - The algorithm identifies "chunks" or ranges of values based on their final sorted index.
    - Elements are pushed from Stack A to Stack B. To optimize future moves, smaller elements within the chunk are rotated to the bottom of Stack B (`rb`), creating a loosely sorted structure (Gaussian curve distribution).
    - Source: `presort_to_b.c`

2.  **Phase 2: Tiny Sort**
    - Once Stack A is reduced to 3 elements, a hardcoded logic sorts them instantly.
    - Source: `sort_sizes.c`

3.  **Phase 3: Greedy Back-Insertion (Stack B to A)**
    - The algorithm now moves elements back to Stack A.
    - For every element in Stack B, it calculates the **cost** (number of rotations) required to push it to its correct target position in Stack A.
    - It selects the **cheapest node** (fewest total moves) and executes the operations.
    - **Optimization:** It utilizes simultaneous rotations (`rr`, `rrr`) whenever the target and the node are in the same half of their respective stacks, drastically reducing operation count.
    - Source: `target_b_to_a.c` & `costs_utils.c`

### <a name="installation"></a>Installation

Clone the repository and compile the project using `make`:

```bash
git clone https://github.com/your-username/push_swap.git
cd push_swap
make        # Compiles 'push_swap'
make bonus  # Compiles 'checker'
```

### <a name="usage"></a>Usage

**Running the Sorter:**
Pass a list of integers as arguments. The program outputs the instructions to sort them.
```bash
./push_swap 42 1337 24 1 0
```

**Using the Checker (Bonus):**
Verify if the instructions actually sort the list.
```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG
```

---

## 🇪🇸 Versión en Español

### 📖 Tabla de Contenidos
- [Resumen](#resumen)
- [El Algoritmo](#el-algoritmo)
- [Instalación](#instalación)
- [Uso](#uso)
- [Referencia de Operaciones](#referencia-de-operaciones)

### <a name="resumen"></a>Resumen
El desafío es simple: dado un conjunto de enteros aleatorios en la Pila A, ordénalos usando solo la Pila A y la Pila B con comandos específicos (intercambiar, empujar, rotar). La verdadera complejidad radica en la eficiencia algorítmica requerida para obtener la puntuación máxima (por ejemplo, ordenar 500 números en menos de 5500 operaciones).

### <a name="el-algoritmo"></a>El Algoritmo
Este proyecto implementa una estrategia **Híbrida de Ordenación por Bloques e Inserción Voraz**, diseñada para manejar grandes conjuntos de datos de manera eficiente.

1.  **Fase 1: Pre-clasificación (Chunks a Pila B)**
    - El algoritmo identifica "bloques" o rangos de valores basados en su índice final ordenado.
    - Los elementos se empujan de la Pila A a la B. Para optimizar movimientos futuros, los elementos más pequeños dentro del bloque se rotan al fondo de la Pila B (`rb`), creando una estructura semi-ordenada.
    - Fuente: `presort_to_b.c`

2.  **Fase 2: Ordenamiento Pequeño**
    - Una vez que la Pila A se reduce a 3 elementos, una lógica específica los ordena instantáneamente.
    - Fuente: `sort_sizes.c`

3.  **Fase 3: Inserción Voraz de Retorno (Pila B a A)**
    - El algoritmo ahora mueve los elementos de vuelta a la Pila A.
    - Para cada elemento en la Pila B, calcula el **coste** (número de rotaciones) necesario para colocarlo en su posición objetivo correcta en la Pila A.
    - Selecciona el **nodo más barato** (menor cantidad total de movimientos) y ejecuta las operaciones.
    - **Optimización:** Utiliza rotaciones simultáneas (`rr`, `rrr`) siempre que el objetivo y el nodo estén en la misma mitad de sus respectivas pilas, reduciendo drásticamente el conteo de operaciones.
    - Fuente: `target_b_to_a.c` & `costs_utils.c`

### <a name="instalación"></a>Instalación

Clona el repositorio y compila el proyecto usando `make`:

```bash
git clone https://github.com/tu-usuario/push_swap.git
cd push_swap
make        # Compila 'push_swap'
make bonus  # Compila 'checker'
```

### <a name="uso"></a>Uso

**Ejecutar el Ordenador:**
Pasa una lista de enteros como argumentos. El programa imprimirá las instrucciones para ordenarlos.
```bash
./push_swap 42 1337 24 1 0
```

**Usar el Verificador (Bonus):**
Verifica si las instrucciones realmente ordenan la lista.
```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG
```

---

<div align="center">
  <h3>Operations Reference / Referencia de Operaciones</h3>
</div>

| Operation | Description (EN) | Descripción (ES) |
| :--- | :--- | :--- |
| `sa` | Swap first 2 elements of stack A | Intercambia los 2 primeros elementos de A |
| `sb` | Swap first 2 elements of stack B | Intercambia los 2 primeros elementos de B |
| `ss` | `sa` + `sb` | `sa` + `sb` |
| `pa` | Push top of B to A | Mueve el elemento superior de B a A |
| `pb` | Push top of A to B | Mueve el elemento superior de A a B |
| `ra` | Rotate stack A up | Rota A hacia arriba |
| `rb` | Rotate stack B up | Rota B hacia arriba |
| `rr` | `ra` + `rb` | `ra` + `rb` |
| `rra` | Reverse rotate stack A down | Rota A hacia abajo |
| `rrb` | Reverse rotate stack B down | Rota B hacia abajo |
| `rrr` | `rra` + `rrb` | `rra` + `rrb` |

<br>

<div align="center">
  <b>Developed by msedeno-</b><br>
  42 Málaga<br>
  <a href="mailto:msedeno-@student.42malaga.com">msedeno-@student.42malaga.com</a>
</div>
