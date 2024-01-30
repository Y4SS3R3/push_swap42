/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymassiou <ymassiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:55:57 by ymassiou          #+#    #+#             */
/*   Updated: 2024/01/29 15:41:07 by ymassiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	more_sort(t_stack *stack, int size)
{
	while (stack)
	{
		if (stack -> final_rank <= size / 2)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	abs(int num)
{
	if (num < 0)
		num = -num;
	return (num);
}

int	is_sorted(t_stack *stack)
{
	if (stack == NULL)
		return (0);
	while (stack->next != NULL)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	find_max_final(t_stack *stack)
{
	int	max;

	max = -1;
	while (stack)
	{
		if (stack->final_rank > max)
			max = stack->final_rank;
		stack = stack->next;
	}
	return (max);
}
