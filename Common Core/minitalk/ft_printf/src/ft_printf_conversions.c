/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:25:14 by rbaldin           #+#    #+#             */
/*   Updated: 2024/12/02 15:33:44 by rbaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_char(va_list args, int fd)
{
	char	character;

	character = (char) va_arg(args, int);
	return (write(fd, &character, 1));
}

int	ft_printf_str(va_list args, int fd)
{
	char	*string;
	int		pc;

	pc = 0;
	string = va_arg(args, char *);
	if (!string)
		string = "(null)";
	while (*string)
		pc += write(fd, string++, 1);
	return (pc);
}

static	int	ft_put_x(unsigned long n, int fd, const char *chain);

int	ft_put_hex(va_list args, int fd, const char form)
	{
	unsigned long	n;
	int				pc;

	pc = 0;
	n = va_arg(args, unsigned int);
	if (form == 'x')
		return (ft_put_x(n, fd, "0123456789abcdef"));
	else
		return (ft_put_x(n, fd, "0123456789ABCDEF"));
}

static	int	ft_put_x(unsigned long n, int fd, const char *chain)
{
	int	pc;

	pc = 0;
	if (n >= 16)
		pc += ft_put_x(n / 16, fd, chain);
	pc += write(fd, &chain[n % 16], 1);
	return (pc);
}

int	ft_printf_ptr(va_list args, int fd)
{
	void	*p;
	int		pc;

	p = va_arg(args, void *);
	if (p == NULL)
		return (write(fd, "(nil)", 5));
	pc = write(fd, "0x", 2);
	pc += ft_put_x((unsigned long)p, fd, "0123456789abcdef");
	return (pc);
}
