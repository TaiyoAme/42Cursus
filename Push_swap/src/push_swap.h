/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:58:59 by hehuang           #+#    #+#             */
/*   Updated: 2023/12/22 20:02:46 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stddef.h>

typedef struct nbr_node
{
	int				value;
	struct nbr_node	*next;
	struct nbr_node	*previous;
	int				rank;
	char			name;
}	t_stack;

char	**create_tab(int argc, char **argv, int *size);
char	**ft_split(char const *s);
char	*ft_strdup(const char *s);
int		*convert_tab(char **str_tab);
int		count_words(char const *str);
int		ft_strlen(char const *str);
int		ft_tabcat(char **dest, char *src);
int		is_number(char *str);
int		ft_atoi(const char *nptr);
int		check_duplicate(int *tab, int len);
void	add_min_rank(t_stack *stack_list, int rank);
int		stack_size(t_stack *a);
void	addfirst(t_stack **a, t_stack *new_node);
void	delfirst(t_stack **a);
//algo
void	phase_une(int tier, t_stack **from, t_stack **to);
void	before_push(t_stack **a, t_stack **b);
//operation
void	swap_stack(t_stack **a, char name);
void	push_stack(t_stack **from, t_stack **to, char name);
void	rotate_stack(t_stack **a, char name);
void	rev_rotate_stack(t_stack **a, char name);
void	rotate_stacks(t_stack **a, t_stack **b);
void	rev_rotate_stacks(t_stack **a, t_stack **b);
//Error handling
void	showInputError(void);

t_stack	*stack_new(int content);
t_stack	*create_list(int *tab, int len);

#endif
