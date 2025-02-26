/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrn_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 11:56:16 by rbaldin           #+#    #+#             */
/*   Updated: 2024/12/02 10:55:07 by rbaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_exceptions(int n, int fd);

static	size_t	ft_count(int n)
{
	size_t	i;
	int		nb;

	i = 0;
	nb = n;
	while (nb != 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

static	int	ft_count_pow(int n, int i);

static	void	ft_printing_nums(int i, int n, int nb, int fd);

int	ft_nbrn_count(int n, int fd)
{
	size_t	i;
	int		nb;

	if (n <= 0)
		return (ft_exceptions(n, fd));
	else
	{
		nb = n;
		i = ft_count(n);
		ft_printing_nums(i, n, nb, fd);
	}
	return (ft_count(n));
}

static	void	ft_printing_nums(int i, int n, int nb, int fd)
{
	while (i > 0)
	{
		nb = ft_count_pow(n, i - 1);
		nb %= 10;
		nb += '0';
		write(fd, &nb, 1);
		nb -= '0';
		i--;
	}
}

static	int	ft_count_pow(int n, int i)
{
	while (i > 0)
	{
		n /= 10;
		i--;
	}
	return (n);
}

static	int	ft_exceptions(int n, int fd)
{
	if (n == -2147483648)
	{
		return (write(fd, "-2147483648", 11));
	}
	else if (n == 0)
		return (write(fd, "0", 1));
	else
	{
		n = n * (-1);
		return (write(fd, "-", 1) + ft_nbrn_count(n, fd));
	}
}
	/*
int main(void)
{
	ft_putnbr_fd(0, 1);
	write(1, "\n", 1);
	ft_putnbr_fd(5, 1);
	write(1, "\n", 1);
	ft_putnbr_fd(12, 1);
	write(1, "\n", 1);  
         ft_putnbr_fd(123, 1);
	write(1, "\n", 1);
	ft_putnbr_fd(2147483647, 1);
	write(1, "\n", 1);
	ft_putnbr_fd(-7, 1);
	write(1, "\n", 1);
	ft_putnbr_fd(-2147483648, 1);
	write(1, "\n", 1);
	ft_putnbr_fd(-1, 1);
         write(1, "\n", 1);
         ft_putnbr_fd(1, 1);
         write(1, "\n", 1);
       ft_putnbr_fd(-42, 1);
          write(1, "\n", 1);
          ft_putnbr_fd(42, 1);
          write(1, "\n", 1);
}
*/
