/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymassiou <ymassiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:51:35 by ymassiou          #+#    #+#             */
/*   Updated: 2024/01/29 10:28:17 by ymassiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rx_both(t_stack **head_a, t_stack **head_b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		rr(head_a, head_b, 1);
		(*cost_a)--;
		(*cost_b)--;
	}
}

void	rrx_both(t_stack **head_a, t_stack **head_b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		rrr(head_a, head_b, 1);
		(*cost_a)++;
		(*cost_b)++;
	}
}

void	do_rotate_a(t_stack **head_a, int *cost_a)
{
	while (*cost_a)
	{
		if (*cost_a > 0)
		{
			ra(head_a, 1);
			(*cost_a)--;
		}
		else if (*cost_a < 0)
		{
			rra(head_a, 1);
			(*cost_a)++;
		}
	}
}

void	do_rotate_b(t_stack **head_b, int *cost_b)
{
	while (*cost_b)
	{
		if (*cost_b > 0)
		{
			rb(head_b, 1);
			(*cost_b)--;
		}
		else if (*cost_b < 0)
		{
			rrb(head_b, 1);
			(*cost_b)++;
		}
	}
}

void	do_move(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	if (*cost_a < 0 && *cost_b < 0)
		rrx_both(a, b, cost_a, cost_b);
	else if (*cost_a > 0 && *cost_b > 0)
		rx_both(a, b, cost_a, cost_b);
	do_rotate_a(a, cost_a);
	do_rotate_b(b, cost_b);
	pa(a, b, 1);
}
