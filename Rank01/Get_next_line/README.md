# Get Next Line

![Status](https://img.shields.io/badge/status-finished-success)
![Language](https://img.shields.io/badge/language-C-blue)

## 🇬🇧 English

### Description
**Get Next Line** is a project from the 42 curriculum that involves writing a function capable of reading a line ending with a newline character from a file descriptor. This project introduces the concept of static variables in C and file manipulation.

### Function Prototype
```c
char *get_next_line(int fd);
```

### Features
- Reads from a file descriptor effectively handling buffers.
- Returns the line read correctly, including the newline character `\n` if present.
- **Bonus:** Handles multiple file descriptors simultaneously without losing the reading thread of each one.
- No memory leaks.

### How to use
1. Include the header in your C file:
   ```c
   #include "get_next_line.h"
   ```
2. Compile your files with the library source code:
   ```bash
   gcc main.c get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=42
   ```

---

## 🇪🇸 Español

### Descripción
**Get Next Line** es un proyecto del currículum de 42 que consiste en programar una función que devuelva una línea leída de un file descriptor. Este proyecto introduce el uso de variables estáticas en C y la gestión de memoria dinámica en lecturas de archivos.

### Prototipo
```c
char *get_next_line(int fd);
```

### Características
- Lee de un file descriptor gestionando un buffer.
- Devuelve la línea leída correctamente, incluyendo el salto de línea `\n` si existe.
- **Bonus:** Gestiona múltiples file descriptors simultáneamente, manteniendo el estado de lectura de cada uno de forma independiente.
- Gestión de memoria limpia (sin leaks).

### Uso
1. Incluye la cabecera en tu archivo C:
   ```c
   #include "get_next_line.h"
   ```
2. Compila tus archivos junto con el código fuente:
   ```bash
   gcc main.c get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=42
   ```

---

### Author / Autor
**msedeno-**  
[GitHub Profile](https://github.com/msedeno-)
