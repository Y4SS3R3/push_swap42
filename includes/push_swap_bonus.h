/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymassiou <ymassiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 11:50:12 by ymassiou          #+#    #+#             */
/*   Updated: 2024/01/29 18:07:16 by ymassiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
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
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *haystack, int needle);
char	*ft_strdup(const char *str);
char	*ft_substr(const char *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
char	*get_next_line(int fd);
t_stack	*ft_parse(int argc, char **argv);
void	pb(t_stack **head_a, t_stack **head_b, int index);
void	pa(t_stack **head_a, t_stack **head_b, int index);
void	rra(t_stack **head, int state);
void	rrb(t_stack **head, int state);
void	rrr(t_stack **head_a, t_stack **head_b, int index);
void	ra(t_stack **head, int state);
void	rb(t_stack **head, int state);
void	rr(t_stack **head_a, t_stack **head_b, int index);
void	sa(t_stack **head, int state);
void	sb(t_stack **head, int state);
void	ss(t_stack **head_a, t_stack **head_b, int index);
void	ft_stackadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_stacklast(t_stack *lst);
t_stack	*ft_stacknew(int content);
int		ft_stacksize(t_stack *lst);
void	error_protocol(void);
int		ft_isdigit(int c);
long	ft_atoi(const char *str);
void	ft_putstr_fd(char *s, int fd);
void	free_stack(t_stack **stack, int index);
int		index_it(t_stack *head);
void	findex_it(t_stack *head, int size);
size_t	ft_strcmp(char *s1, char *s2);
int		more_sort(t_stack *stack, int size);
int		abs(int num);
int		ind_max_final(t_stack *stack);
int		is_sorted(t_stack *stack);
#endif
