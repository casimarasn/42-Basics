*Este proyecto ha sido creado como parte del currículo de 42 por msedeno-.*

# Get_next_line - 42 School Project

![Language](https://img.shields.io/badge/Language-C-blue)
![School](https://img.shields.io/badge/School-42-black)
![Success](https://img.shields.io/badge/Success-125%2F100-success)

---

## 🇬🇧 English Version

### Description
Get Next Line is a project at 42 that challenges students to create a function that reads a line from a file descriptor. The main goal is to learn about static variables in C, dynamic memory allocation, and efficient file reading management.

### Instructions
**Installation & Usage:**
1. Clone the repository into your project folder.
2. Since this project typically doesn't include a Makefile (it's often just the source files used in other projects), you compile the files directly with your program.
3. You must define the buffer size at compilation time using the `-D BUFFER_SIZE=n` flag.

**Example Usage:**
Include the header in your C file:
```c
#include "get_next_line.h"
```
Compile your project linking the source files:
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c -o gnl
```

### Resources
**References:**
- [Open Group Base Specifications (read)](https://pubs.opengroup.org/onlinepubs/9699919799/functions/read.html)
- [Open Group Base Specifications (malloc)](https://pubs.opengroup.org/onlinepubs/9699919799/functions/malloc.html)

**AI Usage:**
- **Task:** Documentation.
  - **Details:** GitHub Copilot assisted in structuring and generating the content of this `README.md` file to comply with the project format standards.

### Detailed Library Description (List of Files)

#### 1. Mandatory Part
Core functions to handle file reading.

| File | Description |
| :--- | :--- |
| [`get_next_line.c`](get_next_line.c) | Contains the main logic of the function `get_next_line`, which reads from a file descriptor until a newline is found or EOF is reached. |
| [`get_next_line_utils.c`](get_next_line_utils.c) | Helper functions required for `get_next_line` (usually string length, join, or substring functions). |
| [`get_next_line.h`](get_next_line.h) | Header file containing function prototypes and the `BUFFER_SIZE` macro definition (if not defined at compile time). |

#### 2. Bonus Part
Handling multiple file descriptors with a single static variable.

| File | Description |
| :--- | :--- |
| [`get_next_line_bonus.c`](get_next_line_bonus.c) | Implementation of `get_next_line` capable of managing multiple file descriptors simultaneously using a static array (or list). |
| [`get_next_line_utils_bonus.c`](get_next_line_utils_bonus.c) | Helper functions for the bonus implementation. |
| [`get_next_line_bonus.h`](get_next_line_bonus.h) | Header file for the bonus part. |

---

## 🇪🇸 Versión en Español

### Descripción
Get Next Line es un proyecto en 42 que desafía a los estudiantes a crear una función que lea una línea desde un descriptor de archivo (file descriptor). El objetivo principal es aprender sobre variables estáticas en C, asignación dinámica de memoria y gestión eficiente de lectura de archivos.

### Instrucciones
**Instalación y Uso:**
1. Clona el repositorio en tu carpeta de proyecto.
2. Dado que este proyecto a menudo no incluye un Makefile (son archivos fuente para usar en otros proyectos), compilas los archivos directamente con tu programa.
3. Debes definir el tamaño del buffer en tiempo de compilación usando la flag `-D BUFFER_SIZE=n`.

**Ejemplo de uso:**
Incluye el header en tu archivo C:
```c
#include "get_next_line.h"
```
Compila tu proyecto enlazando los archivos fuente:
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c -o gnl
```

### Recursos
**Referencias:**
- [Open Group Base Specifications (read)](https://pubs.opengroup.org/onlinepubs/9699919799/functions/read.html)
- [Open Group Base Specifications (malloc)](https://pubs.opengroup.org/onlinepubs/9699919799/functions/malloc.html)

**Uso de IA:**
- **Tarea:** Documentación.
  - **Detalles:** GitHub Copilot asistió en la estructuración y generación del contenido de este archivo `README.md` para cumplir con los estándares de formato del proyecto.

### Descripción detallada de la librería (Lista de Archivos)

#### 1. Parte Obligatoria
Funciones principales para gestionar la lectura de archivos.

| Archivo | Descripción |
| :--- | :--- |
| [`get_next_line.c`](get_next_line.c) | Contiene la lógica principal de la función `get_next_line`, que lee de un descriptor de archivo hasta encontrar un salto de línea o llegar al final del archivo (EOF). |
| [`get_next_line_utils.c`](get_next_line_utils.c) | Funciones auxiliares necesarias para `get_next_line` (generalmente longitud de cadena, unión o subcadenas). |
| [`get_next_line.h`](get_next_line.h) | Archivo de cabecera con los prototipos de función y la definición de la macro `BUFFER_SIZE` (si no se define al compilar). |

#### 2. Parte Bonus
Gestión de múltiples descriptores de archivo con una única variable estática.

| Archivo | Descripción |
| :--- | :--- |
| [`get_next_line_bonus.c`](get_next_line_bonus.c) | Implementación de `get_next_line` capaz de gestionar múltiples file descriptors simultáneamente usando un array estático (o lista). |
| [`get_next_line_utils_bonus.c`](get_next_line_utils_bonus.c) | Funciones auxiliares para la implementación bonus. |
| [`get_next_line_bonus.h`](get_next_line_bonus.h) | Archivo de cabecera para la parte bonus. |

---

<div align="center">
  <b>Developed by msedeno-</b><br>
  42 Málaga<br>
  <a href="mailto:msedeno-@student.42malaga.com">msedeno-@student.42malaga.com</a>
</div>
