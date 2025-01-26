/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:26:34 by rbaldin           #+#    #+#             */
/*   Updated: 2025/01/26 10:57:00 by rbaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	cost_calculation(t_stack **st_a, size_t index)
{
	if (index <= (*st_a)->size / 2)
		ra(st_a);
	else
		rra(st_a);
}

static	long	max_num_finding(t_stack *a)
{
	long	n;
	long	max_n;
	t_list	*current;

	max_n = INT_MIN;
	current = a->top;
	while (current)
	{
		n = *(long *)(current->content);
		if (max_n < n)
			max_n = n;
		current = current->next;
	}
	return (max_n);
}

static	size_t	bits_counting(t_stack *a)
{
	long	max_num;
	size_t	max_bits;

	max_bits = 0;
	max_num = max_num_finding(a);
	while ((max_num >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

static	void	minus_adjustement(t_stack *a, int off_num)
{
	long	n;
	t_list	*temp;

	temp = a->top;
	while (temp)
	{
		n = *(long *)(temp->content);
		n = n - off_num;
		*(long *)(temp->content) = n;
		temp = temp->next;
	}
}

void	radix(t_stack **a, t_stack **b, int off_num)
{
	size_t	nbits;
	long	n;
	int	i;
	size_t	bit;
	int	size;

	if (off_num < 0)
		minus_adjustment(*a, off_num);
	nbits = bits_counting(*a);
	i = 0;
	bit = 0;
	while (bit < nbits)
	{
		size = (*a)->size;
		i = 0;
		while (i < size)
		{
			n = *(long *)((*a)->top->content);
			if (((n >> i) & 1) == 0)
				pb(a, b);
			else
				cost_calculation(a, i);
			i++;
		}
		logical_optimization(a, b);
		while ((*b)->size > 0)
			pa(a, b);
		bit++;
	}
	if (off_num < 0)
		minus_adjustement(*a, -off_num);
	return;
}
