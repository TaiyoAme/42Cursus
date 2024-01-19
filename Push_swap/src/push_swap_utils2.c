/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:14:44 by hehuang           #+#    #+#             */
/*   Updated: 2024/01/19 15:20:30 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *a)
{
	int	val;
	int	count;

	if (!a)
		return (0);
	count = 1;
	val = a -> value;
	a = a -> next;
	while (a -> value != val)
	{
		a = a -> next;
		count++;
	}
	return (count);
}

void	addfirst(t_stack **a, t_stack *new_node)
{
	if (new_node)
	{
		if (*a)
		{
			new_node -> next = (*a);
			new_node -> previous = (*a)-> previous;
			(*a)-> previous -> next = new_node;
			(*a)-> previous = new_node;
		}
		else
		{
			new_node -> next = new_node;
			new_node -> previous = new_node;
		}
		(*a) = new_node;
	}
}

void	delfirst(t_stack **a)
{
	if (*a && (*a)-> next -> value != (*a)-> value)
	{
		(*a)-> next -> previous = (*a)-> previous;
		(*a)-> previous -> next = (*a)-> next;
		*a = (*a)-> next;
	}
	else if (*a)
		*a = NULL;
}

void	ft_remove_cost(t_stack **s_list)
{
	t_stack	*curr;

	if (*s_list)
	{
		curr = (*s_list);
		while (curr->cost_in_a[0] != 0)
		{
			curr->cost_in_a[0] = 0;
			curr->cost_in_a[1] = 0;
			curr->cost_in_a[2] = 0;
			curr->cost_in_a[3] = 0;
			curr = curr -> next;
		}
	}
}

int	ft_is_sorted(t_stack **a)
{
	t_stack	*curr;
	int		i;
	int		rank;

	curr = (*a)->next;
	i = 0;
	rank = (*a)->rank;
	while (++i < stack_size(*a))
	{
		if (curr->rank <= rank)
			return (0);
		else
			rank = curr->rank;
		curr = curr->next;
	}
	return (1);
}
