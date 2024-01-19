/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:24:45 by hehuang           #+#    #+#             */
/*   Updated: 2024/01/19 17:31:55 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_stack	*init_checker_stack(int argc, char **argv)
{
	char	**test;
	int		*converted_tab;
	int		len;
	t_stack	*stack_list;

	stack_list = NULL;
	if (argc > 1)
	{
		len = 0;
		test = create_tab(--argc, ++argv, &len);
		converted_tab = convert_tab(test);
		str_tab_free(test);
		if (converted_tab != NULL && check_duplicate(converted_tab, len))
		{
			stack_list = create_list(converted_tab, len);
			free(converted_tab);
		}
	}
	return (stack_list);
}

static int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!n)
		return (0);
	if (ft_strlen(s1) > 4)
		return (1);
	while ((s1[i] || s2[i]) && s1[i] == s2[i] && i < n)
		i++;
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}

static void	reset_str(char **str)
{
	int	i;

	i = -1;
	while ((*str)[++i])
		(*str)[i] = '\0';
}

static int	input_op(t_stack **a, t_stack **b, char *op)
{
	if (!ft_strncmp(op, "ra\n", 4))
		rotate_stack(a, 0);
	else if (!ft_strncmp(op, "rb\n", 4))
		rotate_stack(b, 0);
	else if (!ft_strncmp(op, "rr\n", 4))
		rotate_stacks(a, b, a, 0);
	else if (!ft_strncmp(op, "rra\n", 4))
		rev_rotate_stack(a, 0);
	else if (!ft_strncmp(op, "rrb\n", 4))
		rev_rotate_stack(b, 0);
	else if (!ft_strncmp(op, "rrr\n", 4))
		rev_rotate_stacks(a, b, a, 0);
	else if (!ft_strncmp(op, "sa\n", 4))
		swap_stack(a, 0);
	else if (!ft_strncmp(op, "sb\n", 4))
		swap_stack(b, 0);
	else if (!ft_strncmp(op, "ss\n", 4))
		swap_stacks(a, b, 0);
	else if (!ft_strncmp(op, "pa\n", 4))
		push_stack(b, a, 0);
	else if (!ft_strncmp(op, "pb\n", 4))
		push_stack(a, b, 0);
	else
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	char	*u_input;
	t_stack	*s_list;
	t_stack	*s_b;

	s_list = init_checker_stack(argc, argv);
	s_b = NULL;
	if (!s_list)
		write(1, "Error\n", 6);
	else
	{
		u_input = malloc(4 * sizeof(char));
		while (u_input[0] != '\n')
		{
			reset_str(&u_input);
			read(0, u_input, 10000);
			if (u_input[0] != '\n' && !input_op(&s_list, &s_b, u_input))
				write(1, "Operation non reconnu\n", 23);
		}
		if (ft_is_sorted(&s_list))
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
		t_stack_list_free(&s_list, stack_size(s_list));
	}
	return (0);
}
