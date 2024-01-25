/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:14:53 by hehuang           #+#    #+#             */
/*   Updated: 2024/01/25 23:07:35 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_end(t_stack **a, t_stack **b)
{
	t_stack	*max;

	max = get_max(b);
	cost_to_top(b, &max, &max->cost_in_a);
	while ((*b)-> rank != max->rank)
	{
		if (max->cost_in_a[2] == -1)
			rev_rotate_stack(b, 'b');
		else
			rotate_stack(b, 'b');
	}
	while (*b)
	{
		push_stack(b, a, 'a');
	}
}

void	tree_input(t_stack **s_list)
{
	t_stack	*a;

	a = *s_list;
	if (a->value > a->next->value && a->previous->value > a->value)
		swap_stack(s_list, 'a');
	else if (a->value > a->next->value && a->next->value > a->previous->value)
	{
		swap_stack(s_list, 'a');
		rev_rotate_stack(s_list, 'a');
	}
	else if (a->value < a->next->value && a->next->value > a->previous->value
		&& a->value < a->previous->value)
	{
		swap_stack(s_list, 'a');
		rotate_stack(s_list, 'a');
	}
	else if (a->value > a->next->value && a->next->value < a->previous->value)
		rotate_stack(s_list, 'a');
	else
		rev_rotate_stack(s_list, 'a');
}

void	five_input(t_stack **a, t_stack **b)
{
	t_stack	*lowest;

	lowest = find_cheapest(*a);
	next_step(a, NULL, &lowest);
	push_stack(a, b, 'b');
	lowest = find_cheapest(*a);
	next_step(a, NULL, &lowest);
	push_stack(a, b, 'b');
	tree_input(a);
	push_stack(b, a, 'a');
	push_stack(b, a, 'a');
}

void	run_push_swap(t_stack **a, t_stack **b)
{
	int	a_size;

	a_size = stack_size(*a);
	if (a_size == 2)
		swap_stack(a, 'a');
	else if (a_size == 3)
		tree_input(a);
	else if (a_size == 5)
	{
		five_input(a, b);
	}
	else
	{
		push_stack(a, b, 'b');
		push_stack(a, b, 'b');
		ft_rev_sort(a, b);
		ft_end(a, b);
	}
}

void	push_swap(int argc, char **argv)
{
	char	**test;
	int		*converted_tab;
	int		len;
	t_stack	*stack_list;
	t_stack	*stack_b;

	if (argc > 1)
	{
		len = 0;
		test = create_tab(--argc, ++argv, &len);
		converted_tab = convert_tab(test);
		str_tab_free(test);
		stack_b = NULL;
		if (converted_tab != NULL && check_duplicate(converted_tab, len))
		{
			stack_list = create_list(converted_tab, len);
			free(converted_tab);
			if (!ft_is_sorted(&stack_list))
				run_push_swap(&stack_list, &stack_b);
			t_stack_list_free(&stack_list, len);
		}
		else
			write(1, "Error\n", 6);
	}
}
