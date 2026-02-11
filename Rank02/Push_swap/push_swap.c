/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 17:28:48 by msedeno-          #+#    #+#             */
/*   Updated: 2026/02/11 23:17:34 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack **a, t_stack **b)
{
	int	size;

	if (is_sorted(*a))
		return ;
	size = stack_size(*a);
	if (size <= 5)
		return (sort_small(a, b));
	if (size <= 100)
	{
		presort_to_b(a, b);
		sort_three(a);
		bring_back_to_a(a, b);
		return ;
	}
	presort_to_b_big(a, b);
	sort_three(a);
	bring_back_to_a(a, b);
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
	push_swap(&stack_a, &stack_b);
	free_stack(stack_a);
	free_array(numbers);
	return (0);
}
