/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymassiou <ymassiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:56:35 by ymassiou          #+#    #+#             */
/*   Updated: 2024/01/29 10:20:27 by ymassiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sa(t_stack **head, int state)
{
	t_stack	*first;
	t_stack	*second;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	first = *head;
	second = (*head)->next;
	first->next = second->next;
	second->next = first;
	*head = second;
	if (state)
		ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack **head, int state)
{
	t_stack	*first;
	t_stack	*second;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	first = *head;
	second = (*head)->next;
	first->next = second->next;
	second->next = first;
	*head = second;
	if (state)
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack **head_a, t_stack **head_b, int index)
{
	sa(head_a, 0);
	sb(head_b, 0);
	if (index == 1)
		ft_putstr_fd("ss\n", 1);
}
