/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymassiou <ymassiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 20:18:58 by ymassiou          #+#    #+#             */
/*   Updated: 2024/01/29 10:29:46 by ymassiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **stack, int index)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
	if (index == 1)
		exit(EXIT_FAILURE);
}

int	index_it(t_stack *head)
{
	int	index;

	index = 0;
	while (head)
	{
		head -> pos = index;
		index++;
		head = head -> next;
	}
	return (index);
}

void	findex_it(t_stack *head, int size)
{
	int		max;
	t_stack	*curr;
	t_stack	*max_pos;

	while (size > 0)
	{
		curr = head;
		max = INT_MIN;
		while (curr)
		{
			if (curr -> content > max && curr -> final_rank < 0)
			{
				max_pos = curr;
				max = curr -> content;
			}
			curr = curr -> next;
		}
		max_pos -> final_rank = size;
		size--;
	}
}

size_t	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
