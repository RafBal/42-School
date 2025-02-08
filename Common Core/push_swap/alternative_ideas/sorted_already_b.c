/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_already_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:39:45 by rbaldin           #+#    #+#             */
/*   Updated: 2025/02/01 17:08:24 by rbaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	sorted_already_b(t_stack **stack_b)
{
	t_list	*now;

	if (!stack_b || !(*stack_b)->top || !(*stack_b)->top->next)
		return (true);
	now = (*stack_b)->top;
	while (now && now->next)
	{
		if (*(int *)now->content < *(int *)now->next->content)
			return (false);
		now = now->next;
	}
	return (true);
}
