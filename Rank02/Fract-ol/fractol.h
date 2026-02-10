/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 21:11:40 by msedeno-          #+#    #+#             */
/*   Updated: 2026/02/10 20:02:16 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

/* --- Libraries --- */
# include <math.h>
# include <stdint.h>
# include "Libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"

/* Window dimensions */
# define WIDTH 1920
# define HEIGHT 1080

/* Math constants */
# define MAX_ITER 500
# define ZOOM_FACTOR 1.2
# define MOVE_STEP 0.1

/* --- Colors (Hex RGBA) optional --- */
# define BLACK 0x000000FF
# define WHITE 0xFFFFFFFF
# define RED 0xFF0000FF
# define GREEN 0x00FF00FF
# define BLUE 0x0000FFFF

/* Fractal types */
# define MANDELBROT 1
# define JULIA 2
# define BURNING_SHIP 3

/* --- Structures --- */

/**
 * @brief Represents a complex number.
 * Used for mathematical calculations of coordinates.
 */
typedef struct s_c
{
	double	re;
	double	im;
}				t_c;

/**
 * @brief Main structure holding the program state.
 * Contains MLX instances, fractal settings, and view boundaries.
 */
typedef struct fractal
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	int			type;
	double		min_real;
	double		max_real;
	double		min_imag;
	double		max_imag;
	double		zoom;
	double		julia_real;
	double		julia_imag;
	int			max_it;
}				t_fractal;

/**
 * @brief Helper structure for string-to-double conversion.
 * Tracks current parsing state variables.
 */
typedef struct s_atod
{
	double		frac;
	double		base;
	double		val;
	const char	*paki;
	int			point;
}				t_atod;

// ./args_utils.c

/** 
 * @brief Skips whitespace and detects the sign of a number string.
 */
const char	*skip_ws_sign(const char *s, int *sign);

/** 
 * @brief Parses the fractional part of a number string.
 */
double		parse_fraction(const char *s, t_atod *atod);

/** 
 * @brief Converts a string to a double value (Ascii To Double).
 */
double		ft_atod(const char *s, t_atod *atod);

// ./colors.c

/** 
 * @brief Generates a color value based on the iteration count.
 */
uint32_t	get_color(int iter, int max_iter);

// ./errors_free.c

/** 
 * @brief Cleans up resources, terminates MLX, and exits the program.
 */
void		finish_exit(t_fractal *fractal);

/** 
 * @brief Prints an error message and usage instructions, then exits.
 */
void		error_message(t_fractal *fractal);

// ./fractol.c

/** 
 * @brief Initializes default values for the fractal settings.
 */
void		init_values(t_fractal *fractal);

/** 
 * @brief Selects the correct rendering function based on fractal type.
 */
void		render_fractols(t_fractal *fractal);

/** 
 * @brief Initializes MLX window and starts the event loop.
 */
void		init_fractal(t_fractal *fractal);

/** 
 * @brief Main entry point: validates arguments and starts program.
 */
int			main(int ac, char **av);

// ./julia.c

/** 
 * @brief Shifts the view coordinates (panning).
 */
void		pan_view(t_fractal *f, double dx, double dy);

/** 
 * @brief Handles specific controls or logic for Julia set.
 */
void		julia_controls(t_fractal *f);

/** 
 * @brief Calculates iterations for a single point in the Julia set.
 */
int			julia_iter(t_c cc, t_fractal *fractal);

/** 
 * @brief Iterates over pixels to render the Julia set.
 */
void		render_julia(t_fractal *fractal);

/** 
 * @brief Maps screen pixel coordinates to the complex plane.
 */
t_c			pixel_to_complex(int x, int y, t_fractal *fractal);

// ./mandelbrot.c

/** 
 * @brief Calculates iterations for a single point in the Mandelbrot set.
 */
int			mandelbrot(t_c c, t_fractal *fractal);

/** 
 * @brief Iterates over pixels to render the Mandelbrot set.
 */
void		render_mandelbrot(t_fractal *fractal);

// ./utils.c

/** 
 * @brief Applies zoom focused on a specific mouse coordinate.
 */
void		zoom_at(t_fractal *fractal, double mx, double my, double factor);

/** 
 * @brief MLX callback for mouse scroll events (Zooming).
 */
void		scroll_callback(double xdelta, double ydelta, void *param);

/** 
 * @brief MLX callback for keyboard events (Movement, ESC, etc).
 */
void		handle_keys(void *param);

#endif
