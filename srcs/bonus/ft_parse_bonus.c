/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymassiou <ymassiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 11:47:04 by ymassiou          #+#    #+#             */
/*   Updated: 2024/01/29 10:17:44 by ymassiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	ft_check(char c)
{
	if (c == '+' || c == '-' || ft_isdigit(c))
		return (1);
	return (0);
}

static int	check_input(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (!ft_check(str[i]) && str[i] != ' ')
			return (0);
		else if (ft_isdigit(str[i]) && (str[i + 1] == '+' || str[i + 1] == '-'))
			return (0);
		if (str[i] >= '0' && str[i] <= '9')
			count++;
		i++;
	}
	if (count == 0)
		return (0);
	return (1);
}

static int	is_duplicate(t_stack *current, long new_int)
{
	while (current)
	{
		if ((int)current->content == new_int)
			return (1);
		current = current->next;
	}
	if (new_int > INT_MAX || new_int < INT_MIN)
		return (1);
	return (0);
}

static t_stack	*ft_retrieve(char *str, t_stack **head)
{
	int		i;
	long	result;
	t_stack	*new;

	i = 0;
	while (str[i])
	{
		while (str[i] == ' ' && str[i])
			i++;
		if (!str[i])
			break ;
		result = ft_atoi(&str[i]);
		if (is_duplicate(*head, result))
		{
			free_stack(head, 0);
			error_protocol();
		}
		new = ft_stacknew(result);
		if (new == NULL)
			free_stack(head, 1);
		ft_stackadd_back(head, new);
		while (str[i] && ft_check(str[i]))
			i++;
	}
	return (*head);
}

t_stack	*ft_parse(int argc, char **argv)
{
	int		i;
	t_stack	*head;

	i = 1;
	head = NULL;
	while (i < argc)
	{
		if (check_input(argv[i]) == 0)
			error_protocol();
		head = ft_retrieve(argv[i], &head);
		i++;
	}
	return (head);
}
