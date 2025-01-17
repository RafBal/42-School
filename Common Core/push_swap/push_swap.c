/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 08:04:16 by rbaldin           #+#    #+#             */
/*   Updated: 2025/01/15 07:54:51 by rbaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = input_checking(argc, argv);
	if (!stack_a)
	{
		ft_putendl_fd("Error", 2);
		return (1);
	}
	stack_b = null_stack_initializing();
	if (!stack_b)
	{
		stack_freeing(&stack_a);
		ft_putendl_fd("Error", 2);
		return (1);
	}
	push_swap(&stack_a, &stack_b);
	stack_freeing(&stack_a);
	stack_freeing(&stack_b);
	return (0);
}
