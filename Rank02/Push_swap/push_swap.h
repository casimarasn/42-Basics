/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 17:28:41 by msedeno-          #+#    #+#             */
/*   Updated: 2026/02/14 21:15:10 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/inc/libft.h"

/**
 * @brief Node structure for the stack (doubly linked list).
 * 
 * @param num The integer value stored in the node.
 * @param pos The current position/index of the node in the stack.
 * @param target_pos The target position in the other stack for sorting.
 * @param cost_a Cost of moves in stack A to position this node.
 * @param cost_b Cost of moves in stack B to position this node.
 * @param index The normalized index (rank) of the value in the sorted array.
 * @param prev Pointer to the previous node.
 * @param next Pointer to the next node.
 */
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

/* ========================================================================== */
/*                                 FUNCTIONS                                  */
/* ========================================================================== */

/* ========================================== */
/*               Arguments.c                  */
/* ========================================== *

/**
 * @brief Concatenates two strings adding a space character between them.
 */
char	*ft_strjoin_space(char const *s1, char const *s2);

/**
 * @brief Converts a string to a long integer, validating formats and
 * handling errors.
 */
int		ft_atoi_strict(const char *str, long *num);

/**
 * @brief Concatenates all command-line arguments into a single string.
 */
char	*create_big_av(int ac, char **av);

/**
 * @brief Processes and merges command-line arguments into a unified array
 * of strings.
 */
char	**join_arguments(int ac, char **av);

/* ========================================== */
/*               Arguments_utils.c            */
/* ========================================== */

/**
 * @brief Checks if a character is a whitespace.
 */
int		ft_isspace(int c);

/**
 * @brief Sorts an array of integers in ascending order.
 */
void	sort_int_array(int *arr, int size);

/**
 * @brief Returns the absolute value of an integer.
 */
int		ft_abs(int n);

/* ========================================== */
/*               Costs_utils.c                */
/* ========================================== */

/**
 * @brief Computes the cost (moves required) to push elements from B
 * back to their correct position in A.
 */
void	calculate_costs(t_stack *a, t_stack *b);

/**
 * @brief Determines the size of chunks/ranges based on the total number
 * of elements.
 */
int		choose_range_size(int size);

/**
 * @brief Executes the necessary rotations on stack A based on the calculated
 * cost.
 */
void	move_a(t_stack **a, int cost_a);

/**
 * @brief Executes the necessary rotations on stack B based on the calculated
 * cost.
 */
void	move_b(t_stack **b, int cost_b);

/**
 * @brief Updates the pos (current position) field for every node in the stack.
 */
void	update_pos(t_stack *stack);

/* ========================================== */
/*               Find_nodes.c                 */
/* ========================================== */

/**
 * @brief Finds the position of the node with the minimum value in the stack.
 */
int		find_min_pos(t_stack *a);

/**
 * @brief Finds the position of the global minimum value specifically within
 * stack A.
 */
int		find_min_pos_in_a(t_stack *a);

/**
 * @brief Compares two nodes to determine which one is cheaper to move.
 */
int		is_better_node(t_stack *node, t_stack *best);

/**
 * @brief Identifies the node in stack B that requires the fewest moves
 * to be pushed to A.
 */
t_stack	*find_cheapest_node(t_stack *b);

/**
 * @brief Finds the position of the node holding index 0 (the smallest number).
 */
int		find_pos_index0(t_stack *a);

/* ========================================== */
/*                Free.c                      */
/* ========================================== */

/**
 * @brief Frees all memory allocated for a stack (linked list).
 */
void	free_stack(t_stack *stack);

/**
 * @brief Frees a null-terminated array of strings.
 */
void	free_array(char **str);

/**
 * @brief Prints "Error" to standard error and terminates the program.
 */
void	error(void);

/* ========================================== */
/*               Is_valid.c                   */
/* ========================================== */

/**
 * @brief Verifies if an input string is empty or contains only spaces.
 */
void	check_empty_str(char **numbers);

/**
 * @brief Checks if strings contain only valid numeric characters (and signs).
 */
int		is_valid_char(char *s);

/**
 * @brief Validates the format and content of the command-line arguments.
 */
void	is_valid_args(int ac, char **av);

/**
 * @brief Checks if there are any duplicate numbers in the input.
 */
int		is_duplicated(char **numbers, int count);

/**
 * @brief Checks if stack A is already sorted in ascending order.
 */
int		is_sorted(t_stack *a);

/* ========================================== */
/*               Moves_multi.c                */
/* ========================================== */

/**
 * @brief Swaps the first two elements of both stack A and
 * stack B simultaneously.
 */
void	ss(t_stack **a, t_stack **b);

/**
 * @brief Rotates both stack A and stack B upwards simultaneously.
 */
void	rr(t_stack **a, t_stack **b);

/**
 * @brief Reverse rotates both stack A and stack B downwards simultaneously.
 */
void	rrr(t_stack **a, t_stack **b);

/* ========================================== */
/*               Moves_ps.c                   */
/* ========================================== */

/**
 * @brief Swaps the first two elements of stack A.
 */
void	sa(t_stack **a, int print);

/**
 * @brief Swaps the first two elements of stack B.
 */
void	sb(t_stack **b, int print);

/**
 * @brief Pushes the top element of stack A to the top of stack B.
 */
void	pb(t_stack **a, t_stack **b);

/**
 * @brief Pushes the top element of stack B to the top of stack A.
 */
void	pa(t_stack **a, t_stack **b);

/* ========================================== */
/*               Moves_r.c                    */
/* ========================================== */

/**
 * @brief Rotates stack A upwards (first becomes last).
 */
void	ra( t_stack **a, int print);

/**
 * @brief Rotates stack B upwards (first becomes last).
 */
void	rb(t_stack **b, int print);

/**
 * @brief Reverse rotates stack A downwards (last becomes first).
 */
void	rra(t_stack **a, int print);

/**
 * @brief Reverse rotates stack B downwards (last becomes first).
 */
void	rrb(t_stack **b, int print);

/* ========================================== */
/*               Presort_to_B.c               */
/* ========================================== */

/**
 * @brief Performs upward rotations on stack A a specific number of times.
 */
void	rotate_up(t_stack **a, int steps);

/**
 * @brief Performs downward rotations on stack A a specific number of times.
 */
void	rotate_down(t_stack **a, int steps);

/**
 * @brief Rotates stack A to bring a specific position to the top using the
 * shortest path.
 */
void	rotate_a_to_pos(t_stack **a, int pos);

/**
 * @brief Pushes an element from A to B and rotates B if the value is in the
 * lower half of the current range.
 */
void	push_and_rot_if_small(t_stack **a, t_stack **b, int pushed, int step);

/**
 * @brief Handles the pre-sorting logic for large stacks, moving elements to B
 * in chunks/ranges.
 */
void	presort_to_b_big(t_stack **a, t_stack **b);

/* ========================================== */
/*               Push_swap.c                  */
/* ========================================== */

/**
 * @brief The core algorithm controller that decides which sorting method
 * to use based on stack size.
 */
void	push_swap(t_stack **a, t_stack **b);

/**
 * @brief The entry point of the program.
 */
int		main(int ac, char **av);

/* ========================================== */
/*               Sort_sizes.c                 */
/* ========================================== */

/**
 * @brief Algorithms to sort exactly three elements.
 */
void	sort_three(t_stack **a);

/**
 * @brief Algorithms to sort exactly four elements.
 */
void	sort_four(t_stack **a, t_stack **b);

/**
 * @brief Algorithms to sort exactly five elements.
 */
void	sort_five(t_stack **a, t_stack **b);

/**
 * @brief Dispatches the sorting for small stacks (<= 5 elements).
 */
void	sort_small(t_stack **a, t_stack **b);

/**
 * @brief General pre-sorting function that moves elements from A to B.
 */
void	presort_to_b(t_stack **a, t_stack **b);

/* ========================================== */
/*               Stack_build.c                */
/* ========================================== */

/**
 * @brief Converts an array of string numbers into an array of integers.
 */
int		*str_to_int(char **numbers, int count);

/**
 * @brief Creates a sorted copy of the integer array to calculate
 * normalized indices.
 */
int		*copy_and_sort(int *arr, int count);

/**
 * @brief Finds the rank/index of a number based on the sorted array.
 */
int		get_index(int num, int *sorted, int size);

/**
 * @brief Creates and adds nodes to stack A populated with values and indices.
 */
void	add_nodes(t_stack **stack_a, int *arr, int *sorted, int count);

/**
 * @brief Orchestrates the parsing and creation of the initial stack A
 * from arguments.
 */
t_stack	*build_stack(char **numbers);

/* ========================================== */
/*               Stack_utils.c                */
/* ========================================== */

/**
 * @brief Allocates and initializes a new stack node.
 */
t_stack	*stack_new(int num);

/**
 * @brief Adds a new node to the end of the stack.
 */
void	stack_add_back(t_stack **stack, t_stack *new);

/**
 * @brief Adds a new node to the beginning of the stack.
 */
void	stack_add_front(t_stack **stack, t_stack *new);

/**
 * @brief Returns the number of elements in the stack.
 */
int		stack_size(t_stack *stack);

/**
 * @brief Retrieves a pointer to the node at a specific numeric position.
 */
t_stack	*get_node_by_pos(t_stack *stack, int pos);

/* ========================================== */
/*               Target_to_a.c                */
/* ========================================== */

/**
 * @brief Finds the position of the smallest index in A that is greater
 * than the reference index.
 */
int		pos_minid_greater(t_stack *a, int ref_idx);

/**
 * @brief Calculates target positions in A for all nodes currently in B.
 */
void	set_targets_in_b(t_stack *b, t_stack *a);

/**
 * @brief Performs the cheapest sequence of operations to move a node
 * from B to its target in A.
 */
void	execute_move(t_stack **a, t_stack **b, t_stack *node);

/**
 * @brief Rotates stack A at the end to ensure the smallest element
 * is at the top.
 */
void	final_rotate_a(t_stack **a);

/**
 * @brief Manages the process of pushing elements back from B to A until
 * B is empty.
 */
void	bring_back_to_a(t_stack **a, t_stack **b);

#endif