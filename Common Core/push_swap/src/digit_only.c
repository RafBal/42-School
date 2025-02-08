/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit_only.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:32:16 by rbaldin           #+#    #+#             */
/*   Updated: 2025/02/05 09:57:44 by rbaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	digit_only(const char *str)
{
	size_t	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (i + 1 <= ft_strlen(str))
		{
			if (ft_isdigit(str[i + 1]))
				i++;
			else
				return (0);
		}
		else
			return (0);
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
