/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 15:38:55 by hehuang           #+#    #+#             */
/*   Updated: 2024/01/16 17:56:31 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	str_tab_free(char **str_tab)
{
	int	i;

	i = 0;
	while (str_tab[i])
	{
		free(str_tab[i]);
		i++;
	}
	free(str_tab);
}

void	stack_free(t_stack **node)
{
	free((*node)->cost_in_a);
	free(*node);
}

void	t_stack_list_free(t_stack **s_list, int n)
{
	t_stack	*curr;
	int		i;

	i = 0;
	while (i < n)
	{
		curr = (*s_list)->next;
		stack_free(s_list);
		(*s_list) = curr;
		i++;
	}
}
