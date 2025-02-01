/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 12:31:20 by rbaldin           #+#    #+#             */
/*   Updated: 2025/02/01 17:22:15 by rbaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	stack_reverse_rotating(t_stack **a, t_stack **b, int ca, int cb)
{
	bool	flag_rra;
	bool	flag_rrb;
	int	size_a;
	int	size_b;

	flag_rra = false;
	flag_rrb = false;
	size_a = (*a)->size;
	size_b = (*b)->size;
	if (ca > size_a / 2)
		flag_rra = true;
	if (cb > size_b / 2)
		flag_rrb = true;
	if(flag_rra && flag_rrb)
		while ((size_a - ca++ > 0) && (size_b - cb++ > 0))
			rrr(a, b);
	if (ca < size_a && flag_rra)
		while (size_a - ca++ > 0)
			rra(a);
	if (cb < size_b && flag_rrb)
		while (size_b - cb++ > 0)
			rrb(b);
}

static	void	stack_rotating(t_stack **a, t_stack **b, int ca, int cb)
{
	bool	flag_ra;
	bool	flag_rb;

	flag_ra = false;
	flag_rb = false;
	if ((ca <= (*a)->size / 2) && (ca != 0))
		flag_ra = true;
	if ((cb <= (*b)->size / 2) && (cb != 0))
		flag_rb = true;
	if (flag_ra && flag_rb)
		while ((ca-- > 0) && (cb-- > 0))
			rr(a, b);
	if (ca > 0 && flag_ra)
		while (ca-- > 0)
			ra(a);
	if (cb > 0 && flag_rb)
		while (cb-- > 0)
			rb(b);
}

static	int	cost_calculating(t_stack **s, int bt, int bin_dig)
{
	t_list	*copy;
	int	index;
	int	size_s;
	long	n;
	if (!s || !(*s) || !((*s)->top))
		return (0);
	index = 0;
	copy = (*s)->top;
	size_s = (*s)->size;
	while (copy)
	{
		n = *(long *)(copy->content);
		if (((n >> bt) & 1) == bin_dig)
			break;
		index++;
		copy = copy->next;
	}
	if (copy != NULL)
		return (index);
	else
		return (0);
}

static	void	spinning(t_stack **a_st, t_stack **b_st, int bit)
{
	int	cost_a;
	int	cost_b;
	
	cost_a = cost_calculating(a_st, bit, 0);
	cost_b = cost_calculating(b_st, bit, 1);
	stack_rotating(a_st, b_st, cost_a, cost_b);
	stack_reverse_rotating(a_st, b_st, cost_a, cost_b);
}


void	radix_b(t_stack **sta, t_stack **stb, int bt)
{
	int	i;
	int	sizb;
	int	nb;

	sizb = (*stb)->size;
	i = -1;
	while (++i < sizb && !sorted_already_b(stb))
	{
		if ((*stb) && (*stb)->top)
			nb = *(long *)((*stb)->top->content);
		else
			break;
		if (((nb >> bt) & 1) == 1)
			pa(stb, sta);
		else
			spinning(sta, stb, bt);
	}
	//logical_optimization(sta, stb);
}
