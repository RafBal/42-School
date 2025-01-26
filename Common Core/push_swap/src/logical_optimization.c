/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logical_optimization.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 11:09:06 by rbaldin           #+#    #+#             */
/*   Updated: 2025/01/26 09:37:11 by rbaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotation_comparing(t_values v, t_stack **a, t_stack **b)
{
	bool	rra_flag;
	bool	rrb_flag;

	rra_flag = false;
	rrb_flag = false;

	if (v.la < v.ta)
		rra_flag = true;
	if (v.lb > v.tb)
		rrb_flag = false;
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

void	rotation_comparing(t_values v, t_stack **a, t_stack **b)
{
	bool	ra_flag;
	bool	rb_flag;

	ra_flag = false;
	rb_flag = false;
	if (v.ta > v.tna && v.ta > v.t2na && v.ta > v.la)
		ra_flag = true;
	if (v.tb < v.tnb && v.tb < v.t2nb && v.tb < v.lb)
		rb_flag = true;
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

void	swap_comparing(t_values v, t_stack **a, t_stack **b)
{
	bool	sa_flag;
	bool	sb_flag;

	sa_flag = false;
	sb_flag = false;
	if (v.ta > v.tna && v.ta < v.t2na)
		sa_flag = true;
	if (v.tb < v.tnb && v.tb > v.t2nb)
		sb_flag = true;
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

t_values	values_updating(t_stack **sta, t_stack **stb)
{
	t_values	uv;
	t_list	*last_a;
	t_list	*last_b;

	if ((*st_a)->top)
		uv.ta = *(long *)((*st_a)->top->content);
	if ((*st_a)->top->next)
		uv.tna = *(long *)((*st_a)->top->next->content);
	if ((*st_a)->top->next->next)
		uv.t2na = *(long *)((*st_a)->top->next->next->content);
	last_a = ft_lstlast((*st_a)->top);
	if (last_a)
		uv.la = *(long *)(last_a->content);
	if ((*st_b)->top)
		uv.tb = *(long *)((*st_a)->top->content);
	if ((*st_b)->top->next)
		uv.tnb = *(long *)((*st_b)->top->next->content);
	if ((*st_b)->top->next->next)
		uv.t2nb = *(long *)((*st_b)->top->next->next->content);
	last_b = ft_lstlast((*st_b)->top);
	if (last_b)
		uv.lb = *(long *)(last_b->content);
	return (uv);
}

void	logical_optimization(t_stack **st_a, t_stack **st_b)      
{                              
	t_values        value;
	
	value = values_updating(st_a, st_b);
	swap_comparing(value, st_a, st_b);
	value = values_updating(st_a, st_b);
	rotation_comparing(value, st_a, st_b);
	value = values_updating(st_a, st_b);
	reverse_rotation_comparing(value, st_a, st_b);
}	
