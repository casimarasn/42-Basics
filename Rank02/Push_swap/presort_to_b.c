/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presort_to_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 16:35:00 by casimarasn        #+#    #+#             */
/*   Updated: 2026/02/11 23:17:27 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_up(t_stack **a, int steps)
{
	int	i;

	i = 0;
	while (i < steps)
	{
		ra(a, 1);
		i++;
	}
}

void	rotate_down(t_stack **a, int steps)
{
	int	i;

	i = 0;
	while (i < steps)
	{
		rra(a, 1);
		i++;
	}
}

void	rotate_a_to_pos(t_stack **a, int pos)
{
	int	size;

	if (!a || !*a)
		return ;
	size = stack_size(*a);
	if (pos <= size / 2)
		rotate_up(a, pos);
	else
		rotate_down(a, size - pos);
}

void	push_and_rot_if_small(t_stack **a, t_stack **b, int pushed, int step)
{
	pb(a, b);
	if (*b && (*b)->index < pushed - (step / 2))
		rb(b, 1);
}

void	presort_to_b_big(t_stack **a, t_stack **b)
{
	int	size;
	int	pushed;
	int	step;

	if (!a || !*a)
		return ;
	size = stack_size(*a);
	step = choose_range_size(size);
	pushed = 0;
	while (stack_size(*a) > 3)
	{
		update_pos(*a);
		if ((*a)->index <= pushed)
		{
			push_and_rot_if_small(a, b, pushed, step);
			pushed++;
		}
		else if ((*a)->index <= pushed + step)
		{
			push_and_rot_if_small(a, b, pushed, step);
			pushed++;
		}
		else
			ra(a, 1);
	}
}
