/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymassiou <ymassiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 21:24:07 by ymassiou          #+#    #+#             */
/*   Updated: 2024/01/29 10:17:21 by ymassiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	check_stack(t_stack *stack_a, t_stack *stack_b)
{
	if (is_sorted(stack_a) != 0 && stack_b == NULL)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free_stack(&stack_a, 0);
	free_stack(&stack_b, 0);
}

static void	exec_move(char *command, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp("sa\n", command) == 0)
		sa(stack_a, 0);
	else if (ft_strcmp("sb\n", command) == 0)
		sb(stack_b, 0);
	else if (ft_strcmp("ss\n", command) == 0)
		ss(stack_a, stack_b, 0);
	else if (ft_strcmp("ra\n", command) == 0)
		ra(stack_a, 0);
	else if (ft_strcmp("rb\n", command) == 0)
		rb(stack_b, 0);
	else if (ft_strcmp("rr\n", command) == 0)
		rr(stack_a, stack_b, 0);
	else if (ft_strcmp("rra\n", command) == 0)
		rra(stack_a, 0);
	else if (ft_strcmp("rrb\n", command) == 0)
		rrb(stack_b, 0);
	else if (ft_strcmp("rrr\n", command) == 0)
		rrr(stack_a, stack_b, 0);
	else if (ft_strcmp("pa\n", command) == 0)
		pa(stack_a, stack_b, 0);
	else if (ft_strcmp("pb\n", command) == 0)
		pb(stack_a, stack_b, 0);
	else
		error_protocol();
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		check;
	char	*command;

	if (ac == 1)
		return (0);
	stack_a = ft_parse(ac, av);
	stack_b = NULL;
	check = 1;
	while (check)
	{
		command = get_next_line(0);
		if (command == NULL)
		{
			check = 0;
			break ;
		}
		exec_move(command, &stack_a, &stack_b);
		free(command);
	}
	check_stack(stack_a, stack_b);
	return (0);
}
