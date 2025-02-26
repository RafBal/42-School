/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 18:10:29 by rbaldin           #+#    #+#             */
/*   Updated: 2024/11/04 10:52:09 by rbaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*suc;

	suc = (unsigned char *) s;
	while (n)
	{
		if ((unsigned char) c == *suc)
			return ((void *) suc);
		suc++;
		n--;
	}
	return (NULL);
}
