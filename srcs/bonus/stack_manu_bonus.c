/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manu_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymassiou <ymassiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:30:18 by ymassiou          #+#    #+#             */
/*   Updated: 2024/01/29 15:04:52 by ymassiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_stackadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (lst == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		last = ft_stacklast(*lst);
		last -> next = new;
	}
}

t_stack	*ft_stacklast(t_stack *lst)
{
	t_stack	*current;

	current = lst;
	if (current == NULL)
		return (NULL);
	while (current->next != NULL)
	{
		current = current->next;
	}
	return (current);
}

t_stack	*ft_stacknew(int content)
{
	t_stack	*head;

	head = (t_stack *)malloc(sizeof(t_stack));
	if (head == NULL)
		return (NULL);
	head -> content = content;
	head -> final_rank = -1;
	head -> target_pos = -1;
	head->cost_stack_a = -1;
	head->cost_stack_b = -1;
	head -> next = NULL;
	return (head);
}

int	ft_stacksize(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst -> next;
	}
	return (i);
}
