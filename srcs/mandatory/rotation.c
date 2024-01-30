/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymassiou <ymassiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 19:55:36 by ymassiou          #+#    #+#             */
/*   Updated: 2024/01/29 10:29:04 by ymassiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **head, int state)
{
	t_stack	*first;
	t_stack	*last;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	first = *head;
	last = ft_stacklast(*head);
	*head = first -> next;
	last->next = first;
	first->next = NULL;
	if (state)
		ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack **head, int state)
{
	t_stack	*first;
	t_stack	*last;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	first = *head;
	last = ft_stacklast(*head);
	*head = first -> next;
	last->next = first;
	first->next = NULL;
	if (state)
		ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack **head_a, t_stack **head_b, int index)
{
	ra(head_a, 0);
	rb(head_b, 0);
	if (index == 1)
		ft_putstr_fd("rr\n", 1);
}
