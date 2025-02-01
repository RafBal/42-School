/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 09:05:28 by rbaldin           #+#    #+#             */
/*   Updated: 2025/02/01 16:58:12 by rbaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H 
# define PUSH_SWAP_H

#include "../libft/libft.h"
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct s_stack
{
	t_list	*top;
	int	size;
}	t_stack;
t_stack	*input_checking(int argc, char **argv);
t_stack	*stack_initializing(int *nums, int *size);
t_stack	*null_stack_initializing(void);
void	stack_freeing(t_stack **stack);
void	push_swap(t_stack **a, t_stack **b);
void	sa(t_stack **stacka);
void	sb(t_stack **stackb);
void	ss(t_stack **stacka, t_stack **stackb);
void	pa(t_stack **stackb, t_stack **stacka);
void	pb(t_stack **stacka, t_stack **stackb);
void	ra(t_stack **stacka);
void	rb(t_stack **stackb);
void	rr(t_stack **stacka, t_stack **stackb);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
bool	sorted_already(t_stack *s);
void	radix(t_stack **a, t_stack **b, int off_num);
typedef	struct s_values
{
	long	top;
	bool	tv;
	long	next;
	bool	nv;
	long	next2;
	bool	n2v;
	long	bottom;
	bool	bv;
}	t_values;
void	logical_optimization(t_stack **st_a, t_stack **st_b);
t_values	updating(t_stack **st);
bool	sorted_already_b(t_stack **stack_b);
void	radix_b(t_stack **sta, t_stack **stb, int bt);
#endif
