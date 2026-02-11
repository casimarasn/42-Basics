/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 17:28:41 by msedeno-          #+#    #+#             */
/*   Updated: 2025/10/14 18:28:25 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"

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

// free.c
void	free_stack(t_stack *stack);
void	free_array(char **str);
void	error(void);
void	free_stacks(t_stack **a, t_stack **b, char *str);

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

// push_swap.c
void	gnl_call(t_stack **a, t_stack **b);
void	move_if(t_stack **a, t_stack **b, char *str);
void	push_swap(t_stack **a, t_stack **b);
int		main(int ac, char **av);

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

#endif