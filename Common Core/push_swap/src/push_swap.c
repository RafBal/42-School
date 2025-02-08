/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:21:57 by rbaldin           #+#    #+#             */
/*   Updated: 2025/02/07 10:45:22 by rbaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	three_sort(t_stack *a, t_list *t, t_list *m, t_list *bot)
{
	int	topc;
	int	middlec;
	int	bottomc;

	topc = *(int *)(t->content);
	middlec = *(int *)(m->content);
	bottomc = *(int *)(bot->content);
	if (topc < middlec && topc < bottomc && middlec > bottomc)
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

bool	sorted_already(t_stack *s)
{
	t_list	*now;

	if (!s || !s->top || !s->top->next)
		return (true);
	now = s->top;
	while (now && now->next)
	{
		if (*(int *)now->content > *(int *)now->next->content)
			return (false);
		now = now->next;
	}
	return (true);
}

void	push_swap(t_stack **a, t_stack **b)
{
	t_list	*high;
	t_list	*medium;
	t_list	*low;

	if (sorted_already(*a))
		return ;
	else if ((*a)->size == 2)
	{
		sa(a);
		return ;
	}
	else if ((*a)->size == 3)
	{
		high = (*a)->top;
		medium = high->next;
		low = medium->next;
		three_sort(*a, high, medium, low);
	}
	else if ((*a)->size < 6)
		sixless_sort(a, b);
	else
	{
		values_simplifying(*a);
		radix(a, b);
	}
}
