/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotation_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymassiou <ymassiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:02:31 by ymassiou          #+#    #+#             */
/*   Updated: 2024/01/29 10:20:39 by ymassiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rra(t_stack **head, int state)
{
	t_stack	*first;
	t_stack	*last;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	first = *head;
	last = ft_stacklast(*head);
	while ((*head)->next != last)
		*head = (*head)->next;
	(*head)->next = NULL;
	last->next = first;
	*head = last;
	if (state)
		ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack **head, int state)
{
	t_stack	*first;
	t_stack	*last;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	first = *head;
	last = ft_stacklast(*head);
	while ((*head)->next != last)
		*head = (*head)->next;
	(*head)->next = NULL;
	last->next = first;
	*head = last;
	if (state)
		ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack **head_a, t_stack **head_b, int index)
{
	rra(head_a, 0);
	rrb(head_b, 0);
	if (index == 1)
		ft_putstr_fd("rrr\n", 1);
}
