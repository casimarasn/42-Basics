/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_ps_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 17:29:02 by msedeno-          #+#    #+#             */
/*   Updated: 2025/10/14 18:33:52 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

// sa, sb, pa, pb;

void	sa(t_stack **a, int print)
{
	t_stack	*first;
	t_stack	*second;
	int		tmp_num;
	int		tmp_index;

	if (!a || !*a || (*a)->next == *a)
		return ;
	first = *a;
	second = (*a)->next;
	tmp_num = first->num;
	tmp_index = first->index;
	first->num = second->num;
	first->index = second ->index;
	second->num = tmp_num;
	second->index = tmp_index;
	if (print == 1)
		ft_putstr_fd ("sa\n", 1);
}

void	sb(t_stack **b, int print)
{
	t_stack	*first;
	t_stack	*second;
	int		tmp_num;
	int		tmp_index;

	if (!b || !*b || (*b)->next == (*b))
		return ;
	first = *b;
	second = (*b)->next;
	tmp_num = first->num;
	tmp_index = first->index;
	first->num = second->num;
	first->index = second->index;
	second->num = tmp_num;
	second->index = tmp_index;
	if (print == 1)
		ft_putstr_fd("sb\n", 1);
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp_node;

	if (!a || !*a)
		return ;
	tmp_node = *a;
	if (tmp_node->next == tmp_node)
		*a = NULL;
	else
	{
		tmp_node->prev->next = tmp_node->next;
		tmp_node->next->prev = tmp_node->prev;
		*a = tmp_node ->next;
	}
	tmp_node->next = NULL;
	tmp_node->prev = NULL;
	stack_add_front(b, tmp_node);
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp_node;

	if (!b || !*b)
		return ;
	tmp_node = *b;
	if (tmp_node->next == tmp_node)
		*b = NULL;
	else
	{
		tmp_node->prev->next = tmp_node->next;
		tmp_node->next->prev = tmp_node->prev;
		*b = tmp_node->next;
	}
	tmp_node->next = NULL;
	tmp_node->prev = NULL;
	stack_add_front(a, tmp_node);
}
