/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_uns_nbr_count.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:27:20 by rbaldin           #+#    #+#             */
/*   Updated: 2024/12/02 15:35:12 by rbaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_count(unsigned int nb)
{
	int	i;

	i = 0;
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

static	char	ft_get_dig(unsigned int nb, int i)
{
	int	j;

	j = 0;
	while (++j < i)
		nb /= 10;
	return ((nb % 10) + '0');
}

int	ft_put_uns_nbr_count(va_list args, int fd)
{
	unsigned int	n;
	int				i;
	int				pc;
	char			digit;

	i = 0;
	pc = 0;
	n = (unsigned int) va_arg(args, unsigned int);
	if (n == 0)
		return (write(fd, "0", 1));
	else if (n > 0)
	{
		i = ft_count(n);
		while (i > 0)
		{
			digit = ft_get_dig(n, i);
			pc += write(fd, &digit, 1);
			i--;
		}
	}
	return (pc);
}
