/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:58:59 by hehuang           #+#    #+#             */
/*   Updated: 2024/01/25 22:39:52 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>

typedef struct nbr_node
{
	int				value;
	struct nbr_node	*next;
	struct nbr_node	*previous;
	int				rank;
	int				*cost_in_a;
}	t_stack;

char		**create_tab(int argc, char **argv, int *size);
char		**ft_split(char const *s);
char		*ft_strdup(const char *s);
int			*convert_tab(char **str_tab);
int			count_words(char const *str);
int			ft_strlen(char const *str);
void		ft_tabcat(char ***dest, char *src, int *index);
int			is_number(char *str);
long long	ft_atol(const char *nptr);
int			check_duplicate(int *tab, int len);
void		add_min_rank(t_stack *stack_list, int rank);
int			stack_size(t_stack *a);
void		addfirst(t_stack **a, t_stack *new_node);
void		delfirst(t_stack **a);
void		cost_to_top(t_stack **s_list, t_stack **elmt, int **cost_a);
void		establish_cost(t_stack **a, t_stack **b);
//algo
t_stack		*find_cheapest(t_stack *b);
void		next_step(t_stack **a, t_stack **b, t_stack **min);
void		ft_rev_sort(t_stack **a, t_stack **b);
void		ft_end(t_stack **a, t_stack **b);
int			ft_is_sorted(t_stack **a);
void		ft_remove_cost(t_stack **s_list);
void		run_push_swap(t_stack **a, t_stack **b);
void		push_swap(int argc, char **argv);
//operation
void		swap_stack(t_stack **a, char name);
void		push_stack(t_stack **from, t_stack **to, char name);
void		rotate_stack(t_stack **a, char name);
void		rev_rotate_stack(t_stack **a, char name);
void		swap_stacks(t_stack **a, t_stack **b, int name);
void		rotate_stacks(t_stack **a, t_stack **b, t_stack **elm, int n);
void		rev_rotate_stacks(t_stack **a, t_stack **b, t_stack **elm, int n);
//Free things
void		str_tab_free(char **str_tab);
void		t_stack_list_free(t_stack **s_list, int len);
//Stacks
t_stack		*stack_new(int content);
t_stack		*create_list(int *tab, int len);
t_stack		*get_max(t_stack **s_list);

#endif
