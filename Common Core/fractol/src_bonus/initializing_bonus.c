/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializing_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:42:26 by rbaldin           #+#    #+#             */
/*   Updated: 2025/02/24 17:39:12 by rbaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static	void	malloc_issue(int n)
{
	if (1 == n)
		ft_putstr_fd("Failed to stablish the X server connection.", \
				STDERR_FILENO);
	else if (2 == n)
		ft_putstr_fd("Failed to create the window.", STDERR_FILENO);
	else if (3 == n)
		ft_putstr_fd("Failed to generate the image.", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

static	void	data_beginning(t_fractalid *fractal)
{
	fractal->outbound_value = 4.0;
	fractal->resolution_index = 42;
	fractal->change_x = 0.0;
	fractal->change_y = 0.0;
	fractal->focus = 1.0;
}

void	events_beginning(t_fractalid *fract)
{
	mlx_hook(fract->mlx_window, KeyPress, KeyPressMask, key_handling,
		fract);
	mlx_hook(fract->mlx_window, ButtonPress, ButtonPressMask,
		mouse_handling, fract);
	mlx_hook(fract->mlx_window, DestroyNotify, StructureNotifyMask,
		closing, fract);
}

void	initializing(t_fractalid *f)
{
	f->mlx_connection = mlx_init();
	if (NULL == f->mlx_connection)
		malloc_issue(1);
	f->mlx_window = mlx_new_window(f->mlx_connection, W, H, f->name);
	if (NULL == f->mlx_window)
	{
		mlx_destroy_display(f->mlx_connection);
		free(f->mlx_connection);
		malloc_issue(2);
	}
	f->imgid.ia = mlx_new_image(f->mlx_connection, W, H);
	if (NULL == f->imgid.ia)
	{
		mlx_destroy_window(f->mlx_connection, f->mlx_window);
		mlx_destroy_display(f->mlx_connection);
		free(f->mlx_connection);
		malloc_issue(3);
	}
	f->imgid.pa = mlx_get_data_addr(f->imgid.ia, &f->imgid.bpp,
			&f->imgid.ll, &f->imgid.endian);
	events_beginning(f);
	data_beginning(f);
}
// from: https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html
