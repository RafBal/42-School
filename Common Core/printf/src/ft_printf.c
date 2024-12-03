/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:20:46 by rbaldin           #+#    #+#             */
/*   Updated: 2024/11/29 15:47:26 by rbaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_type_checker(va_list args, const char *type)
{
	int	pc;

	pc = 0;
	if (*type == 'c')
		pc = ft_printf_char(args, 1);
	else if (*type == 's')
		pc = ft_printf_str(args, 1);
	else if (*type == 'p')
		pc = ft_printf_ptr(args, 1);
	else if (*type == 'd' || *type == 'i')
		pc = ft_putnbr_fd_count(args, 1);
	else if (*type == 'u')
		pc = ft_put_uns_nbr_count(args, 1);
	else if (*type == 'x')
		pc = ft_put_hex(args, 1, 'x');
	else if (*type == 'X')
		pc = ft_put_hex(args, 1, 'X');
	else if (*type == '%')
		pc = write(1, "%", 1);
	return (pc);
}

int	ft_printf(const char *type, ...)
{
	va_list	args;
	int		pc;

	pc = 0;
	va_start(args, type);
	while (*type)
	{
		if (*type == '%' && *(type + 1))
		{
			type++;
			pc += ft_type_checker(args, type);
		}
		else
		{
			write(1, type, 1);
			pc++;
		}
		type++;
	}
	va_end(args);
	return (pc);
}
