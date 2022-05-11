/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessamdi <oessamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:54:12 by oessamdi          #+#    #+#             */
/*   Updated: 2022/05/11 00:46:25 by oessamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_list
{
	int				nb;
	int				order;
	int				id;
	struct s_list	*next;
}					t_list;

typedef struct s_vars
{
	int		i;
	int		div;
	int		*tab;
	int		size;
	int		middle;
	int		first;
	int		last;
}			t_vars;

int		lstsize(t_list *lst);
t_list	*lstlast(t_list *lst);
t_list	*lstblast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_atoi(char const *str, int *checker);
void	free_list(t_list **head);
int		init_list(t_list **head, int ac, char **av);
int		put_order(t_list **stack_a, int *tab);
int		*sort_array(int *tab);
int		check_duplication(t_list *stack_a, int *tab);
void	swapa(t_list **stack_a, int x);
void	swapb(t_list **stack_b, int x);
void	swaps(t_list **stack_a, t_list **stack_b, int x);
void	pusha(t_list **stack_b, t_list **stack_a, int x);
void	pushb(t_list **stack_a, t_list **stack_b, int x);
void	rotatea(t_list **stack_a, int x);
void	rotateb(t_list **stack_b, int x);
void	rotater(t_list **stack_a, t_list **stack_b, int x);
void	rrotatea(t_list **stack_a, int x);
void	rrotateb(t_list **stack_b, int x);
void	rrotater(t_list **stack_a, t_list **stack_b, int x);
void	ft_quick_sort(int *arr, int start, int end);
int		*set_array(t_list *stack_a, int *t);
void	sort_two(t_list **stack_a);
void	sort_three(t_list **stack_a);
void	sort_four(t_list **stack_a, t_list **stack_b);
void	sort_five(t_list **stack_a, t_list **stack_b);
int		rb_or_rrb(t_list *sb, int n);
void	sort_big_stack(t_list **sa, t_list **sb, t_vars *vars);
int		sort_stack(t_list *stack_a, t_list *stack_b, t_vars	*vars);
int		stack_sorted(t_list *head);
void	put_id(t_list **stack);
char	*get_next_line(int fd);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
