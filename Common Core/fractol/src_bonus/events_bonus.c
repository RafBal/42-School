/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:09:28 by rbaldin           #+#    #+#             */
/*   Updated: 2025/02/24 17:38:50 by rbaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	closing(t_fractalid *fract)
{
	mlx_destroy_image(fract->mlx_connection, fract->imgid.ia);
	mlx_destroy_window(fract->mlx_connection, fract->mlx_window);
	mlx_destroy_display(fract->mlx_connection);
	free(fract->mlx_connection);
	exit(EXIT_SUCCESS);
}

// keypress prototype
// int (*function)(int keycode, void *param)

int	key_handling(int keysym, t_fractalid *fractal)
{
	if (keysym == XK_Escape)
		closing(fractal);
	if (keysym == XK_Up)
		fractal->change_y -= 0.1 * fractal->focus;
	else if (keysym == XK_Down)
		fractal->change_y += 0.1 * fractal->focus;
	else if (keysym == XK_Right)
		fractal->change_x -= 0.1 * fractal->focus;
	else if (keysym == XK_Left)
		fractal->change_x += 0.1 * fractal->focus;
	else if (keysym == XK_equal)
		fractal->resolution_index += 10;
	else if (keysym == XK_minus)
		fractal->resolution_index -= 10;
	rendering(fractal);
	return (0);
}

int	mouse_handling(int button, int x, int y, t_fractalid *frac)
{
	(void)x;
	(void)y;
	if (button == Button5)
		frac->focus *= 1.05;
	else if (button == Button4)
		frac->focus *= 0.95;
	rendering(frac);
	return (0);
}
