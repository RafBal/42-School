/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:41:41 by rbaldin           #+#    #+#             */
/*   Updated: 2024/11/08 15:07:28 by rbaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	size_t	ft_min(size_t sl, unsigned int start, size_t len);

static	size_t	ft_gs(char const *s, size_t al, unsigned int start, char *ma)
{
	size_t	i;

	i = 0;
	while (i < al)
	{
		ma[i] = s[start + i];
		i++;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*ma;
	size_t		i;
	size_t		sl;
	size_t		al;

	if (!s)
		return (NULL);
	sl = ft_strlen(s);
	if (start >= sl)
	{
		ma = (char *)malloc(1);
		if (ma)
			ma[0] = '\0';
		return (ma);
	}
	al = ft_min(sl, start, len);
	ma = (char *) malloc(al + 1);
	if (!ma)
		return (NULL);
	i = ft_gs(s, al, start, ma);
	ma[i] = '\0';
	return (ma);
}

static	size_t	ft_min(size_t sl, unsigned int start, size_t len)
{
	if (start >= sl)
		return (0);
	if (sl - start < len)
		return (sl - start);
	else
		return (len);
}
/*
int main(void){

	printf("%s\n", ft_substr("lorem ipsum dolor sit amet",0,10));
        printf("%s\n", ft_substr("lorem ipsum dolor sit amet", 7,10));
}
*/
