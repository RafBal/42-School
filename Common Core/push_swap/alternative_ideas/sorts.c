/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 09:13:33 by rbaldin           #+#    #+#             */
/*   Updated: 2025/01/17 15:54:12 by rbaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted_already(t_stack *s)
{
	t_list	*now;

	now = s->top;
	while (now && now->next)
	{
		if ((int)(long)now->content > (int)(long)now->next->content)
			return (0);
		now = now->next;
	}
	return (1);
}

void	three_sort(t_stack *a, t_list *top, t_list *middle, t_list *bottom)
{
	int	topc;
	int	middlec;
	int	bottomc;
	 
	topc = *(long *)(top->content);
	middlec = *(long *)(middle->content);
	bottomc = *(long *)(bottom->content);
	if (topc < middlec && middlec > bottomc)
	{
		 rra(&a);
		 sa(&a);
	}
	else if (topc > middlec && middlec > bottomc)
	{
		sa(&a);
		rra(&a);
	}
	else if (topc > middlec && middlec < bottomc && topc > bottomc)
		ra(&a);
	else if (topc > middlec && middlec < bottomc && topc < bottomc)
		 sa(&a);
	else
		 rra(&a);
}
