/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:59:22 by rbaldin           #+#    #+#             */
/*   Updated: 2024/10/23 11:28:31 by rbaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	return (c);
}
/*
int main(void)
{
	printf("%c\n", ft_toupper(99));
	printf("%c\n", ft_toupper('A'));
        printf("%c\n", ft_toupper(75));
        printf("%c\n", ft_toupper('Z'));
        printf("%c\n", ft_toupper('d'));
        printf("%c\n", ft_toupper(108));

}
*/
