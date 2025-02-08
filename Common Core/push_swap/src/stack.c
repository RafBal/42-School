/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:34:11 by rbaldin           #+#    #+#             */
/*   Updated: 2025/02/04 11:34:43 by rbaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static	void	*removing_stack(t_stack **st)
{
	if (!st || !(*st))
		return (NULL);
	ft_lstclear(&((*st)->top), free);
	free(*st);
	return (NULL);
}

static	t_list	*creating_stack(t_list *nodt, int *n, t_stack *stkt, int i)
{
	int	*v;

	v = malloc(sizeof(int));
	if (!v)
	{
		removing_stack(&stkt);
		return (NULL);
	}
	*v = n[i - 1];
	nodt = ft_lstnew(v);
	if (!nodt)
	{
		free(v);
		removing_stack(&stkt);
		return (NULL);
	}
	return (nodt);
}

t_stack	*stack_initializing(int	*nums, int *size)
{
	t_stack	*stackt;
	t_list	*nodet;
	int		it;

	stackt = ft_calloc(1, sizeof(t_stack));
	if (!stackt)
		return (NULL);
	stackt->top = NULL;
	stackt->size = *size;
	it = *size;
	nodet = NULL;
	while (it > 0)
	{
		nodet = creating_stack(nodet, nums, stackt, it);
		if (!nodet)
			return (NULL);
		ft_lstadd_front(&(stackt->top), nodet);
		it--;
	}
	return (stackt);
}

t_stack	*null_stack_initializing(void)
{
	t_stack	*stacknull;

	stacknull = ft_calloc(1, sizeof(t_stack));
	if (!stacknull)
		return (NULL);
	stacknull->top = NULL;
	stacknull->size = 0;
	return (stacknull);
}
