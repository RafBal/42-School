/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:52:20 by rbaldin           #+#    #+#             */
/*   Updated: 2025/02/04 10:01:49 by rbaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	rotation(t_stack **s, char *op)
{
	t_list	*reserve;
	t_list	*temp;

	if (!s || !(*s) || !(*s)->top || !(*s)->top->next)
		return ;
	reserve = (*s)->top;
	(*s)->top = (*s)->top->next;
	reserve->next = NULL;
	temp = (*s)->top;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = reserve;
	if (op)
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
