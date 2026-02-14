/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 17:28:41 by msedeno-          #+#    #+#             */
/*   Updated: 2026/02/14 20:45:37 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/inc/libft.h"

typedef struct s_stack
{
	int				num;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	int				index;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

// arguments.c
char	*ft_strjoin_space(char const *s1, char const *s2);
int		ft_atoi_strict(const char *str, long *num);
char	*create_big_av(int ac, char **av);
char	**join_arguments(int ac, char **av);

// arguments_utils.c
int		ft_isspace(int c);
void	sort_int_array(int *arr, int size);
int		ft_abs(int n);

// costs_utils.c
void	calculate_costs(t_stack *a, t_stack *b);
int		choose_range_size(int size);
void	move_a(t_stack **a, int cost_a);
void	move_b(t_stack **b, int cost_b);
void	update_pos(t_stack *stack);

// find_nodes.c
int		find_min_pos(t_stack *a);
int		find_min_pos_in_a(t_stack *a);
int		is_better_node(t_stack *node, t_stack *best);
t_stack	*find_cheapest_node(t_stack *b);
int		find_pos_index0(t_stack *a);

// free.c
void	free_stack(t_stack *stack);
void	free_array(char **str);
void	error(void);

// is_valid.c
void	check_empty_str(char **numbers);
int		is_valid_char(char *s);
void	is_valid_args(int ac, char **av);
int		is_duplicated(char **numbers, int count);
int		is_sorted(t_stack *a);

// moves_multi.c
void	ss(t_stack **a, t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rrr(t_stack **a, t_stack **b);

// moves_ps.c
void	sa(t_stack **a, int print);
void	sb(t_stack **b, int print);
void	pb(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);

// moves_r.c
void	ra( t_stack **a, int print);
void	rb(t_stack **b, int print);
void	rra(t_stack **a, int print);
void	rrb(t_stack **b, int print);

// presort_to_b.c
void	rotate_up(t_stack **a, int steps);
void	rotate_down(t_stack **a, int steps);
void	rotate_a_to_pos(t_stack **a, int pos);
void	push_and_rot_if_small(t_stack **a, t_stack **b, int pushed, int step);
void	presort_to_b_big(t_stack **a, t_stack **b);

// push_swap.c
void	push_swap(t_stack **a, t_stack **b);
int		main(int ac, char **av);

// sort_sizes.c
void	sort_three(t_stack **a);
void	sort_four(t_stack **a, t_stack **b);
void	sort_five(t_stack **a, t_stack **b);
void	sort_small(t_stack **a, t_stack **b);
void	presort_to_b(t_stack **a, t_stack **b);

// stack_build.c
int		*str_to_int(char **numbers, int count);
int		*copy_and_sort(int *arr, int count);
int		get_index(int num, int *sorted, int size);
void	add_nodes(t_stack **stack_a, int *arr, int *sorted, int count);
t_stack	*build_stack(char **numbers);

// stacks_utils.c
t_stack	*stack_new(int num);
void	stack_add_back(t_stack **stack, t_stack *new);
void	stack_add_front(t_stack **stack, t_stack *new);
int		stack_size(t_stack *stack);
t_stack	*get_node_by_pos(t_stack *stack, int pos);

// target_b_to_a.c
int		pos_minid_greater(t_stack *a, int ref_idx);
void	set_targets_in_b(t_stack *b, t_stack *a);
void	execute_move(t_stack **a, t_stack **b, t_stack *node);
void	final_rotate_a(t_stack **a);
void	bring_back_to_a(t_stack **a, t_stack **b);

#endif