/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:11:01 by hehuang           #+#    #+#             */
/*   Updated: 2023/10/25 18:19:27 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*current;

	res = NULL;
	current = NULL;
	if (lst)
	{
		current = ft_lstnew(f(lst -> content));
		res = current;
		while (lst -> next)
		{
			lst = lst -> next;
			current = ft_lstnew(f(lst -> content));
			if (current)
				ft_lstadd_back(&res, current);
			else
			{
				ft_lstclear(&res, del);
				return (NULL);
			}
		}
	}
	return (res);
}
