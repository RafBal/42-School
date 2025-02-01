/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 14:08:12 by rbaldin           #+#    #+#             */
/*   Updated: 2025/01/28 12:37:25 by rbaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	swap(t_stack **stack, char *op)
{
	t_list	*swap;

	if (!stack || !(*stack) || !(*stack)->top || !((*stack)->top->next))
		return;
	swap = (*stack)->top;
	(*stack)->top = (*stack)->top->next;
	swap->next = (*stack)->top->next;
	(*stack)->top->next = swap;
	if (op)
		ft_putendl_fd(op, 1);
}

void	sa(t_stack **stacka)
{
	swap(stacka, "sa");
}

void	sb(t_stack **stackb)
{
	swap(stackb, "sb");
}

void	ss(t_stack **stacka, t_stack **stackb)
{
	swap(stacka, NULL);
	swap(stackb, NULL);
	ft_putendl_fd("ss", 1);
}
