/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_only.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:04:41 by rbaldin           #+#    #+#             */
/*   Updated: 2025/02/24 16:21:37 by rbaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	int	is_valid_double(const char *string)
{
	size_t	i;
	size_t	decimal;

	i = 0;
	decimal = 0;
	while (string[i])
	{
		if (string[i] == '.')
		{
			if (decimal)
				return (0);
			decimal = 1;
		}
		else if (!ft_isdigit(string[i]))
			return (0);
		i++;
	}
	return (1);
}

int	double_only(const char *str)
{
	if (!str || !str[0])
		return (0);
	if (*str == '-' || *str == '+')
	{
		str++;
		if (!ft_isdigit(*str) && *str != '.')
			return (0);
	}
	return (is_valid_double(str));
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
