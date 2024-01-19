/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:05:57 by hehuang           #+#    #+#             */
/*   Updated: 2024/01/19 17:36:58 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cost_to_top(t_stack **s_list, t_stack **elmt, int **cost_tab)
{
	t_stack	*top;
	t_stack	*bottom;
	int		i;

	top = (*elmt)-> next;
	bottom = (*elmt)-> previous;
	i = 0;
	if (cost_tab[0][0] != 0)
		i = 2;
	cost_tab[0][i + 1] = 1;
	while (top->rank != (*s_list)->rank && bottom->rank != (*s_list)->rank)
	{
		cost_tab[0][i + 1]++;
		top = top -> next;
		bottom = bottom -> previous;
	}
	if (top->rank == (*s_list)->rank)
		cost_tab[0][i] = -1;
	else
		cost_tab[0][i] = 1;
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

static t_stack	*get_nearest(t_stack **b, int rank)
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

static void	set_stack(t_stack **s_list, t_stack **elmt)
{
	t_stack	*near;

	near = get_nearest(s_list, (*elmt)->rank);
	if (near-> rank != (*s_list)->rank)
	{
		cost_to_top(s_list, &near, &((*elmt)->cost_in_a));
	}
	else
	{
		(*elmt)->cost_in_a[2] = 0;
		(*elmt)->cost_in_a[3] = 0;
	}
}

void	establish_cost(t_stack **a, t_stack **b)
{
	t_stack	*curr;

	(*a)->cost_in_a[0] = 1;
	(*a)->cost_in_a[1] = 0;
	set_stack(b, a);
	curr = (*a)->next;
	while (curr->rank != (*a)->rank)
	{
		cost_to_top(a, &curr, &(curr->cost_in_a));
		set_stack(b, &curr);
		curr = curr->next;
	}
}
