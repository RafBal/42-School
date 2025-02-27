/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:56:05 by rbaldin           #+#    #+#             */
/*   Updated: 2025/02/24 15:55:32 by rbaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
 The prompt for the mandatory part can be typed in two ways:
 ./fractol mandelbrot
 ./fractol julia "real number" "imaginary number" 
 */

static	void	mandelbrot_starting(t_fractalid *f)
{
	f->start_x = 0.0;
	f->start_y = 0.0;
}

static	int	julia_checking(t_fractalid *fra, char **av)
{
	int	valid;

	valid = 0;
	if (double_only(av[3]) && double_only(av[2]))
	{
		valid = 1;
		fra->start_x = atodbl(av[2]);
		fra->start_y = atodbl(av[3]);
	}
	return (valid);
}

static	void	wrong_arguments(void)
{
	errno = EINVAL;
	perror(ERROR_MESSAGE);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_fractalid	fract;

	if (2 == argc && !ft_strncmp(argv[1], "mandelbrot", 10))
		mandelbrot_starting(&fract);
	else if (4 == argc && !ft_strncmp(argv[1], "julia", 5))
	{
		if (!julia_checking(&fract, argv))
			wrong_arguments();
	}
	else
		wrong_arguments();
	fract.name = argv[1];
	initializing(&fract);
	rendering(&fract);
	mlx_loop(fract.mlx_connection);
	return (0);
}
