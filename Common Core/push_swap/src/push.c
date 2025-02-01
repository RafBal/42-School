/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 14:08:12 by rbaldin           #+#    #+#             */
/*   Updated: 2025/01/31 13:27:49 by rbaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	pa(t_stack **stackb, t_stack **stacka)
{
	t_list	*new;

	if (!stackb || !(*stackb) || !(*stackb)->top)
		return;
	new = (*stackb)->top;
	if (!new || !(new->content))
		return;
	(*stackb)->top = (*stackb)->top->next;
	new->next = (*stacka)->top;
	(*stacka)->top = new;
	(*stacka)->size += 1;
	(*stackb)->size -= 1;
	//printf("PA: Moving %d from stack B to A\n", *((int *)(*stacka)->top->content));
	ft_putendl_fd("pa", 1);
}

void	pb(t_stack **stacka, t_stack **stackb)
{
	t_list *new;

	if (!stacka || !(*stacka) || !(*stacka)->top)
		return;
	new = (*stacka)->top;
	if (!new || !(new->content))
		return;
	(*stacka)->top = (*stacka)->top->next;
	new->next = (*stackb)->top;
	(*stackb)->top = new;
	(*stackb)->size += 1;
	(*stacka)->size -= 1;
	//printf("PB: Moving %d from stack A to B\n", *((int *)(*stackb)->top->content));
	ft_putendl_fd("pb", 1);
}
