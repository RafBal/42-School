/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:11:24 by rbaldin           #+#    #+#             */
/*   Updated: 2024/11/08 15:12:30 by rbaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	int	ft_count(int i, int n)
{
	int	nb;

	nb = n;
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

static	void	ft_assign(char *lit_num, int i, int n, int is_n)
{
	lit_num[i] = '\0';
	while (i-- > 0)
	{
		lit_num[i] = (n % 10) + '0';
		n /= 10;
	}
	if (is_n)
		lit_num[0] = '-';
}

static	char	*ft_z_or_int_min(int n)
{
	char	*lit_num;

	if (n == 0)
	{
		lit_num = (char *)malloc(2);
		if (lit_num)
			ft_strlcpy(lit_num, "0", 2);
		return (lit_num);
	}
	else
	{
		lit_num = (char *)malloc(12);
		if (lit_num)
			ft_strlcpy(lit_num, "-2147483648", 12);
		return (lit_num);
	}
}

char	*ft_itoa(int n)
{
	char	*lit_num;
	int		i;
	int		is_n;

	i = 0;
	is_n = 0;
	if (n == 0 || n == -2147483648)
		return (ft_z_or_int_min(n));
	if (n < 0)
	{
		n = -n;
		is_n = 1;
	}
	i = ft_count(i, n) + is_n;
	lit_num = (char *)malloc(i + 1);
	if (!lit_num)
		return (NULL);
	ft_assign(lit_num, i, n, is_n);
	return (lit_num);
}
/*
int main(void)
{
	printf("%s\n", ft_itoa(1234));
	printf("%s\n", ft_itoa(-5678));
	printf("%s\n", ft_itoa(-9281));
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(-2147483648));
}
*/
