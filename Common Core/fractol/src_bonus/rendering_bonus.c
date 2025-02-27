/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 19:20:44 by rbaldin           #+#    #+#             */
/*   Updated: 2025/02/24 17:39:45 by rbaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static	void	ft_mlx_pixel_put(t_imageid *detail, int x, int y, int colour)
{
	char	*destiny;
	int		compensation;

	compensation = (y * detail->ll + x * (detail->bpp / 8));
	destiny = detail->pa + compensation;
	*(unsigned int *)destiny = colour;
}
// from: https://42-cursus.gitbook.io/guide/minilibx/minilibx-helper-function 
// from: https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html

static	void	mandelbroting(int x, int y, t_fractalid *f)
{
	t_z	z;
	t_z	c;
	int	i;
	int	colour;

	i = 0;
	z.x = f->start_x;
	z.y = f->start_y;
	c.x = f->focus * remapping(x, -2, +2, W) + f->change_x;
	c.y = f->focus * remapping(y, -2, +2, H) + f->change_y;
	while (i < f->resolution_index)
	{
		z = sum_z(square_z(z), c);
		if (z.x * z.x + z.y * z.y > f->outbound_value)
		{
			colour = remapping(i, BLACK, WHITE, f->resolution_index);
			ft_mlx_pixel_put(&(f->imgid), x, y, colour);
			return ;
		}
		i++;
	}
	ft_mlx_pixel_put(&(f->imgid), x, y, RED);
}

static	void	julianing(int x, int y, t_fractalid *f)
{
	t_z	z;
	t_z	c;
	int	i;
	int	colour;

	i = 0;
	c.x = f->start_x;
	c.y = f->start_y;
	z.x = f->focus * remapping(x, -2, +2, W) + f->change_x;
	z.y = f->focus * remapping(y, -2, +2, H) + f->change_y;
	while (i < f->resolution_index)
	{
		z = sum_z(square_z(z), c);
		if (z.x * z.x + z.y * z.y > f->outbound_value)
		{
			colour = remapping(i, BLACK, WHITE, f->resolution_index);
			ft_mlx_pixel_put(&(f->imgid), x, y, colour);
			return ;
		}
		i++;
	}
	ft_mlx_pixel_put(&(f->imgid), x, y, RED);
}

void	rendering(t_fractalid *f)
{
	int	x;
	int	y;

	y = -1;
	while (++y < H)
	{
		x = -1;
		while (++x < W)
		{
			if (!ft_strncmp(f->name, "julia", 5))
				julianing(x, y, f);
			else
				mandelbroting(x, y, f);
		}
	}
	mlx_put_image_to_window(f->mlx_connection, f->mlx_window, f->imgid.ia \
			, 0, 0);
}
