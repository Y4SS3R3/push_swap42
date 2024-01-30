/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymassiou <ymassiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 22:27:03 by ymassiou          #+#    #+#             */
/*   Updated: 2024/01/29 16:46:58 by ymassiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*head_a;
	t_stack	*head_b;
	int		size;

	if (argc < 2)
		exit(0);
	head_a = ft_parse(argc, argv);
	head_b = NULL;
	size = index_it(head_a);
	findex_it(head_a, size);
	if (is_sorted(head_a))
		return (0);
	if (size <= 3)
		sort_three(&head_a);
	else
		sort_n(&head_a, &head_b, size);
	free_stack(&head_a, 0);
	free_stack(&head_b, 0);
	return (0);
}
