/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:26:34 by rbaldin           #+#    #+#             */
/*   Updated: 2025/02/10 15:36:53 by rbaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	radix_b(t_stack **sta, t_stack **stb, int bt, int maxbits)
{
	int	i;
	int	sizb;
	int	nb;

	sizb = (*stb)->size;
	i = -1;
	while (++i < sizb && stb && *stb && (*stb)->top)
	{
		nb = *(int *)((*stb)->top->content);
		if (bt == maxbits)
			pa(stb, sta);
		else if (((nb >> bt) & 1) == 1)
			pa(stb, sta);
		else
			rb(stb);
	}
}

static	int	max_num_finding(t_stack *a)
{
	int		n;
	int		max_n;
	t_list	*current;

	if (!a || !a->top)
		return (0);
	current = a->top;
	max_n = *(int *)(current->content);
	while (current)
	{
		n = *(int *)(current->content);
		if (max_n < n)
			max_n = n;
		current = current->next;
	}
	return (max_n);
}

static	int	bits_counting(t_stack *a)
{
	int	max_num;
	int	max_bits;

	if (!a || !a->top)
		return (0);
	max_bits = 0;
	max_num = max_num_finding(a);
	while ((max_num >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix(t_stack **a, t_stack **b)
{
	int	nbits;
	int	n;
	int	bit;
	int	i;
	int	size;

	nbits = bits_counting(*a);
	bit = -1;
	while (++bit < nbits && a && *a && (*a)->top)
	{
		size = (*a)->size;
		i = -1;
		while (++i < size && !sorted_already(*a))
		{
			n = *(int *)((*a)->top->content);
			if (((n >> bit) & 1) == 0)
				pb(a, b);
			else
				ra(a);
		}
		radix_b(a, b, bit + 1, nbits);
	}
	while ((*b) && (*b)->size > 0)
		pa(b, a);
}
