/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:58:49 by rbaldin           #+#    #+#             */
/*   Updated: 2024/11/09 14:38:02 by rbaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	l;

	l = 0;
	while (lst)
	{
		lst = lst->next;
		l++;
	}
	return (l);
}
/*
#include <stdio.h>
int main(){
	t_list	*list = NULL; // Empty list case.

	printf("List size (empty): %d\n", ft_lstsize(list));

// Adding a few nodes for testing.
t_list node1 = {"Node 1", NULL};
t_list node2 = {"Node 2", NULL};
t_list node3 = {"Node 3", NULL};

node1.next = &node2;
node2.next = &node3;
list = &node1;

printf("List size (3 nodes): %d\n", ft_lstsize(list));
return (0);
}
*/
