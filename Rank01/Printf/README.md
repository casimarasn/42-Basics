# ft_printf

**By: msedeno-**

## English

### Description
This project is a reimplementation of the standard C library function `printf`. It handles variable argument lists and formats output according to specific conversion specifiers. The primary goal is to understand variadic functions and detailed output management in C.

### Features
Supported conversions:
- `%c`: Prints a single character.
- `%s`: Prints a string (as defined by the common C convention).
- `%p`: The `void *` pointer argument has to be printed in hexadecimal format.
- `%d`: Prints a decimal (base 10) number.
- `%i`: Prints an integer in base 10.
- `%u`: Prints an unsigned decimal (base 10) number.
- `%x`: Prints a number in hexadecimal (base 16) lowercase format.
- `%X`: Prints a number in hexadecimal (base 16) uppercase format.
- `%%`: Prints a percent sign.

### Usage
Compile the library:
```bash
make
```
Include the header in your code:
```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s!\n", "World");
    return (0);
}
```
Link the library when compiling your program:
```bash
cc main.c libftprintf.a -o my_program
```

---

## Español

### Descripción
Este proyecto consiste en la reimplementación de la función `printf` de la librería estándar de C. Maneja listas de argumentos variables y formatea la salida de acuerdo con especificadores de conversión. El objetivo principal es comprender el funcionamiento de las funciones variádicas y la gestión detallada de la salida en C.

### Características
Conversiones soportadas:
- `%c`: Imprime un solo carácter.
- `%s`: Imprime una cadena de caracteres (según la convención de C).
- `%p`: El puntero `void *` se imprime en formato hexadecimal.
- `%d`: Imprime un número decimal (base 10).
- `%i`: Imprime un entero en base 10.
- `%u`: Imprime un número decimal sin signo (base 10).
- `%x`: Imprime un número en hexadecimal (base 16) en minúsculas.
- `%X`: Imprime un número en hexadecimal (base 16) en mayúsculas.
- `%%`: Imprime el símbolo de porcentaje.

### Uso
Compila la librería:
```bash
make
```
Incluye el header en tu código:
```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hola, %s!\n", "Mundo");
    return (0);
}
```
Enlaza la librería al compilar tu programa:
```bash
cc main.c libftprintf.a -o mi_programa
```
