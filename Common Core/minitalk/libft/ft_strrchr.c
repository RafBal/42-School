/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 09:29:22 by rbaldin           #+#    #+#             */
/*   Updated: 2024/11/05 08:16:18 by rbaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*ptr;

	if (ft_strlen(s) == 0)
	{
		if (c == '\0')
			return ((char *)s);
		else
			return (NULL);
	}
	ptr = s + ft_strlen(s);
	while (ptr >= s)
	{
		if (*ptr == (unsigned char)c)
			return ((char *) ptr);
		ptr--;
	}
	if (c == '\0')
		return ((char *)s + ft_strlen(s));
	else
		return (NULL);
}
/*
int main(void){

	printf("%s\n", ft_strrchr("mamata",'m'));
	printf("%s\n", strrchr("mamata",'m'));
	printf("%s\n", ft_strrchr("ababa", 'b'));
	printf("%s\n", strrchr("ababa", 'b'));
}
*/
