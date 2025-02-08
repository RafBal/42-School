/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sixless_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 09:54:01 by rbaldin           #+#    #+#             */
/*   Updated: 2025/02/08 16:33:08 by rbaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	spin_spending(t_stack **stck_a, int index)
{
	if (!stck_a || !(*stck_a) || !(*stck_a)->top)
		return ;
	if (index <= (*stck_a)->size / 2)
	{
		while (index > 0)
		{
			ra(stck_a);
			index--;
		}
	}
	else
	{
		while (index <= (*stck_a)->size - 1)
		{
			rra(stck_a);
			index++;
		}
	}
}

static	int	min_num_finding(t_stack *st_a)
{
	int		min_n;
	int		n;
	t_list	*present;

	if (!st_a || !st_a->top)
		return (0);
	present = st_a->top;
	min_n = *(int *)(present->content);
	while (present)
	{
		n = *(int *)(present->content);
		if (min_n > n)
			min_n = n;
		present = present->next;
	}
	return (min_n);
}

static	void	min_pushing(t_stack **stack_a, t_stack **stack_b)
{
	int		min_num;
	t_list	*min_node;
	int		i;

	if (!stack_a || !(*stack_a) || !(*stack_a)->top)
		return ;
	min_num = min_num_finding(*stack_a);
	min_node = (*stack_a)->top;
	i = -1;
	while (++i < (*stack_a)->size)
	{
		if (min_num == *(int *)min_node->content)
			break ;
		min_node = min_node->next;
	}
	spin_spending(stack_a, i);
	pb(stack_a, stack_b);
}

void	sixless_sort(t_stack **a, t_stack **b)
{
	if ((*a)->size == 4)
	{
		min_pushing(a, b);
		push_swap(a, b);
		pa(b, a);
	}
	else
	{
		min_pushing(a, b);
		min_pushing(a, b);
		push_swap(a, b);
		pa(b, a);
		pa(b, a);
	}
}
