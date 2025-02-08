/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_freeing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:51:30 by rbaldin           #+#    #+#             */
/*   Updated: 2025/02/04 10:53:55 by rbaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_freeing(t_stack **stack)
{
	if (!stack || !(*stack))
		return ;
	if ((*stack)->top)
		ft_lstclear(&((*stack)->top), free);
	free(*stack);
	*stack = NULL;
}
