/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logical_optimization.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 11:09:06 by rbaldin           #+#    #+#             */
/*   Updated: 2025/01/31 11:16:33 by rbaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	r_r_comparing(t_values va, t_values vb, t_stack **a, t_stack **b)
{
	bool	rra_flag;
	bool	rrb_flag;

	rra_flag = false;
	rrb_flag = false;

	if (va.tv && va.bv)
	{
		if (va.bottom < va.top)
			rra_flag = true;
	}
	if (vb.tv && vb.bv)
	{
		if (vb.bottom > vb.top)
			rrb_flag = true;
	}
	if (rra_flag && rrb_flag)
		rrr(a, b);
	else
	{
		if (rra_flag)
			rra(a);
		else if (rrb_flag)
			rrb(b);
	}
}

static	void	r_comparing(t_values va, t_values vb, t_stack **a, t_stack **b)
{
	bool	ra_flag;
	bool	rb_flag;

	ra_flag = false;
	rb_flag = false;
	if (va.tv && va.nv && va.n2v && va.bv)
	{
		if (va.top > va.next && va.top > va.next2 && va.top > va.bottom)
			ra_flag = true;
	}
	if (vb.tv && vb.nv && vb.n2v && vb.bv)
	{
		if (vb.top < vb.next && vb.top < vb.next2 && vb.top < vb.bottom)
			rb_flag = true;
	}
	if (ra_flag && rb_flag)
		rr(a, b);
	else
	{
		if (ra_flag)
			ra(a);
		else if (rb_flag)
			rb(b);
	}
}

static	void	s_comparing(t_values va, t_values vb, t_stack **a, t_stack **b)
{
	bool	sa_flag;
	bool	sb_flag;

	sa_flag = false;
	sb_flag = false;
	if (va.tv && va.nv && va.n2v)
	{
		if (va.top > va.next && va.top < va.next2)
			sa_flag = true;
	}
	if (vb.tv && vb.nv && vb.n2v)
	{
		if (vb.top < vb.next && vb.top > vb.next2)
			sb_flag = true;
	}
	if (sa_flag && sb_flag)
		ss(a, b);
	else
	{
		if (sa_flag)
			sa(a);
		else if (sb_flag)
			sb(b);
	}
}

void	logical_optimization(t_stack **st_a, t_stack **st_b)      
{                              
	t_values        value_a;
	t_values	value_b;
	
	if (!st_a || !(*st_a) || !st_b ||!(*st_b))
		return;
	value_a = updating(st_a);
	value_b = updating(st_b);
	s_comparing(value_a, value_b, st_a, st_b);
	value_a = updating(st_a);
	value_b = updating(st_b);
	r_comparing(value_a, value_b, st_a, st_b);
	value_a = updating(st_a);
	value_b = updating(st_b);
	r_r_comparing(value_a, value_b, st_a, st_b);
}
