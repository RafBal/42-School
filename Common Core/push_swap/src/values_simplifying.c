/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   values_simplifying.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 12:14:03 by rbaldin           #+#    #+#             */
/*   Updated: 2025/02/06 11:22:07 by rbaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	replacing(int *ar, int size, t_list *n)
{
	int	i;

	while (n)
	{
		i = -1;
		while (++i < size)
		{
			if (*(int *)n->content == ar[i])
			{
				*(int *)n->content = i;
				break ;
			}
		}
		n = n->next;
	}
	free(ar);
}

static	int	*bubble_sorting(int *array, int length)
{
	int	i;
	int	j;
	int	t;

	i = -1;
	while (++i < length - 1)
	{
		j = i;
		while (++j < length)
		{
			if (array[i] > array[j])
			{
				t = array[i];
				array[i] = array[j];
				array[j] = t;
			}
		}
	}
	return (array);
}

void	values_simplifying(t_stack *a)
{
	int		size;
	int		*sorted_arr;
	t_list	*node;
	int		i;

	size = a->size;
	sorted_arr = malloc(sizeof(int) * size);
	if (!sorted_arr)
		return ;
	node = a->top;
	i = -1;
	while (++i < size)
	{
		sorted_arr[i] = *(int *)node->content;
		node = node->next;
	}
	sorted_arr = bubble_sorting(sorted_arr, size);
	replacing(sorted_arr, size, a->top);
}
