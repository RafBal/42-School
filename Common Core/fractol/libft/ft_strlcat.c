/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:37:32 by rbaldin           #+#    #+#             */
/*   Updated: 2024/11/11 13:03:40 by rbaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	ls;
	size_t	ld;
	size_t	cpyl;

	ls = ft_strlen(src);
	if (!size && !dst)
		return (ls);
	ld = ft_strlen(dst);
	if (size <= ld)
		return (size + ls);
	cpyl = size - ld - 1;
	if (cpyl > ls)
		cpyl = ls;
	ft_memcpy(dst + ld, src, cpyl);
	dst[ld + cpyl] = '\0';
	return (ls + ld);
}
/*
#include <stdio.h>
#include <string.h>

int main() {
	char dest[20] = "Hello, ";
	const char *src = "World!";
	size_t size = sizeof(dest);

	ft_strlcat(dest, src, size);
	
	printf("Result = %s\n", dest);
	
	return (0);
}
*/
