/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 07:42:40 by rbaldin           #+#    #+#             */
/*   Updated: 2024/10/28 08:01:41 by rbaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1uc;
	unsigned char	*s2uc;

	s1uc = (unsigned char *)s1;
	s2uc = (unsigned char *)s2;
	while (n > 0)
	{
		if (*s1uc != *s2uc)
			return (*s1uc - *s2uc);
		s1uc++;
		s2uc++;
		n--;
	}
	return (0);
}
