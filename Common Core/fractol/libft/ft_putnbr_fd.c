/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 11:56:16 by rbaldin           #+#    #+#             */
/*   Updated: 2024/11/08 15:21:40 by rbaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static	void	ft_exceptions(int n, int fd);

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

void	ft_putnbr_fd(int n, int fd)
{
	size_t	i;
	int		nb;

	if (n <= 0)
		ft_exceptions(n, fd);
	else
	{
		nb = n;
		i = ft_count(n);
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

static	void	ft_exceptions(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
	}
	else if (n == 0)
		write(fd, "0", 1);
	else
	{
		write(fd, "-", 1);
		n = n * (-1);
		ft_putnbr_fd(n, fd);
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
