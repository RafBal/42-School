/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:55:54 by rbaldin           #+#    #+#             */
/*   Updated: 2024/10/29 11:24:27 by rbaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;	

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = '\0';
		i++;
	}
}
/*
int main(void) {
	
	int	arr[3] = {4,3,5};
	int	arr2[3] = {4,3,5};
	
	ft_bzero(arr, 3);
	bzero(arr2, 3);
	for (int i = 0; i < 3; i++){
		printf("%d", arr[i]);
	}
	printf("\n");
	for (int i = 0; i < 3; i++){
		printf("%d", arr2[i]);
	}
	

}
*/
