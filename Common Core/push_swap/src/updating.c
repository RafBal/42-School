/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updating.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 08:24:54 by rbaldin           #+#    #+#             */
/*   Updated: 2025/01/31 11:11:04 by rbaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static  t_values        updating2(t_stack **st, t_values uv);

t_values	updating(t_stack **st)
{
	t_values	uv;
 
	uv.tv = false;
	uv.nv = false;
	uv.n2v = false;
	uv.bv = false;
	if (!st || !(*st) || !((*st)->top))
		return (uv);
	uv.top = *(long *)((*st)->top->content);
 	uv.tv = true;
 	if ((*st)->top->next)
	{
 		uv.next = *(long *)((*st)->top->next->content);
 		uv.nv = true;
 	}
	return (updating2(st, uv));
}

static	t_values	updating2(t_stack **st, t_values uv)
{
	t_list	*last;

	if (!st || !(*st) || !((*st)->top))
		return (uv);
	if ((*st)->top && (*st)->top->next && (*st)->top->next->next)
	{
		uv.next2 = *(long *)((*st)->top->next->next->content);
		uv.n2v = true;
	}
	last = ft_lstlast((*st)->top);
	if (last)
	{
		uv.bottom = *(long *)(last->content);
		uv.bv = true;
	}
	return (uv);
}
