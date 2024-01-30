/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_n.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymassiou <ymassiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 13:27:56 by ymassiou          #+#    #+#             */
/*   Updated: 2024/01/29 10:30:15 by ymassiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_final(t_stack **stack)
{
	t_stack	*tmp;
	int		lowest_final_rank;
	int		lowest_pos;

	tmp = *stack;
	lowest_final_rank = INT_MAX;
	index_it(*stack);
	lowest_pos = tmp->pos;
	while (tmp)
	{
		if (tmp->final_rank < lowest_final_rank)
		{
			lowest_final_rank = tmp->final_rank;
			lowest_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (lowest_pos);
}

static void	top_it(t_stack **stack_a)
{
	int	size;
	int	min;

	size = ft_stacksize(*stack_a);
	min = find_min_final(stack_a);
	if (min > size / 2)
	{
		while (min < size)
		{
			rra(stack_a, 1);
			min++;
		}
	}
	else
	{
		while (min > 0)
		{
			ra(stack_a, 1);
			min--;
		}
	}
}

static void	push_less_med(t_stack **stack_a, t_stack **stack_b, int size)
{
	while (more_sort(*stack_a, size))
	{
		if ((*stack_a)->final_rank <= size / 2)
			pb(stack_a, stack_b, 1);
		else
			ra(stack_a, 1);
	}
}

void	sort_n(t_stack **head_a, t_stack **head_b, int size)
{
	int		count;

	push_less_med(head_a, head_b, size);
	count = ft_stacksize(*head_a);
	while (count > 3)
	{
		pb(head_a, head_b, 1);
		count--;
	}
	sort_three(head_a);
	while (ft_stacksize(*head_b))
	{
		set_target_pos(head_a, head_b);
		calculate_cost(head_a, head_b);
		cheapest_move(head_a, head_b);
	}
	if (is_sorted(*head_a))
		return ;
	top_it(head_a);
}

void	sort_three(t_stack **head)
{
	t_stack	*middle;
	t_stack	*first;
	int		max;
	int		size;

	first = *head;
	size = ft_stacksize(*head);
	max = find_max_final(*head);
	middle = first -> next;
	if (size == 1)
		return ;
	else if (size == 2)
	{
		if ((*head)-> final_rank > (*head)-> next -> final_rank)
			sa(head, 1);
		return ;
	}
	if (first -> final_rank == max)
		ra(head, 1);
	else if (middle -> final_rank == max)
		rra(head, 1);
	if ((*head)-> final_rank > (*head)-> next -> final_rank)
		sa(head, 1);
}
