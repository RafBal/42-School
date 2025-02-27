/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:21:36 by rbaldin           #+#    #+#             */
/*   Updated: 2025/02/24 17:51:28 by rbaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

// Height
# define H 800
// Width
# define W 800

# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define ERROR_MESSAGE "Try ./fractol mandelbrot or ./fractol julia a b. Avoid"

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <errno.h>
# include <math.h>
# include <stdio.h>  // debugging and perror function
# include <stdlib.h> // malloc and free
# include <unistd.h> // write and derivatives

// z = x + i*y
typedef struct s_z
{
	double		x;
	double		y;
}				t_z;

t_z				sum_z(t_z complex1, t_z complex2);
t_z				square_z(t_z complexn);

// Pixel Buffer Values (PBV)
// ia = image address
// pa = pixel address
// bpp = bits per pixel
// ll = line length
typedef struct s_imageid
{
	void		*ia;
	char		*pa;
	int			bpp;
	int			endian;
	int			ll;
}				t_imageid;

// Fractal ID = MLX basics + PBV + hooks
typedef struct s_fractalid
{
	char		*name;
	void		*mlx_connection;
	void		*mlx_window;
	t_imageid	imgid;
	double		outbound_value;
	int			resolution_index;
	double		change_x;
	double		change_y;
	double		focus;
	double		start_x;
	double		start_y;
}				t_fractalid;

// events
int				closing(t_fractalid *fract);
int				key_handling(int keysym, t_fractalid *fractal);
int				mouse_handling(int button, int x, int y, t_fractalid *frac);
int				double_only(const char *str);
double			remapping(double oi, double nmn, double nmx, double omx);
double			atodbl(char *s);
void			initializing(t_fractalid *f);
void			rendering(t_fractalid *f);
#endif
