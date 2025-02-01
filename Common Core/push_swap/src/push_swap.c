/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:21:57 by rbaldin           #+#    #+#             */
/*   Updated: 2025/02/01 16:54:48 by rbaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	min_finding(t_stack **a)
{
	int	min_num;
	int	n_to_compare;
	t_list	*a_reserv;
	
	a_reserv = (*a)->top;
	min_num = INT_MAX;
	while (a_reserv)
	{
		n_to_compare = *(long *)(a_reserv->content);
		if (n_to_compare < min_num)
			min_num = n_to_compare;
		a_reserv = a_reserv->next;
	}
	if (min_num < 0)
		return (min_num);
	return (0);
}

static	void	three_sort(t_stack *a, t_list *top, t_list *middle, t_list *bottom)
{
	int	topc;
	int	middlec;
	int	bottomc;

	topc = *(long *)(top->content);
	middlec = *(long *)(middle->content);
	bottomc = *(long *)(bottom->content);
	if (topc < middlec && middlec && middlec > bottomc)
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
		if (*(long *)now->content > *(long *)now->next->content)
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
	int	off_num;

	if (sorted_already(*a))
		return;
	else if ((*a)->size == 2)
	{
		sa(a);
		return;
	}
	else if ((*a)->size == 3)
	{
		high = (*a)->top;
		medium = high->next;
		low = medium->next;
		three_sort(*a, high, medium, low);
	}
	else
	{
		off_num = min_finding(a);
		radix(a, b, off_num);
	}
}
