/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:03:51 by hehuang           #+#    #+#             */
/*   Updated: 2024/01/11 17:13:54 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

void	ft_end(t_stack **a, t_stack **b)
{
	t_stack	*max;
	int		*ctt;

	max = get_max(b);
	ctt = cost_to_top(b, &max);
	while ((*b)-> rank != max->rank)
	{
		if (ctt[0] == -1)
			rev_rotate_stack(b, 'b');
		else
			rotate_stack(b, 'b');
	}
	while (*b)
	{
		push_stack(b, a, 'a');
	}
}

void	run_push_swap(t_stack **a, t_stack **b)
{
	push_stack(a, b, 'b');
	push_stack(a, b, 'b');
	if ((*b)->rank < (*b)->next->rank)
		swap_stack(b, 'b');
	etablish_cost(a, b);
	ft_rev_sort(a, b);
	ft_end(a, b);
}

int	main(int argc, char **argv)
{
	char	**test;
	int		*converted_tab;
	int		len;
	t_stack	*stack_list;
	t_stack	*stack_b;

	len = 0;
	test = create_tab(--argc, ++argv, &len);
	converted_tab = convert_tab(test);
	stack_b = NULL;
	if (converted_tab != NULL && check_duplicate(converted_tab, len))
	{
		stack_list = create_list(converted_tab, len);
		run_push_swap(&stack_list, &stack_b);
	}
	else
	{
		printf("Nope \n");
	}
	return (0);
}
