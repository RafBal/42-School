/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 09:13:33 by rbaldin           #+#    #+#             */
/*   Updated: 2025/01/15 11:29:17 by rbaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted_already(t_stack *s)
{
	t_list	*current;

	current = s->top;
	while (current && current->next)
	{
		if ((int)(long)current->content > (int)(long)current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}

int	three_sort(t_stack *a)
{

