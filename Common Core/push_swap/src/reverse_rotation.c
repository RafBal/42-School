/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:12:04 by rbaldin           #+#    #+#             */
/*   Updated: 2025/02/04 10:03:09 by rbaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	reverse_rotation(t_stack **s, char *op)
{
	t_list	*l_sec;
	t_list	*l;

	if (!s || !(*s) || !(*s)->top || !(*s)->top->next)
		return ;
	l_sec = NULL;
	l = (*s)->top;
	while (l->next)
	{
		l_sec = l;
		l = l->next;
	}
	l_sec->next = NULL;
	l->next = (*s)->top;
	(*s)->top = l;
	if (op)
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
