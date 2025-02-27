/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:08:47 by rbaldin           #+#    #+#             */
/*   Updated: 2025/02/24 17:40:36 by rbaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

/*
 oi = old_index
 ni = new_index
 nmn = new_min
 nmx = new_max
 omn = old_min
 omx = old_max
 */

double	remapping(double oi, double nmn, double nmx, double omx)
{
	double	ni;
	double	omn;

	omn = 0;
	ni = (nmx - nmn) * (oi - omn) / (omx - omn) + nmn;
	return (ni);
}

/*
A simple program to test the remapping function.
int	main(void)
{
	for (int i = 0; i < 10; ++i)
	{
		printf("%d -> %f\n", i, remapping((double)i, 0, 30, 10));
	}
	return (0);
}
*/

t_z	sum_z(t_z complex1, t_z complex2)
{
	t_z	answer;

	answer.x = complex1.x + complex2.x;
	answer.y = complex1.y + complex2.y;
	return (answer);
}

t_z	square_z(t_z complexn)
{
	t_z	answer;

	answer.x = complexn.x * complexn.x - complexn.y * complexn.y;
	answer.y = 2 * complexn.x * complexn.y;
	return (answer);
}

double	atodbl(char *s)
{
	long	integer_part;
	double	fractional_part;
	double	pow;
	int		sign;

	integer_part = 0;
	fractional_part = 0;
	sign = 1;
	pow = 1;
	while ((*s >= 9 && *s <= 13) || ' ' == *s)
		s++;
	while ('+' == *s || '-' == *s)
		if ('-' == *s++)
			sign = -sign;
	while (*s != '.' && *s)
		integer_part = (integer_part * 10) + (*s++ - '0');
	while ('.' == *s)
		s++;
	while (*s)
	{
		pow /= 10;
		fractional_part = fractional_part + (*s++ - '0') * pow;
	}
	return ((integer_part + fractional_part) * sign);
}

/*
int main(void)
{
	int r;
	r = double_only("+fgva0.1");
	printf("%d\n for double ", r); 
	return (0);
}
*/
