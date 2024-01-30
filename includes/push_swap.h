/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymassiou <ymassiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 11:50:12 by ymassiou          #+#    #+#             */
/*   Updated: 2024/01/29 18:07:18 by ymassiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				content;
	int				pos;
	int				target_pos;
	int				final_rank;
	int				cost_stack_a;
	int				cost_stack_b;
	struct s_stack	*next;
}	t_stack;
t_stack	*ft_parse(int argc, char **argv);
void	pb(t_stack **head_a, t_stack **head_b, int index);
void	pa(t_stack **head_a, t_stack **head_b, int index);
void	ft_putstr_fd(char *s, int fd);
long	ft_atoi(const char *str);
int		ft_isdigit(int c);
void	ft_stackadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_stacklast(t_stack *lst);
t_stack	*ft_stacknew(int content);
int		ft_stacksize(t_stack *lst);
void	sort_three(t_stack **head);
void	sort_n(t_stack **head_a, t_stack **head_b, int size);
void	ra(t_stack **head, int state);
void	rb(t_stack **head, int state);
void	rr(t_stack **head_a, t_stack **head_b, int index);
void	rrb(t_stack **head, int state);
void	rra(t_stack **head, int state);
void	rrr(t_stack **head_a, t_stack **head_b, int index);
void	sa(t_stack **head, int state);
void	sb(t_stack **head, int state);
void	ss(t_stack **head_a, t_stack **head_b, int index);
int		index_it(t_stack *head);
int		abs(int num);
void	rx_both(t_stack **head_a, t_stack **head_b, int *cost_a, int *cost_b);
void	rrx_both(t_stack **head_a, t_stack **head_b, int *cost_a, int *cost_b);
void	do_rotate_a(t_stack **head_a, int *cost_a);
void	do_rotate_b(t_stack **head_b, int *cost_b);
void	do_move(t_stack **a, t_stack **b, int *cost_a, int *cost_b);
int		more_sort(t_stack *stack, int size);
void	calculate_cost(t_stack **stack_a, t_stack **stack_b);
void	cheapest_move(t_stack **stack_a, t_stack **stack_b);
void	findex_it(t_stack *head, int size);
int		is_sorted(t_stack *stack);
int		find_max_final(t_stack *stack);
int		target(t_stack **a, int b_idx, int target_idx, int target_pos);
void	set_target_pos(t_stack **a, t_stack **b);
void	free_stack(t_stack **stack, int index);
void	error_protocol(void);
#endif
