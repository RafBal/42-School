/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 09:17:50 by rbaldin           #+#    #+#             */
/*   Updated: 2024/11/05 10:33:38 by rbaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d_temp;
	unsigned char		*s_temp;
	size_t				count;

	if (!dest && !src)
		return (NULL);
	count = 0;
	d_temp = (unsigned char *)dest;
	s_temp = (unsigned char *)src;
	if (d_temp > s_temp)
	{
		while (n--)
			d_temp[n] = s_temp[n];
	}
	else
	{
		while (count < n)
		{
			d_temp[count] = s_temp[count];
			count++;
		}
	}
	return (dest);
}
