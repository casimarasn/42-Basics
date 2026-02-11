/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 17:28:48 by msedeno-          #+#    #+#             */
/*   Updated: 2026/02/11 23:21:10 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	push_swap(t_stack **a, t_stack **b)
{
	char	*str;

	while (1)
	{
		str = get_next_line(0);
		if (str == NULL)
			break ;
		move_if(a, b, str);
		free(str);
	}
	if ((is_sorted(*a) == 1) && !*b)
		ft_putstr_fd ("OK\n", 1);
	else
		ft_putstr_fd ("KO\n", 1);
}

void	move_if(t_stack **a, t_stack **b, char *str)
{
	if (ft_strncmp ("ra\n", str, 3) == 0)
		ra(a, 0);
	else if (ft_strncmp ("rb\n", str, 3) == 0)
		rb(b, 0);
	else if (ft_strncmp ("rra\n", str, 4) == 0)
		rra(a, 0);
	else if (ft_strncmp ("rrb\n", str, 4) == 0)
		rrb(b, 0);
	else if (ft_strncmp ("sa\n", str, 3) == 0)
		sa(a, 0);
	else if (ft_strncmp ("sb\n", str, 3) == 0)
		sb(b, 0);
	else if (ft_strncmp ("pa\n", str, 3) == 0)
		pa(a, b);
	else if (ft_strncmp ("pb\n", str, 3) == 0)
		pb(a, b);
	else if (ft_strncmp ("rr\n", str, 3) == 0)
		rr(a, b);
	else if (ft_strncmp ("rrr\n", str, 4) == 0)
		rrr(a, b);
	else if (ft_strncmp ("ss\n", str, 3) == 0)
		ss(a, b);
	else
		free_stacks(a, b, str);
}

int	main(int ac, char **av)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	char		**numbers;

	stack_b = NULL;
	if (ac < 2)
		return (0);
	numbers = join_arguments(ac, av);
	if (!numbers || !numbers[0] || !*numbers[0])
	{
		free_array(numbers);
		error();
	}
	stack_a = build_stack(numbers);
	free_array(numbers);
	push_swap(&stack_a, &stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
