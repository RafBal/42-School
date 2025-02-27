/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:45:26 by rbaldin           #+#    #+#             */
/*   Updated: 2024/10/22 14:58:12 by rbaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	st;

	st = 0;
	while (*s)
	{
		st++;
		s++;
	}
	return (st);
}
/*
int main(void){

	printf("%ld\n", ft_strlen("camelo"));
	printf("%ld\n", strlen("camelo"));
	printf("%ld\n", ft_strlen("boa"));
	printf("%ld\n", strlen("boa"));
}
*/
