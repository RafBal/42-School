/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:12:44 by rbaldin           #+#    #+#             */
/*   Updated: 2024/10/22 14:33:10 by rbaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
/*
int main(void){

	printf("%d\n", ft_isascii('t'));
	printf("%d\n", ft_isascii(255));
	printf("%d\n", ft_isascii(-25));
	printf("%d\n", ft_isascii('1'));
}
*/
