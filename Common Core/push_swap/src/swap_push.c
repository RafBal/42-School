/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 14:08:12 by rbaldin           #+#    #+#             */
/*   Updated: 2025/01/26 11:54:43 by rbaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **stacka)
{
	t_stack	*swap;

	if (!stacka || !(*stacka) || !((*stacka)->next))
		return;
	swap = *stacka;
	*stacka = (*stacka)->next;
	swap->next = (*stacka)->next;
	(*stacka)->next = swap;
	ft_putendl_fd("sa", 1);
}

void	sb(t_stack **stackb)
{
	t_stack	*swap;

	if (!stackb || !(*stackb) || !((*stackb)->next))
		return;
	swap = *stackb;
	*stackb = (*stackb)->next;
	swap->next = (*stackb)->next;
	(*stackb)->next = swap;
	ft_putendl_fd("sb", 1);
}

void	ss(t_stack **stacka, t_stack **stackb)
{
	sa(stacka);
	sb(stackb);
	ft_putendl_fd("ss", 1);
}

void	pa(t_stack **stackb, t_stack **stacka)
{
	t_stack	*new;

	if (!stackb || !(*stackb))
		return;
	new = *stackb;
	*stackb = (*stackb)->next;
	new->next = *stacka;
	*stacka = new;
	(*stacka)->size += 1;
	(*stackb)->size -= 1;
	ft_putendl_fd("pa", 1);
}

void	pb(t_stack **stacka, t_stack **stackb)
{
	t_stack *new;

	if (!stacka || !(*stacka))
		return;
	new = *stacka;
	*stacka = (*stacka)->next;
	new->next = *stackb;
	*stackb = new;
	(*stackb)->size += 1;
	(*stacka)->size -= 1;
	ft_putendl_fd("pb", 1);
}
