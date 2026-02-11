/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 08:53:51 by msedeno-          #+#    #+#             */
/*   Updated: 2026/02/11 23:17:12 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_pos(t_stack *a)
{
	int		min;
	int		pos;
	int		i;
	t_stack	*tmp;

	if (!a)
		return (-1);
	min = a->num;
	pos = 0;
	i = 0;
	tmp = a->next;
	while (tmp != a)
	{
		i++;
		if (tmp->num < min)
		{
			min = tmp->num;
			pos = i;
		}
		tmp = tmp->next;
	}
	return (pos);
}

int	find_min_pos_in_a(t_stack *a)
{
	t_stack	*tmp;
	int		i;
	int		size;
	int		min_i;
	int		min_pos;

	if (!a)
		return (-1);
	size = stack_size(a);
	tmp = a;
	min_i = tmp->index;
	min_pos = tmp->pos;
	i = 1;
	while (i < size)
	{
		tmp = tmp->next;
		if (tmp->index < min_i)
		{
			min_i = tmp->index;
			min_pos = tmp->pos;
		}
		i++;
	}
	return (min_pos);
}

int	is_better_node(t_stack *node, t_stack *best)
{
	int	node_cost;
	int	best_cost;

	node_cost = ft_abs(node->cost_a) + ft_abs(node->cost_b);
	best_cost = ft_abs(best->cost_a) + ft_abs(best->cost_b);
	if (node_cost < best_cost)
		return (1);
	if (node_cost == best_cost)
	{
		if ((node->cost_a > 0 && node->cost_b > 0)
			|| (node->cost_a < 0 && node->cost_b < 0))
		{
			if (!((best->cost_a > 0 && best->cost_b > 0)
					|| (best->cost_a < 0 && best->cost_b < 0)))
				return (1);
		}
	}
	return (0);
}

t_stack	*find_cheapest_node(t_stack *b)
{
	t_stack	*node;
	t_stack	*best;
	int		size;
	int		i;

	if (!b)
		return (NULL);
	size = stack_size(b);
	best = b;
	node = b->next;
	i = 1;
	while (i < size)
	{
		if (is_better_node(node, best))
			best = node;
		node = node->next;
		i++;
	}
	return (best);
}

int	find_pos_index0(t_stack *a)
{
	t_stack	*tmp;
	int		size;
	int		i;

	if (!a)
		return (-1);
	size = stack_size(a);
	tmp = a;
	i = 0;
	while (i < size)
	{
		if (tmp->index == 0)
			return (tmp->pos);
		tmp = tmp->next;
		i++;
	}
	return (-1);
}
