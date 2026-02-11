*Este proyecto ha sido creado como parte del currículum de 42 por msedeno-.*

# Pipex - 42 School Project

![Language](https://img.shields.io/badge/Language-C-blue)
![School](https://img.shields.io/badge/School-42-black)
![Success](https://img.shields.io/badge/Success-100%2F100-success)

---

## 🇬🇧 English Version

### Description
Pipex is a project that aims to deepen the understanding of UNIX mechanisms: pipes and redirections. The goal is to program a tool that behaves exactly like the shell command: `< file1 cmd1 | cmd2 > file2`. This project covers process creation with `fork`, inter-process communication with `pipe`, and file descriptor redirection using `dup2`.

### Instructions
**Installation & Usage:**
1. Clone the repository into your project folder.
2. Run `make` to compile the project. This will generate the `pipex` executable.
3. To clean up object files, run `make clean`. To remove everything including the executable, run `make fclean`.
4. Run `make re` to recompile the entire project.

**Example Usage:**
```bash
./pipex infile "ls -l" "wc -l" outfile
```
This is equivalent to the shell command:
```bash
< infile ls -l | wc -l > outfile
```

### Resources
**References:**
- [Unix Pipes - Computerphile](https://www.youtube.com/watch?v=uHH7nHkgZ4w)
- [C Standard Library documentation](https://en.cppreference.com/w/c/header)
- [Pipex: The 42 Guide](https://reactive.so/post/42-a-comprehensive-guide-to-pipex)

**AI Usage:**
- **Task:** Header Normalization.
  - **Details:** GitHub Copilot was used to automatically update and format the 42 headers across all `.c` and `.h` files to match the current user and email standards.
- **Task:** Documentation.
  - **Details:** Gemini assisted in structuring and generating the content of this `README.md` file to comply with project submission requirements and professional standards.

### Detailed Project Description (Main Functions)

#### Core Functions

| Function | File | Description |
| :--- | :--- | :--- |
| `main` | pipex.c | Entry point, handles initialization and process management. |
| `child1_process` | process.c | Executes the first command redirecting input from infile to pipe. |
| `child2_process` | process.c | Executes the second command redirecting input from pipe to outfile. |
| `find_command_path` | setup.c | Searches for the binary path of a command in the PATH environment variable. |
| `free_all` | errors_free.c | Safely frees all allocated memory and arrays. |

---

## 🇪🇸 Versión en Español

### Descripción
Pipex es un proyecto que busca profundizar en la comprensión de los mecanismos de UNIX: pipes y redirecciones. El objetivo es programar una herramienta que se comporte exactamente como el comando de shell: `< archivo1 cmd1 | cmd2 > archivo2`. Este proyecto cubre la creación de procesos con `fork`, la comunicación entre procesos con `pipe` y la redirección de descriptores de archivo mediante `dup2`.

### Instrucciones
**Instalación y Uso:**
1. Clona el repositorio en tu carpeta de proyecto.
2. Ejecuta `make` para compilar el proyecto. Esto generará el ejecutable `pipex`.
3. Para limpiar los archivos objeto, ejecuta `make clean`. Para eliminar todo, incluido el ejecutable, ejecuta `make fclean`.
4. Ejecuta `make re` para recompilar todo el proyecto.

**Ejemplo de uso:**
```bash
./pipex infile "ls -l" "wc -l" outfile
```
Esto equivale al comando de shell:
```bash
< infile ls -l | wc -l > outfile
```

### Recursos
**Referencias:**
- [Unix Pipes - Computerphile](https://www.youtube.com/watch?v=uHH7nHkgZ4w)
- [Documentación de la librería estándar de C](https://es.cppreference.com/w/c/header)
- [Pipex: Guía de 42](https://reactive.so/post/42-a-comprehensive-guide-to-pipex)

**Uso de IA:**
- **Tarea:** Normalización de Headers.
  - **Detalles:** Se utilizó GitHub Copilot para actualizar y formatear automáticamente los headers de 42 en todos los archivos `.c` y `.h` conforme a los estándares de usuario e email actuales.
- **Tarea:** Documentación.
  - **Detalles:** Gemini asistió en la estructuración y generación del contenido de este archivo `README.md` para cumplir con los requisitos de entrega del proyecto y estándares profesionales.

### Descripción detallada del proyecto (Funciones Principales)

#### Funciones Principales

| Función | Archivo | Descripción |
| :--- | :--- | :--- |
| `main` | pipex.c | Punto de entrada, maneja la inicialización y gestión de procesos. |
| `child1_process` | process.c | Ejecuta el primer comando redirigiendo la entrada de infile al pipe. |
| `child2_process` | process.c | Ejecuta el segundo comando redirigiendo la entrada del pipe al outfile. |
| `find_command_path` | setup.c | Busca la ruta binaria de un comando en la variable de entorno PATH. |
| `free_all` | errors_free.c | Libera de forma segura toda la memoria reservada y arrays. |

---

<div align="center">
  <b>Developed by msedeno-</b><br>
  42 Málaga<br>
  <a href="mailto:msedeno-@student.42malaga.com">msedeno-@student.42malaga.com</a>
</div>