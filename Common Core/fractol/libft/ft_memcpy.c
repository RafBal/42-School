/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:12:07 by rbaldin           #+#    #+#             */
/*   Updated: 2024/11/05 10:29:48 by rbaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char	*s;
	char		*d;

	if (!dest && !src)
		return (NULL);
	s = (const char *) src;
	d = (char *) dest;
	while (n--)
		*d++ = *s++;
	return (dest);
}
/*
int main(void)
{

	char src1[] = "Hello, World!";
	char dest1[20];
        char dest2[20];
	ft_memcpy(dest1,src1,strlen(src1) + 1);
        memcpy(dest2,src1,strlen(src1) + 1);
	printf("Test 1 - Basic copy");
	printf("%s\n", dest1);
	printf("%s\n", dest2);
 
	char src2[] = "Test";
	char dest3[10];
	char dest4[10];
	ft_memcpy(dest3,src2,strlen(src2));
	memcpy(dest4,src2,strlen(src2));
	printf("Test 2 - Copy with size\n");
	printf("%s\n", dest3);
	printf("%s\n", dest4);
	
	char src3[] = "Overlap Test";
	char src4[] = "Overlap Test";
	ft_memcpy(src3 + 2,src3, 10);
	memcpy(src4 + 2, src4, 10);
	printf("Test 3 - Overlap\n");
	printf("%s\n", src3);
	printf("%s\n", src4);

	// Test Case 4: Null Pointers
    char *nullDest = NULL;
    char *nullSrc = NULL;
	
	if (ft_memcpy(nullDest, nullSrc, 5) == NULL) {
        printf("Test 4 - Null Pointers: Passed\n"); // Expected: Passed
    } else {
        printf("Test 4 - Null Pointers: Failed\n");
    }

    // Test Case 5: Zero Bytes
    char emptyDest[10] = {0}; // Initialize to zero
    ft_memcpy(emptyDest, src1, 0); // Should do nothing
    printf("Test 5 - Zero Bytes: %s\n", emptyDest); // Expected: (empty output)
		
}
*/
