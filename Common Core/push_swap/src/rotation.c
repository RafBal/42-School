/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:52:20 by rbaldin           #+#    #+#             */
/*   Updated: 2025/01/25 12:50:46 by rbaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotation(t_stack **s, const char *op)
{
	t_stack	*reserve;
	t_stack	*temp;

	if (!s || !(*s) || !((*s)->next))
		return;
	reserve = *s;
	*s = (*s)->next;
	reserve->next = NULL;
	temp = *s;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = reserve;
	ft_putendl_fd(op, 1);
}

void	ra(t_stack **stacka)
{
	rotation(stacka, "ra");
}

void	rb(t_stack **stackb)
{
	rotation(stackb, "rb");
}

void	rr(t_stack **stacka, t_stack **stackb)
{
	rotation(stacka, NULL);
	rotation(stackb, NULL);
	ft_putendl_fd("rr", 1);
}
