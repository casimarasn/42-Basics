*Este proyecto ha sido creado como parte del currículo de 42 por msedeno-.*

# Ft_Printf - 42 School Project

![Language](https://img.shields.io/badge/Language-C-blue)
![School](https://img.shields.io/badge/School-42-black)
![Success](https://img.shields.io/badge/Success-100%2F100-success)

---

## 🇬🇧 English Version

### Description
`ft_printf` is a project at 42 where we mimic the behavior of the standard C library function `printf`. The goal is to learn about variadic functions (`stdarg.h`), manage variable numbers of arguments, and format output according to various type specifiers.

### Instructions
**Installation & Usage:**
1. Clone the repository into your project folder.
2. Run `make` to compile the library. This will generate the `libftprintf.a` file.
3. To clean up object files, run `make clean`. To remove everything including the library, run `make fclean`.

**Example Usage:**
Include the header in your C file:
```c
#include "ft_printf.h"
```
Compile your project linking the library:
```bash
cc main.c libftprintf.a -o program
```

### Resources
**References:**
- [Open Group Base Specifications (printf)](https://pubs.opengroup.org/onlinepubs/9699919799/functions/printf.html)
- [C Variadic Functions (stdarg.h)](https://en.cppreference.com/w/c/variadic)

**AI Usage:**
- **Task:** Documentation.
  - **Details:** GitHub Copilot assisted in structuring and generating the content of this `README.md` file to match the style of previous project documentations.

### Detailed Library Description (List of Functions)

#### Core Functions

| Function | Description |
| :--- | :--- |
| [`ft_printf`](ft_printf.c) | The main function that parses the format string and dispatches printing tasks. |
| [`ft_print_format`](ft_print_format.c) | Identifies the conversion specifier and calls the appropriate printing function. |

#### Conversion Handlers

| Function | Description |
| :--- | :--- |
| [`ft_print_char`](ft_print_char.c) | Prints a single character (`%c`). |
| [`ft_print_string`](ft_print_string.c) | Prints a string of characters (`%s`). |
| [`ft_print_pointer`](ft_print_pointer.c) | Prints a memory address in hexadecimal format (`%p`). |
| [`ft_print_nbr`](ft_print_nbr.c) | Prints a signed integer in decimal format (`%d`, `%i`). |
| [`ft_print_unsigned`](ft_print_unsigned.c) | Prints an unsigned integer in decimal format (`%u`). |
| [`ft_print_hexdecmi`](ft_print_hexdecmi.c) | Prints a number in lowercase hexadecimal format (`%x`). |
| [`ft_print_hexdecma`](ft_print_hexdecma.c) | Prints a number in uppercase hexadecimal format (`%X`). |
| [`ft_print_percent`](ft_print_percent.c) | Prints a literal percent sign (`%%`). |

---

## 🇪🇸 Versión en Español

### Descripción
`ft_printf` es un proyecto de 42 donde imitamos el comportamiento de la función `printf` de la librería estándar de C. El objetivo es aprender sobre funciones variádicas (`stdarg.h`), gestionar un número variable de argumentos y formatear la salida según varios especificadores de tipo.

### Instrucciones
**Instalación y Uso:**
1. Clona el repositorio en tu carpeta de proyecto.
2. Ejecuta `make` para compilar la librería. Esto generará el archivo `libftprintf.a`.
3. Para limpiar los archivos objeto, ejecuta `make clean`. Para eliminar todo, incluida la librería, ejecuta `make fclean`.

**Ejemplo de uso:**
Incluye el header en tu archivo C:
```c
#include "ft_printf.h"
```
Compila tu proyecto enlazando la librería:
```bash
cc main.c libftprintf.a -o programa
```

### Recursos
**Referencias:**
- [Open Group Base Specifications (printf)](https://pubs.opengroup.org/onlinepubs/9699919799/functions/printf.html)
- [Funciones Variádicas en C (stdarg.h)](https://es.cppreference.com/w/c/variadic)

**Uso de IA:**
- **Tarea:** Documentación.
  - **Detalles:** GitHub Copilot asistió en la estructuración y generación del contenido de este archivo `README.md` para coincidir con el estilo de documentaciones de proyectos anteriores.

### Descripción detallada de la librería (Lista de Funciones)

#### Funciones Principales

| Función | Descripción |
| :--- | :--- |
| [`ft_printf`](ft_printf.c) | La función principal que analiza la cadena de formato y delega las tareas de impresión. |
| [`ft_print_format`](ft_print_format.c) | Identifica el especificador de conversión y llama a la función de impresión adecuada. |

#### Manejadores de Conversión

| Función | Descripción |
| :--- | :--- |
| [`ft_print_char`](ft_print_char.c) | Imprime un solo carácter (`%c`). |
| [`ft_print_string`](ft_print_string.c) | Imprime una cadena de caracteres (`%s`). |
| [`ft_print_pointer`](ft_print_pointer.c) | Imprime una dirección de memoria en formato hexadecimal (`%p`). |
| [`ft_print_nbr`](ft_print_nbr.c) | Imprime un entero con signo en formato decimal (`%d`, `%i`). |
| [`ft_print_unsigned`](ft_print_unsigned.c) | Imprime un entero sin signo en formato decimal (`%u`). |
| [`ft_print_hexdecmi`](ft_print_hexdecmi.c) | Imprime un número en formato hexadecimal minúscula (`%x`). |
| [`ft_print_hexdecma`](ft_print_hexdecma.c) | Imprime un número en formato hexadecimal mayúscula (`%X`). |
| [`ft_print_percent`](ft_print_percent.c) | Imprime un signo de porcentaje literal (`%%`). |

---

<div align="center">
  <b>Developed by msedeno-</b><br>
  42 Málaga<br>
  <a href="mailto:msedeno-@student.42malaga.com">msedeno-@student.42malaga.com</a>
</div>
