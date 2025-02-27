/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:15:25 by rbaldin           #+#    #+#             */
/*   Updated: 2024/11/09 15:25:44 by rbaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	void	*mal;
	t_list	*replicated_node;
	t_list	*nl;

	if (!lst || !f)
		return (NULL);
	nl = NULL;
	while (lst != NULL)
	{
		mal = f(lst->content);
		replicated_node = ft_lstnew(mal);
		if (!replicated_node)
		{
			ft_lstclear(&nl, del);
			return (NULL);
		}
		ft_lstadd_back(&nl, replicated_node);
		lst = lst->next;
	}
	return (nl);
}
