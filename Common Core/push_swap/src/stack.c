/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:34:11 by rbaldin           #+#    #+#             */
/*   Updated: 2025/01/31 13:28:40 by rbaldin          ###   ########.fr       */
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

t_stack	*stack_initializing(int	*nums, int *size)
{
	t_stack	*stackt;
	t_list	*nodet;
	int	it;
	int	*value;
	
	stackt = ft_calloc(1, sizeof(t_stack));
	if (!stackt)
		return (NULL);
	stackt->top = NULL;
	stackt->size = *size;
	it = *size;
	while (it > 0)
	{
		value = malloc(sizeof(long));
		if (!value || !(nodet = ft_lstnew(value)))
		{
			free(value);
			return(removing_stack(&stackt));
		}
		*value = (long)nums[it - 1];
		//printf("Adding to stack: %d\n", nums[it - 1]);
		ft_lstadd_front(&(stackt->top), nodet);
		it--;
	}
	return (stackt);
}

t_stack	*null_stack_initializing(void)
{
	t_stack *stacknull;

	stacknull = ft_calloc(1, sizeof(t_stack));
	if (!stacknull)
		return (NULL);
	stacknull->top = NULL;
	stacknull->size = 0;
	return (stacknull);
}

void	stack_freeing(t_stack **stack)
{
	if (!stack || !(*stack))
		return;
	if ((*stack)->top)
		ft_lstclear(&((*stack)->top), free);
	free(*stack);
	*stack = NULL;
}
