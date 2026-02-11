/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .print_testers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 17:21:23 by msedeno-          #+#    #+#             */
/*   Updated: 2026/02/11 23:16:57 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack, char name)
{
	t_stack	*tmp;
	int		count;

	ft_printf("Stack %c:\n", name);
	if (!stack)
	{
		ft_printf("(empty)\n");
		return ;
	}
	tmp = stack;
	count = 0;
	while (1)
	{
		ft_printf("%d\n", tmp->num);
		tmp = tmp->next;
		if (tmp == stack)
			break ;
		if (++count > 100)
		{
			ft_printf("Bucle infinito detectado\n");
			break ;
		}
	}
}

void	print_stack_verbose(t_stack *stack, char name)
{
	t_stack	*tmp;

	ft_printf("Stack %c:\n", name);
	if (!stack)
	{
		ft_printf("(empty)\n");
		return ;
	}
	tmp = stack;
	do
	{
		ft_printf("[num:%d idx:%d pos:%d chunk:%d] ",
			tmp->num, tmp->index, tmp->pos, tmp->chunk);
	tmp = tmp->next;
	} while (tmp != stack);
	ft_printf("\n");
}

void	print_b_targets_and_costs(t_stack *b)
{
	t_stack	*tmp = b;

	if (!b)
	{
		ft_printf("Stack B (empty)\n");
		return ;
	}
	ft_printf("Stack B targets and costs:\n");
	do
	{
		ft_printf("[num:%d pos:%d target:%d cost_a:%d cost_b:%d]\n",
			tmp->num, tmp->pos, tmp->target_pos, tmp->cost_a, tmp->cost_b);
	tmp = tmp->next;
	} while (tmp != b);
	ft_printf("\n");
}

void	test_index_vs_pos(t_stack *stack)
{
	t_stack	*tmp;

	if (!stack)
		return ;
	printf("\n=== ÍNDICES vs POSICIONES ===\n");
	printf("Num  | Idx | Pos | Significado\n");
	printf("-----|-----|-----|------------\n");
	tmp = stack;
	do
	{
		printf("%4d | %3d | %3d | %dº más pequeño\n", 
			tmp->num, tmp->index, tmp->pos, tmp->index + 1);
	tmp = tmp->next;
	} while (tmp != stack);
}
