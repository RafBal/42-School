/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:07:02 by rbaldin           #+#    #+#             */
/*   Updated: 2024/11/08 15:08:19 by rbaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ch;
	size_t	l;
	size_t	size1;
	size_t	size2;

	if (!s1 || !s2)
		return (NULL);
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	l = size1 + size2;
	ch = (char *)malloc(l + 1);
	if (!ch)
		return (NULL);
	ft_strlcpy(ch, s1, size1 + 1);
	ft_strlcat(ch, s2, size1 + size2 + 1);
	return (ch);
}
/*
int main(void){

	printf("%s", ft_strjoin("batata"," frita"));
}
*/
