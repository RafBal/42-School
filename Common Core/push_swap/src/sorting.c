/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:21:57 by rbaldin           #+#    #+#             */
/*   Updated: 2025/01/15 11:29:11 by rbaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack **a, t_stack **b)
{
	if (sorted_already(*a))
		return;
	else if ((*a)->size == 2)
	{
		sa(a);
		return;
	}
	else if ((*a)->size == 3)
	{
		three_sort(*a);

}

