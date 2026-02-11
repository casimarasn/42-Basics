/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_b_to_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 17:56:45 by casimarasn        #+#    #+#             */
/*   Updated: 2026/02/11 23:18:04 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pos_minid_greater(t_stack *a, int ref_idx)
{
	t_stack	*tmp;
	int		best_i;
	int		best_pos;
	int		i;
	int		size;

	if (!a)
		return (-1);
	size = stack_size(a);
	tmp = a;
	best_i = INT_MAX;
	best_pos = -1;
	i = 0;
	while (i < size)
	{
		if (tmp->index > ref_idx && tmp->index < best_i)
		{
			best_i = tmp->index;
			best_pos = tmp->pos;
		}
		tmp = tmp->next;
		i++;
	}
	return (best_pos);
}

void	set_targets_in_b(t_stack *b, t_stack *a)
{
	t_stack	*node;
	int		size;
	int		i;
	int		pos;

	if (!b || !a)
		return ;
	size = stack_size(b);
	node = b;
	i = 0;
	while (i < size)
	{
		pos = pos_minid_greater(a, node->index);
		if (pos == -1)
			node->target_pos = find_min_pos_in_a(a);
		else
			node->target_pos = pos;
		node = node->next;
		i++;
	}
}

void	execute_move(t_stack **a, t_stack **b, t_stack *node)
{
	int	cost_a;
	int	cost_b;

	if (!node)
		return ;
	cost_a = node->cost_a;
	cost_b = node->cost_b;
	while (cost_a > 0 && cost_b > 0)
	{
		rr(a, b);
		cost_a--;
		cost_b--;
	}
	while (cost_a < 0 && cost_b < 0)
	{
		rrr(a, b);
		cost_a++;
		cost_b++;
	}
	move_a(a, cost_a);
	move_b(b, cost_b);
	pa(a, b);
}

void	final_rotate_a(t_stack **a)
{
	int	pos0;

	if (!a || !*a)
		return ;
	pos0 = find_pos_index0(*a);
	if (pos0 == -1)
		return ;
	rotate_a_to_pos(a, pos0);
}

void	bring_back_to_a(t_stack **a, t_stack **b)
{
	while (b && *b)
	{
		update_pos(*a);
		update_pos(*b);
		set_targets_in_b(*b, *a);
		calculate_costs(*a, *b);
		execute_move(a, b, find_cheapest_node(*b));
	}
	update_pos(*a);
	final_rotate_a(a);
}
