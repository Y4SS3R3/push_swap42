/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymassiou <ymassiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 14:08:18 by ymassiou          #+#    #+#             */
/*   Updated: 2024/01/29 10:20:43 by ymassiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	pb(t_stack **head_a, t_stack **head_b, int index)
{
	t_stack	*tmp;

	if (*head_a == NULL)
		return ;
	tmp = *head_b;
	*head_b = *head_a;
	*head_a = (*head_a)-> next;
	(*head_b)-> next = tmp;
	if (index == 1)
		ft_putstr_fd("pb\n", 1);
}

void	pa(t_stack **head_a, t_stack **head_b, int index)
{
	t_stack	*tmp;

	if (*head_b == NULL)
		return ;
	tmp = *head_a;
	*head_a = *head_b;
	*head_b = (*head_b)-> next;
	(*head_a)-> next = tmp;
	if (index == 1)
		ft_putstr_fd("pa\n", 1);
}
