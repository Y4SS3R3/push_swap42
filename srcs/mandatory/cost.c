/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymassiou <ymassiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:09:18 by mcombeau          #+#    #+#             */
/*   Updated: 2024/01/29 10:27:33 by ymassiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_target_pos(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_b;
	int		target_pos;

	tmp_b = *stack_b;
	index_it(*stack_a);
	index_it(*stack_b);
	target_pos = 0;
	while (tmp_b)
	{
		target_pos = target(stack_a, tmp_b->final_rank, INT_MAX, target_pos);
		tmp_b->target_pos = target_pos;
		tmp_b = tmp_b->next;
	}
}

int	target(t_stack **stack_a, int final_b, int target, int target_pos)
{
	t_stack	*tmp_a;

	tmp_a = *stack_a;
	while (tmp_a)
	{
		if (tmp_a->final_rank > final_b && tmp_a->final_rank < target)
		{
			target = tmp_a->final_rank;
			target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	if (target != INT_MAX)
		return (target_pos);
	tmp_a = *stack_a;
	while (tmp_a)
	{
		if (tmp_a->final_rank < target)
		{
			target = tmp_a->final_rank;
			target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	return (target_pos);
}

void	calculate_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	size_a = ft_stacksize(tmp_a);
	size_b = ft_stacksize(tmp_b);
	while (tmp_b)
	{
		if (tmp_b->pos > size_b / 2)
			tmp_b->cost_stack_b = -(size_b - tmp_b->pos);
		else
			tmp_b->cost_stack_b = tmp_b->pos;
		if (tmp_b->target_pos > size_a / 2)
			tmp_b->cost_stack_a = -(size_a - tmp_b->target_pos);
		else
			tmp_b->cost_stack_a = tmp_b->target_pos;
		tmp_b = tmp_b->next;
	}
}

void	cheapest_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		cheapest;
	int		cost_stack_a;
	int		cost_stack_b;

	tmp = *stack_b;
	cheapest = INT_MAX;
	while (tmp)
	{
		if (abs(tmp->cost_stack_a) + abs(tmp->cost_stack_b) < cheapest)
		{
			cheapest = abs(tmp->cost_stack_b) + abs(tmp->cost_stack_a);
			cost_stack_a = tmp->cost_stack_a;
			cost_stack_b = tmp->cost_stack_b;
		}
		tmp = tmp->next;
	}
	do_move(stack_a, stack_b, &cost_stack_a, &cost_stack_b);
}
