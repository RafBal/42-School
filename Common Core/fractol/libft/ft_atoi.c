/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:09:41 by rbaldin           #+#    #+#             */
/*   Updated: 2024/10/29 10:26:21 by rbaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	res;
	int	sign_minus;

	sign_minus = 1;
	res = 0;
	while (*nptr == ' ' || *nptr == '\t' || *nptr == '\n' || *nptr == '\v'
		|| *nptr == '\f' || *nptr == '\r')
		nptr++;
	if (*nptr == '-')
	{
		sign_minus = -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (ft_isdigit(*nptr))
		res = res * 10 + (*nptr++ - '0');
	return (res * sign_minus);
}
/*
int main(void){

	printf("%d\n", ft_atoi("546:5"));
	printf("%d\n", atoi("546:5"));
	printf("%d\n", ft_atoi("\e475"));
	printf("%d\n", atoi("\e475"));
	printf("%d\n", ft_atoi("\t\n\r\v\f  469 \n"));
          printf("%d\n", atoi("\t\n\r\v\f  469 \n"));
          printf("%d\n", ft_atoi("2147483647"));
          printf("%d\n", atoi("2147483647"));
	  printf("%d\n", ft_atoi("\t\n\r\v\fd469 \n"));
          printf("%d\n", atoi("\t\n\r\v\fd469 \n"));
	  printf("%d\n", ft_atoi(""));           
        printf("%d\n", atoi(""));
}
*/
