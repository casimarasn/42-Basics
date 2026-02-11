/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 12:43:01 by casimarasn        #+#    #+#             */
/*   Updated: 2026/02/11 23:17:09 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_costs(t_stack *a, t_stack *b)
{
	t_stack	*node_b;
	int		size_a;
	int		size_b;

	if (!a || !b)
		return ;
	size_a = stack_size(a);
	size_b = stack_size(b);
	node_b = b;
	while (1)
	{
		if (node_b->pos <= size_b / 2)
			node_b->cost_b = node_b->pos;
		else
			node_b->cost_b = node_b->pos - size_b;
		if (node_b->target_pos <= size_a / 2)
			node_b->cost_a = node_b->target_pos;
		else
			node_b->cost_a = node_b->target_pos - size_a;
		node_b = node_b->next;
		if (node_b == b)
			break ;
	}
}

int	choose_range_size(int size)
{
	if (size <= 200)
		return (20);
	return (45);
}

void	move_a(t_stack **a, int cost_a)
{
	while (cost_a)
	{
		if (cost_a > 0)
		{
			ra(a, 1);
			cost_a--;
		}
		else
		{
			rra(a, 1);
			cost_a++;
		}
	}
}

void	move_b(t_stack **b, int cost_b)
{
	while (cost_b)
	{
		if (cost_b > 0)
		{
			rb(b, 1);
			cost_b--;
		}
		else
		{
			rrb(b, 1);
			cost_b++;
		}
	}
}

void	update_pos(t_stack *stack)
{
	t_stack	*tmp;
	int		i;
	int		size;

	if (!stack)
		return ;
	size = stack_size(stack);
	tmp = stack;
	i = 0;
	while (i < size)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}
