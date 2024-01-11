/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.algo3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:05:57 by hehuang           #+#    #+#             */
/*   Updated: 2024/01/11 17:10:33 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

int	*cost_to_top(t_stack **s_list, t_stack **elmt)
{
	t_stack	*top;
	t_stack	*bottom;
	int		*moves;

	top = (*elmt)-> next;
	bottom = (*elmt)-> previous;
	moves = malloc(2 * sizeof(int));
	moves[1] = 1;
	while (top->rank != (*s_list)->rank && bottom->rank != (*s_list)->rank)
	{
		moves[1]++;
		top = top -> next;
		bottom = bottom -> previous;
	}
	if (top->rank == (*s_list)->rank)
		moves[0] = -1;
	else
		moves[0] = 1;
	return (moves);
}

t_stack	*get_max(t_stack **s_list)
{
	t_stack	*res;
	t_stack	*curr;

	res = *s_list;
	curr = (*s_list)->next;
	while (curr->rank != (*s_list)->rank)
	{
		if (curr->rank > res->rank)
			res = curr;
		curr = curr->next;
	}
	return (res);
}

t_stack	*get_nearest(t_stack **b, int rank)
{
	t_stack	*near;
	t_stack	*curr;

	near = (*b);
	curr = (*b)-> next;
	while (curr->rank != (*b)->rank)
	{
		if ((rank > curr->rank)
			&& ((rank - near->rank) > (rank - curr->rank)
				|| rank - near->rank < 0))
			near = curr;
		curr = curr -> next;
	}
	if (near->rank > rank)
	{
		near = (get_max(b));
	}
	return (near);
}

void	set_stack(t_stack **s_list, t_stack **elmt)
{
	int		*moves;
	t_stack	*near;

	near = get_nearest(s_list, (*elmt)->rank);
	if (near-> rank != (*s_list)->rank)
	{
		moves = cost_to_top(s_list, &near);
		(*elmt)->cost_in_b[0] = moves[0];
		(*elmt)->cost_in_b[1] = moves[1];
	}
	else
	{
		(*elmt)->cost_in_b[0] = 0;
		(*elmt)->cost_in_b[1] = 0;
	}
}

void	etablish_cost(t_stack **a, t_stack **b)
{
	t_stack	*curr;

	(*a)->cost_in_a[0] = 1;
	(*a)->cost_in_a[1] = 0;
	set_stack(b, a);
	curr = (*a)->next;
	while (curr->rank != (*a)->rank)
	{
		curr -> cost_in_a = cost_to_top(a, &curr);
		set_stack(b, &curr);
		curr = curr->next;
	}
}
