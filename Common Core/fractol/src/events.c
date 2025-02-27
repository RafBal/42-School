/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:09:28 by rbaldin           #+#    #+#             */
/*   Updated: 2025/02/24 17:31:44 by rbaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
