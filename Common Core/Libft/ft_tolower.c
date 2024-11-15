/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:16:28 by rbaldin           #+#    #+#             */
/*   Updated: 2024/10/23 11:26:00 by rbaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	return (c);
}
/*
int main(void){

	printf("%c\n", ft_tolower('A'));
	printf("%c\n", ft_tolower(75));
	printf("%c\n", ft_tolower('Z'));
	printf("%c\n", ft_tolower('d'));
	printf("%c\n", ft_tolower(108));
}
*/
