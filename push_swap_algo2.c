/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:52:26 by hehuang           #+#    #+#             */
/*   Updated: 2024/01/11 17:13:21 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	find_cost(t_stack *elm)
{
	if (elm->cost_in_b[0] < 0 == elm->cost_in_a[0] < 0)
	{
		if (elm -> cost_in_a[1] > elm->cost_in_b[1])
			return (elm->cost_in_a[1]);
		return (elm->cost_in_b[1]);
	}
	return (elm->cost_in_a[1] + elm->cost_in_b[1]);
}

t_stack	*find_cheapest(t_stack *b)
{
	t_stack	*res;
	t_stack	*current;

	res = b;
	current = res->next;
	while (current->rank != b->rank)
	{
		if (find_cost(res) > find_cost(current))
			res = current;
		current = current -> next;
	}
	return (res);
}

void	next_step(t_stack **a, t_stack **b, t_stack **min)
{
	while ((*min)->cost_in_b[0] < 0 == (*min)->cost_in_a[0] < 0
		&& (*min)->cost_in_b[1] != 0 && (*min)->cost_in_a[1] != 0)
	{
		if ((*min)->cost_in_a[0] == 1)
			rotate_stacks(b, a, min);
		if ((*min)->cost_in_a[0] == -1)
			rev_rotate_stacks(b, a, min);
	}
	while ((*min)->cost_in_a[1] != 0)
	{
		if ((*min)->cost_in_a[0] == 1)
			rotate_stack(a, 'a');
		else
			rev_rotate_stack(a, 'a');
		(*min)->cost_in_a[1]--;
	}
	while ((*min)->cost_in_b[1] != 0)
	{
		if ((*min)->cost_in_b[0] == 1)
			rotate_stack(b, 'b');
		else
			rev_rotate_stack(b, 'b');
		(*min)->cost_in_b[1]--;
	}
}

void	ft_rev_sort(t_stack **a, t_stack **b)
{
	t_stack	*min;

	while (stack_size(*a) != 0)
	{
		etablish_cost(a, b);
		min = find_cheapest(*a);
		next_step(a, b, &min);
		push_stack(a, b, 'b');
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
