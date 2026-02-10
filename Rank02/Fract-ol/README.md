# Fract-ol

![Fractol Banner](https://img.shields.io/badge/42-Project-000000?style=flat-square&logo=42)

**Fract-ol** is a graphical exploration project of fractal sets, specifically the Mandelbrot set and the Julia set. It allows users to navigate, zoom, and modify fractal parameters in real-time using a custom graphical interface built with the MLX42 library.

---

## 🇪🇸 Español

Este proyecto es una pequeña aplicación de exploración de fractales. Permite renderizar y navegar por los conjuntos de Mandelbrot y Julia, ofreciendo zoom infinito (hasta los límites del `double`) y personalización de colores.

### Características
- **Renderizado de Fractales**: Conjunto de Mandelbrot y conjunto de Julia.
- **Navegación**: Desplazamiento (Pan) con flechas o WASD.
- **Zoom**: Zoom in/out suave con la rueda del ratón centrado en el cursor.
- **Interactividad Julia**: Modificación en tiempo real de los parámetros del conjunto de Julia.
- **Optimización**: Renderizado eficiente usando manipulación directa de píxeles.

### Instalación y Uso

1. **Clonar el repositorio**:
   ```bash
   git clone https://github.com/tu_usuario/fract-ol.git
   cd fract-ol
   ```

2. **Compilar**:
   El proyecto usa la librería `MLX42` y `libft`.
   ```bash
   make
   ```

3. **Ejecutar**:
   La sintaxis es: `./fractol <tipo> [param_real] [param_imag]`

   - **Mandelbrot**:
     ```bash
     ./fractol mandelbrot
     ```
   - **Julia** (Parámetros por defecto):
     ```bash
     ./fractol julia
     ```
   - **Julia** (Parámetros personalizados):
     ```bash
     ./fractol julia -0.4 0.6
     ```

### Controles
| Tecla / Acción | Función |
|----------------|---------|
| `Rueda Ratón` | Zoom In / Zoom Out (centrado en el ratón) |
| `Flechas` / `WASD` | Mover la vista |
| `Z` / `X` | Modificar Parte Real (Julia) |
| `C` / `V` | Modificar Parte Imaginaria (Julia) |
| `ESC` | Cerrar ventana |

---

## 🇺🇸 English

This project is a fractal exploration application. It renders and allows navigation through the Mandelbrot and Julia sets, offering smooth zoom and parameter customization.

### Features
- **Fractal Rendering**: Mandelbrot set and Julia set.
- **Navigation**: Pan view using Arrow keys or WASD.
- **Zoom**: Smooth zoom in/out with the mouse wheel centered on the cursor.
- **Julia Interactivity**: Real-time modification of the Julia set constants.
- **Optimization**: Efficient rendering using direct pixel manipulation.

### Installation & Usage

1. **Clone the repository**:
   ```bash
   git clone https://github.com/your_username/fract-ol.git
   cd fract-ol
   ```

2. **Compile**:
   The project requires `MLX42` and `libft` (included or compiled automatically).
   ```bash
   make
   ```

3. **Run**:
   Syntax: `./fractol <type> [real_param] [imag_param]`

   - **Mandelbrot**:
     ```bash
     ./fractol mandelbrot
     ```
   - **Julia** (Default parameters):
     ```bash
     ./fractol julia
     ```
   - **Julia** (Custom parameters):
     ```bash
     ./fractol julia -0.4 0.6
     ```

### Controls
| Key / Action | Function |
|--------------|----------|
| `Mouse Wheel` | Zoom In / Zoom Out (cursor centered) |
| `Arrows` / `WASD` | Pan view |
| `Z` / `X` | Modify Real constant (Julia) |
| `C` / `V` | Modify Imaginary constant (Julia) |
| `ESC` | Close window |

---

## 🛠️ Technical Details
- Language: **C**
- Graphics: **MLX42** (OpenGL based)
- Algorithms: Iterative complex number calculation (escape time algorithm).