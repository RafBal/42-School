/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:02:52 by rbaldin           #+#    #+#             */
/*   Updated: 2024/11/05 08:37:23 by rbaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	st;
	size_t	cl;

	if (size > 0)
		cl = size - 1;
	else
		cl = 0;
	st = ft_strlen(src);
	if (cl > st)
		cl = st;
	if (cl > 0)
		ft_memcpy(dst, src, cl);
	if (size > 0)
		dst[cl] = '\0';
	return (st);
}
