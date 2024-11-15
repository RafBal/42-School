/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:08:31 by rbaldin           #+#    #+#             */
/*   Updated: 2024/10/23 10:02:01 by rbaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		ptr[i] = (unsigned char) c;
		i++;
	}
	return (s);
}
/*
int main(void){

	int arr[10];
	int arr2[10];
	memset(arr, 0, sizeof(arr));
	ft_memset(arr2, 0 ,sizeof(arr2));

	for (int i = 0; i < 10; i++){
		printf("%d", arr[i]);	
	}
	printf("\n");
	for (int i = 0; i < 10; i++){
		printf("%d", arr2[i]);
	}
}
*/
