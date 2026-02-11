*Este proyecto ha sido creado como parte del currículo de 42 por msedeno-.*

# Libft - 42 School Project

![Language](https://img.shields.io/badge/Language-C-blue)
![School](https://img.shields.io/badge/School-42-black)
![Success](https://img.shields.io/badge/Success-100%2F100-success)

---

## 🇬🇧 English Version

### Description
Libft is the first individual project at 42. It consists of creating a library of functions in C, which will be used in future projects throughout the curriculum. The goal is to understand how standard functions work, manage memory efficiently, and learn to create data structures like linked lists.

### Instructions
**Installation & Usage:**
1. Clone the repository into your project folder.
2. Run `make` to compile the standard functions. This will generate the `libft.a` file.
3. Run `make bonus` to compile the library including the list manipulation functions.
4. To clean up object files, run `make clean`. To remove everything including the library, run `make fclean`.

**Example Usage:**
Include the header in your C file:
```c
#include "libft.h"
```
Compile your project linking the library:
```bash
cc main.c libft.a -o program
```

### Resources
**References:**
- [Open Group Base Specifications (man pages)](https://pubs.opengroup.org/onlinepubs/9699919799/)
- [C Standard Library documentation](https://en.cppreference.com/w/c/header)

**AI Usage:**
- **Task:** Header Normalization.
  - **Details:** GitHub Copilot was used to automatically update and format the 42 headers across all `.c` and `.h` files to match the current user and email standards.
- **Task:** Documentation.
  - **Details:** GitHub Copilot assisted in structuring and generating the content of this `README.md` file to comply with project submission requirements.

### Detailed Library Description (List of Functions)

#### 1. Libc Functions
Standard C library functions re-implemented.

| Function | Description |
| :--- | :--- |
| [`ft_isalpha`](ft_isalpha.c) | Checks for an alphabetic character. |
| [`ft_isdigit`](ft_isdigit.c) | Checks for a digit (0 through 9). |
| [`ft_isalnum`](ft_isalnum.c) | Checks for an alphanumeric character. |
| [`ft_isascii`](ft_isascii.c) | Checks whether c fits into the ASCII character set. |
| [`ft_isprint`](ft_isprint.c) | Checks for any printable character. |
| [`ft_strlen`](ft_strlen.c) | Calculates the length of a string. |
| [`ft_memset`](ft_memset.c) | Fills memory with a constant byte. |
| [`ft_bzero`](ft_bzero.c) | Zeroes a byte string. |
| [`ft_memcpy`](ft_memcpy.c) | Copies memory area. |
| [`ft_memmove`](ft_memmove.c) | Copies memory area (handling overlaps). |
| [`ft_strlcpy`](ft_strlcpy.c) | Copies string to a specific size. |
| [`ft_strlcat`](ft_strlcat.c) | Concatenates string to a specific size. |
| [`ft_toupper`](ft_toupper.c) | Converts char to uppercase. |
| [`ft_tolower`](ft_tolower.c) | Converts char to lowercase. |
| [`ft_strchr`](ft_strchr.c) | Locates character in string. |
| [`ft_strrchr`](ft_strrchr.c) | Locates character in string (from the end). |
| [`ft_strncmp`](ft_strncmp.c) | Compares two strings up to n characters. |
| [`ft_memchr`](ft_memchr.c) | Scans memory for a character. |
| [`ft_memcmp`](ft_memcmp.c) | Compares memory areas. |
| [`ft_strnstr`](ft_strnstr.c) | Locates a substring in a string. |
| [`ft_atoi`](ft_atoi.c) | Converts a string to an integer. |
| [`ft_calloc`](ft_calloc.c) | Allocates memory and sets its bytes' values to 0. |
| [`ft_strdup`](ft_strdup.c) | Creates a duplicate for the string passed as parameter. |

#### 2. Additional Functions
Functions that are either not in the libc, or part of it but in a different form.

| Function | Description |
| :--- | :--- |
| [`ft_substr`](ft_substr.c) | Allocates and returns a substring from the string 's'. |
| [`ft_strjoin`](ft_strjoin.c) | Allocates and returns a new string, result of the concatenation of 's1' and 's2'. |
| [`ft_strtrim`](ft_strtrim.c) | Allocates and returns a copy of 's1' with the characters specified in 'set' removed from the start and the end. |
| [`ft_split`](ft_split.c) | Allocates and returns an array of strings obtained by splitting 's' using the character 'c' as a delimiter. |
| [`ft_itoa`](ft_itoa.c) | Allocates and returns a string representing the integer received as an argument. |
| [`ft_strmapi`](ft_strmapi.c) | Applies the function 'f' to each character of the string 's' to create a new string. |
| [`ft_striteri`](ft_striteri.c) | Applies the function 'f' on each character of the string passed as argument. |
| [`ft_putchar_fd`](ft_putchar_fd.c) | Outputs the character 'c' to the given file descriptor. |
| [`ft_putstr_fd`](ft_putstr_fd.c) | Outputs the string 's' to the given file descriptor. |
| [`ft_putendl_fd`](ft_putendl_fd.c) | Outputs the string 's' to the given file descriptor followed by a newline. |
| [`ft_putnbr_fd`](ft_putnbr_fd.c) | Outputs the integer 'n' to the given file descriptor. |

#### 3. Bonus Functions (Linked Lists)
Functions to manipulate lists.

| Function | Description |
| :--- | :--- |
| [`ft_lstnew`](ft_lstnew.c) | Allocates and returns a new node. |
| [`ft_lstadd_front`](ft_lstadd_front.c) | Adds the node 'new' at the beginning of the list. |
| [`ft_lstsize`](ft_lstsize.c) | Counts the number of nodes in a list. |
| [`ft_lstlast`](ft_lstlast.c) | Returns the last node of the list. |
| [`ft_lstadd_back`](ft_lstadd_back.c) | Adds the node 'new' at the end of the list. |
| [`ft_lstdelone`](ft_lstdelone.c) | Takes as a parameter a node and frees the memory of the node’s content. |
| [`ft_lstclear`](ft_lstclear.c) | Deletes and frees the given node and every successor of that node. |
| [`ft_lstiter`](ft_lstiter.c) | Iterates the list 'lst' and applies the function 'f' on the content of each node. |
| [`ft_lstmap`](ft_lstmap.c) | Iterates the list 'lst' and applies the function 'f' on the content of each node. |

---

## 🇪🇸 Versión en Español

### Descripción
Libft es el primer proyecto individual en 42. Consiste en crear una librería de funciones en C, que serán utilizadas en futuros proyectos a lo largo del curso. El objetivo es entender cómo funcionan las funciones estándar, gestionar la memoria de manera eficiente y aprender a crear estructuras de datos como listas enlazadas.

### Instrucciones
**Instalación y Uso:**
1. Clona el repositorio en tu carpeta de proyecto.
2. Ejecuta `make` para compilar las funciones estándar. Esto generará el archivo `libft.a`.
3. Ejecuta `make bonus` para compilar la librería incluyendo las funciones de manipulación de listas.
4. Para limpiar los archivos objeto, ejecuta `make clean`. Para eliminar todo, incluida la librería, ejecuta `make fclean`.

**Ejemplo de uso:**
Incluye el header en tu archivo C:
```c
#include "libft.h"
```
Compila tu proyecto enlazando la librería:
```bash*Este proyecto ha sido creado como parte del currículo de 42 por msedeno-.*
cc main.c libft.a -o programa
```

### Recursos
**Referencias:**
- [Open Group Base Specifications (man pages)](https://pubs.opengroup.org/onlinepubs/9699919799/)
- [Documentación de la librería estándar de C](https://es.cppreference.com/w/c/header)

**Uso de IA:**
- **Tarea:** Normalización de Headers.
  - **Detalles:** Se utilizó GitHub Copilot para actualizar y formatear automáticamente los headers de 42 en todos los archivos `.c` y `.h` conforme a los estándares de usuario e email actuales.
- **Tarea:** Documentación.
  - **Detalles:** GitHub Copilot asistió en la estructuración y generación del contenido de este archivo `README.md` para cumplir con los requisitos de entrega del proyecto.

### Descripción detallada de la librería (Lista de Funciones)

#### 1. Funciones de Libc
Reimplementación de funciones de la librería estándar de C.

| Función | Descripción |
| :--- | :--- |
| [`ft_isalpha`](ft_isalpha.c) | Comprueba si es un carácter alfabético. |
| [`ft_isdigit`](ft_isdigit.c) | Comprueba si es un dígito (0 a 9). |
| [`ft_isalnum`](ft_isalnum.c) | Comprueba si es un carácter alfanumérico. |
| [`ft_isascii`](ft_isascii.c) | Comprueba si c encaja en el conjunto de caracteres ASCII. |
| [`ft_isprint`](ft_isprint.c) | Comprueba si es un carácter imprimible. |
| [`ft_strlen`](ft_strlen.c) | Calcula la longitud de una cadena. |
| [`ft_memset`](ft_memset.c) | Rellena la memoria con un byte constante. |
| [`ft_bzero`](ft_bzero.c) | Pone a cero una cadena de bytes. |
| [`ft_memcpy`](ft_memcpy.c) | Copia área de memoria. |
| [`ft_memmove`](ft_memmove.c) | Copia área de memoria (manejando solapamientos). |
| [`ft_strlcpy`](ft_strlcpy.c) | Copia una cadena a un tamaño específico. |
| [`ft_strlcat`](ft_strlcat.c) | Concatena una cadena a un tamaño específico. |
| [`ft_toupper`](ft_toupper.c) | Convierte char a mayúscula. |
| [`ft_tolower`](ft_tolower.c) | Convierte char a minúscula. |
| [`ft_strchr`](ft_strchr.c) | Localiza carácter en cadena. |
| [`ft_strrchr`](ft_strrchr.c) | Localiza carácter en cadena (desde el final). |
| [`ft_strncmp`](ft_strncmp.c) | Compara dos cadenas hasta n caracteres. |
| [`ft_memchr`](ft_memchr.c) | Escanea memoria por un carácter. |
| [`ft_memcmp`](ft_memcmp.c) | Compara áreas de memoria. |
| [`ft_strnstr`](ft_strnstr.c) | Localiza una subcadena en una cadena. |
| [`ft_atoi`](ft_atoi.c) | Convierte una cadena a un entero. |
| [`ft_calloc`](ft_calloc.c) | Asigna memoria y establece sus bytes a 0. |
| [`ft_strdup`](ft_strdup.c) | Crea un duplicado para la cadena pasada como parámetro. |

#### 2. Funciones Adicionales
Funciones que no están en la libc, o que son parte de ella pero en una forma diferente.

| Función | Descripción |
| :--- | :--- |
| [`ft_substr`](ft_substr.c) | Asigna y devuelve una subcadena de la cadena 's'. |
| [`ft_strjoin`](ft_strjoin.c) | Asigna y devuelve una nueva cadena, resultado de la concatenación de 's1' y 's2'. |
| [`ft_strtrim`](ft_strtrim.c) | Asigna y devuelve una copia de 's1' con los caracteres especificados en 'set' eliminados del principio y del final. |
| [`ft_split`](ft_split.c) | Asigna y devuelve un array de cadenas obtenido separando 's' utilizando el carácter 'c' como delimitador. |
| [`ft_itoa`](ft_itoa.c) | Asigna y devuelve una cadena que representa el entero recibido como argumento. |
| [`ft_strmapi`](ft_strmapi.c) | Aplica la función 'f' a cada carácter de la cadena 's' para crear una nueva cadena. |
| [`ft_striteri`](ft_striteri.c) | Aplica la función 'f' en cada carácter de la cadena pasada como argumento. |
| [`ft_putchar_fd`](ft_putchar_fd.c) | Escribe el carácter 'c' en el file descriptor dado. |
| [`ft_putstr_fd`](ft_putstr_fd.c) | Escribe la cadena 's' en el file descriptor dado. |
| [`ft_putendl_fd`](ft_putendl_fd.c) | Escribe la cadena 's' en el file descriptor dado seguido de un salto de línea. |
| [`ft_putnbr_fd`](ft_putnbr_fd.c) | Escribe el entero 'n' en el file descriptor dado. |

#### 3. Funciones Bonus (Listas Enlazadas)
Funciones para manipular listas.

| Función | Descripción |
| :--- | :--- |
| [`ft_lstnew`](ft_lstnew.c) | Asigna y devuelve un nuevo nodo. |
| [`ft_lstadd_front`](ft_lstadd_front.c) | Añade el nodo 'new' al principio de la lista. |
| [`ft_lstsize`](ft_lstsize.c) | Cuenta el número de nodos en una lista. |
| [`ft_lstlast`](ft_lstlast.c) | Devuelve el último nodo de la lista. |
| [`ft_lstadd_back`](ft_lstadd_back.c) | Añade el nodo 'new' al final de la lista. |
| [`ft_lstdelone`](ft_lstdelone.c) | Toma como parámetro un nodo y libera la memoria del contenido del nodo. |
| [`ft_lstclear`](ft_lstclear.c) | Elimina y libera el nodo dado y todos los sucesores de ese nodo. |
| [`ft_lstiter`](ft_lstiter.c) | Itera la lista 'lst' y aplica la función 'f' en el contenido de cada nodo. |
| [`ft_lstmap`](ft_lstmap.c) | Itera la lista 'lst' y aplica la función 'f' en el contenido de cada nodo. |

---

<div align="center">
  <b>Developed by msedeno-</b><br>
  42 Málaga<br>
  <a href="mailto:msedeno-@student.42malaga.com">msedeno-@student.42malaga.com</a>
</div>