/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:26:34 by rbaldin           #+#    #+#             */
/*   Updated: 2025/02/03 11:06:22 by rbaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
static	void	cost_calculation(t_stack **st_a, int bt)
{
	t_list	*copy_a;
	int	index;
	int	size_a;
	int	n;

	if (!st_a || !(*st_a) || !((*st_a)->top))
		return;
	index = 0;
	copy_a = (*st_a)->top;
	size_a = (*st_a)->size;
	while (copy_a)
	{
		n = *(int *)(copy_a->content);
		if (((n >> bt) & 1) == 0)
			break;
		index++;
		copy_a = copy_a->next;
	}
	if ((index <= size_a / 2) && (((n >> bt) & 1) == 0))
	{
		if (index > 0)
			ra(st_a);
	}
	else if ((index > size_a / 2) && (((n >> bt) & 1) == 0))
		rra(st_a);
		
	//	while (size_a - index > 0)
	//	{
	//		rra(st_a);
	//		index++;
	//	}
		
}
*/
static	int	max_num_finding(t_stack *a)
{
	int	n;
	int	max_n;
	t_list	*current;

	if (!a || !a->top)
		return (0);
	current = a->top;
	max_n = *(int *)(current->content);
	while (current)
	{
		n = *(int *)(current->content);
		if (max_n < n)
			max_n = n;
		current = current->next;
	}
	return (max_n);
}

static	size_t	bits_counting(t_stack *a)
{
	int	max_num;
	size_t	max_bits;

	if (!a || !a->top)
		return (0);
	max_bits = 0;
	max_num = max_num_finding(a);
	while ((max_num >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}
/*
static	void	minus_adjustment(t_stack *a, int off_num)
{
	int	n;
	t_list	*temp;

	temp = a->top;
	while (temp)
	{
		n = *(int *)(temp->content);
		n = n - off_num;
		*(int *)(temp->content) = n;
		temp = temp->next;
	}
}
*/
void	radix(t_stack **a, t_stack **b)//, int off_num)
{
	int	nbits;
	int	n;
	int	i;
	int	bit;
	int	size;

//	if (off_num < 0)
//		minus_adjustment(*a, off_num);
	nbits = bits_counting(*a); // verificar depois
	i = 0;
	bit = -1;
	while (++bit < nbits)
	{
		size = (*a)->size;
		i = -1;
		while (++i < size && !sorted_already(*a))
		{
			if ((*a) && (*a)->top)
				n = *(int *)((*a)->top->content);
			else
				break;
			if (((n >> bit) & 1) == 0)
				pb(a, b);
			else
				ra(a); //cost_calculation(a, bit);
		}
		radix_b(a, b, bit + 1);
//		if (!sorted_already(*a) || !sorted_already_b(b))
//			logical_optimization(a, b);
	
	while ((*b) && (*b)->size > 0)
		pa(b, a);
	}	
//	if (off_num < 0)
//		minus_adjustment(*a, -off_num);
}
