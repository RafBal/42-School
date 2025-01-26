/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mechanical_turk.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 11:33:42 by rbaldin           #+#    #+#             */
/*   Updated: 2025/01/21 14:58:22 by rbaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int n)
{
	if (n < 0)
		n = -n;
	return (n);
}

static	int	cheapest_to_b(int na, int t_stack **st_b)
{
	t_stack	**b_sec;
	int	cost;
	int	min_cost;
	int	nb;
	int	rest;

	b_sec = b;
	min_cost = INT_MAX;
	rest = 0;
	while ((*st_b) != NULL)
	{
		nb = (int) *(long *)b->content;
		rest = ft_abs(na - nb);
		if (rest < min_cost)
			min_cost = rest;
		(*st_b) = (*st_b)->next;
	}
	b = b_sec;
	return (min_cost);
}




void	mechanical_turk(t_stack **a, t_stack **b, int ins_ind_b, t_cost cost)
{
	int	min_cost;
	int	best_index;
	int	i;
	t_cost	best_cost;
	int	numa;
	int	numb;

	min_cost = INT_MAX;
	best_index = -1;
	pb(a, b);
	pb(a, b);

	while ((*a)->size > 3)
	{
		while (i < (*a)->size)
		{
			numa = (int) *(long *)a->content;
			numb = (int) *(long *)b->content;
			min_cost = cheapest_to_b(numa, b);
			if (((int) *(long *)a->content > (int) *(long *)b->content) &&
					(numa - numb == cheapest_to_b(numa, b)))
				pb(a, b);

			cost_ = total_cost_calculation(*a, *b, i, ins_ind_b);
			if (cost.total_cost < min_cost)
			{
				min_cost = cost.total_cost;
				best_index = i;
				best_cost = cost;
			}
			i++;
		}
		moves_execution(a, b, best_index, best_cost);
		pb(a, b);
	}
	while ((*b)->size > 0)
		pa(a, b);
}

// sexta-feira: norminette
// sábado: testes
// domingo: entrega
