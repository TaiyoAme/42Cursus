/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 19:18:21 by hehuang           #+#    #+#             */
/*   Updated: 2024/01/11 16:14:05 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
/*
void	set_cost_to_0(t_stack **b)
{
	t_stack	*current;

	current = *b;
	while (current->cost_in_b[0] != 0)
	{
		current->cost_to_a[0] = 0;
		current->cost_to_a[1] = 0;
		current->cost_in_b[0] = 0;
		current->cost_in_b[1] = 0;
		current = current->next;
	}
}

void	cost_to_top(t_stack **s_list, t_stack **elmt)
{
	t_stack	*top;
	t_stack	*bottom;
	int		moves;

	top = (*elmt)-> next;
	bottom = (*elmt)-> previous;
	moves = 1;
	while (top->rank != (*s_list)->rank && bottom->rank != (*s_list)->rank)
	{
		moves++;
		top = top -> next;
		bottom = bottom -> previous;
	}
	if (top->rank == (*s_list)->rank)
		(*elmt)->cost_in_b[0] = -1;
	else
		(*elmt)->cost_in_b[0] = 1;
	(*elmt)->cost_in_b[1] = moves;
}

int	correct_pos(t_stack *s_list, t_stack *elmt, int max)
{
	if (elmt->rank < s_list->rank && (s_list->previous->rank == max
			|| elmt->rank > s_list->previous->rank))
		return (1);
	return (0);
}

int	test(t_stack **a, int rank)
{
	int		bot;
	int		top;
	t_stack	*curr;

	top = 0;
	bot = 0;
	curr = *a;
	while (!(rank < (curr)->rank
			&& (rank > (curr)->previous->rank
				|| (curr)->previous->rank == get_max_rank(a))))
	{
		curr = curr ->next;
		top ++;
	}
	curr = *a;
	while (!(rank < (curr)->rank
			&& (rank > (curr)->previous->rank
				|| (curr)->previous->rank == get_max_rank(a))))
	{
		curr = curr ->previous;
		bot ++;
	}
	if (top > bot)
		return (-bot);
	return (top);
}
void	set_stack(t_stack **s_list, t_stack **elmt)
{
	t_stack	*top;
	t_stack	*bottom;
	int		moves;
	int		max;

	top = (*s_list)-> next;
	bottom = (*s_list)-> previous;
	moves = 0;
	max = get_max_rank(s_list);
	if (!correct_pos(*s_list, *elmt, max))
	{
		moves = test(s_list, (*elmt)->rank);
	}
	if (moves < 0)
		(*elmt)->cost_to_a[0] = -1;
	else
		(*elmt)->cost_to_a[0] = 1;
	(*elmt)->cost_to_a[1] = ft_abs(moves);
}
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

void	test_algo(t_stack **a, t_stack **b)
{
	t_stack	*min;

	while (stack_size(*a) != 3)
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


void	sort_a(t_stack **a)
{
	if (!ft_is_sorted(a) && stack_size(*a)== 3)
	{
		if ((*a)->rank < (*a)->next->rank && (*a)->rank < (*a)->previous->rank)
			rev_rotate_stack(a, 'a');
		if ((*a)->rank > (*a)->next->rank && (*a)->rank > (*a)->previous->rank
			&& (*a)->rank > (*a)->next->rank && (*a)->next->rank < (*a)->previous->rank)
			rotate_stack(a, 'a');
		if ((*a)->rank > (*a)->next->rank)
			swap_stack(a, 'a');
		if ((*a)->rank > (*a)->previous->rank)
			rev_rotate_stack(a, 'a');
		if ((*a)->next->rank > (*a)->previous->rank)
			rev_rotate_stack(a, 'a')
	}
}
*/
