/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:34:11 by rbaldin           #+#    #+#             */
/*   Updated: 2025/01/15 10:24:41 by rbaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_initializing(int	*nums, int *size)
{
	t_stack	*stackt;
	t_list	*nodet;
	int	it;
	
	stackt = ft_calloc(1, sizeof(t_stack));
	if (!stackt)
		return (NULL);
	stackt->top = NULL;
	stackt->size = *size;
	it = *size;
	while (it > 0)
	{
		nodet = ft_lstnew((void *)(long)nums[it - 1]);
		if (!nodet)
		{
			ft_lstclear(&(stackt->top), free);
			free(stackt);
			return (NULL); 
		}
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
	ft_lstclear(&((*stack)->top), free);
	free(*stack);
	*stack = NULL;
}
