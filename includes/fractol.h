/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoares- <tsoares-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 20:29:38 by tsoares-          #+#    #+#             */
/*   Updated: 2024/03/27 06:37:42 by tsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <pthread.h>

# define INVALID_USAGE "\nToo much or missing parameter(s)!\n"
# define INVALID_FRACTAL "Invalid fractal set!"

# define WIDTH 770
# define HEIGHT 770

/*
# define MIN_SEED -1.5
# define MAX_SEED 1.5
# define MIN_ITER 1 */
# define MAX_ITER 74


# define ESC  27 // Keyboard ESC
# define KEYB_UP 65362 // Keyboard arrow up
# define KEYB_DOWN 65364 // Keyboard arrow down
# define KEYB_LEFT 65361 // Keyboard arrow left
# define KEYB_RIGHT 65363 // Keyboard arrow right

# define SCROLL_UP 4 // zoom in
# define SCROLL_DOWN 5 // zoom out

// Basic Colors
#define BLACK "#000000"
#define RED "#FF0000"
#define GREEN "#00FF00"
#define YELLOW "#FFFF00"
#define BLUE "#0000FF"
#define WHITE "#FFFFFF"

// Psychdelic Colors
#define PSYCHEDELIC_PURPLE "#9933FF"
#define PSYCHEDELIC_ORANGE "#FF9933"
#define PSYCHEDELIC_PINK "#FF0099"
#define PSYCHEDELIC_YELLOW "#FFFF33"
#define PSYCHEDELIC_CYAN "#00FFFF"
#define PSYCHEDELIC_GREEN "#33FF00"
#define PSYCHEDELIC_BLUE "#0066FF"
#define PSYCHEDELIC_RED "#FF3333"


typedef struct	s_fract 
{
	char	*name;
	int		user_option;
	void	*img; // Hexadecimal color value for a pixel
	int		color; // Color of the pixel
	char	*addr; // Mem address of img, where the bytes are going to be changed
	int		bpp; // Bits per pixel (num of bits required to represent each pixel)
	int		line_len; // Length of each line in bytes (size of one row in the img)
	int		endian; // Specifies how pixel data is stored or interpreted within an image (little-endian: 0 | big-endian: 1)
	void	*mlx_connection; // Conncetion to the graphic library
	void	*mlx_window; // Window where the fractal will be rendered
	void	*ptr_img; // Points to the image being rendered (used to access and manipulate the pixel data)
	int		x; // x coordinate of pixel being calculated
	int		y; // y coordinate of the pixel being calculated
	double	cx; // Complex x: real part of the complex number
	double	cy; // Complex y: imaginary part of the complex number
	double	zx;
	double	zy;
	double	hypotenuse;
	double	x_offset; // Offset for x direction (allows to pan or move the fractal => shifts the fractal horizontally)
	double	y_offset; // offset for y direction (allows to pan or move the fractal => shifts the fractal vertically)
	double	zoom; // Average of x_zoom and y_zoom (used when both zoom factors expected to be equal)
	int		max_iter; // Maximum number of iterations (determines the level of detail and complexity in the generated fractal img)
    // CAUTION!!! => Increasing max_iter can reveal more details of the fractal but may also increase computation time
}			t_fract;

// Function prototypes
void	put_pixel(t_fract *fract, int x, int y, int color);
int		validate_input(int n_args, char **args);
void	handle_allocation_failure(void);
void	set_fractal_name(t_fract *fractal, char **arguments);
void	render_mandelbrot(t_fract *fractal);
void	render_julia(t_fract *fractal, double n1, double n2);
void	calculate_julia(t_fract *fractal, double julia_x, double julia_y);
int		cleanup_fractal(t_fract *fractal);
void	print_menu();

// Init
void	fractol_init(t_fract *fractal);
void	init_fractal(t_fract *fractal);
void	init_minilibx(t_fract *fractal);

//Function prototypes for drawing fractals images
void	render_fractals(t_fract *fractal);

//Function prototypes for rendering fractals images
void	calculate_mandelbrot(t_fract *fractal);
void	render_mandelbrot_set(t_fract *fractal);
void	render_julia_set(t_fract *fractal);

// Math
double	ft_atof(const char *n);
double	linear_interpolate(double n, double n_min, double n_max, double max);
void	operate_complex(t_fract *fractal, double imag1, double imag2);

#endif


