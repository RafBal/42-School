/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:12:04 by rbaldin           #+#    #+#             */
/*   Updated: 2025/01/25 12:58:25 by rbaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotation(t_stack **s, const char *op)
{
	t_stack	*l_sec;
	t_stack *l;
	if (!s || !(*s) || !(*s)->next)
		return;
	l_sec = NULL;
	l = *s;
	while (l->next)
	{
		l_sec = l;
		l = l->next;
	}
	l_sec->next = NULL;
	l->next = *s;
	*s = l;
	ft_putendl_fd(op, 1);
}

void	rra(t_stack **a)
{
	reverse_rotation(a, "rra");
}

void	rrb(t_stack **b)
{
	reverse_rotation(b, "rrb");
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotation(a, NULL);
	reverse_rotation(b, NULL);
	ft_putendl_fd("rrr", 1);
}	
