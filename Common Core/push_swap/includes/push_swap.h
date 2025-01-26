/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 09:05:28 by rbaldin           #+#    #+#             */
/*   Updated: 2025/01/26 10:08:51 by rbaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <limits.h>
#include <stdbool.h>

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	t_list	*top;
	int	size;
}	t_stack;

typedef	struct s_values
{
	long	ta;
	long	tna;
	long	t2na;
	long	la;
	long	tb;
	long	tnb;
	long	t2nb;
	long	lb;
}	t_values;
#endif
// ta = top value from stack a
// tna = top next value from stack a
// t2na = top next next value from stack a
// la = last value from stack a
// tb = top value from stack b
// tna = top next value from stack b
// t2na = top next next value from stack b
// lb = last value from stack b
