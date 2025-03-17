/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:50:50 by kbolon            #+#    #+#             */
/*   Updated: 2023/05/25 16:02:32 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap_helper(t_list *first, void (*del)(void *))
{
	t_list	*new;

	while (first)
	{
		new = first->next;
		(*del)(first->content);
		free(first);
		first = new;
	}
	return (0);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void *))
{
	t_list	*first;
	t_list	*new;
	void	*t;

	if (!f || !del)
		return (0);
	first = 0;
	while (lst)
	{
		t = (*f)(lst->content);
		new = ft_lstnew(t);
		if (!new)
		{
			ft_lstmap_helper(first, del);
			free (t);
			lst = 0;
			return (0);
		}
		ft_lstadd_back(&first, new);
		lst = lst->next;
	}
	return (first);
}
