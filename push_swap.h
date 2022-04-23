/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessamdi <oessamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:54:12 by oessamdi          #+#    #+#             */
/*   Updated: 2022/04/23 18:17:26 by oessamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	int				nb;
	int				order;
	int				id;
	struct s_list	*next;
}					t_list;

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
void	swaps(t_list **stack_a, t_list **stack_b);
void	pusha(t_list **stack_b, t_list **stack_a);
void	pushb(t_list **stack_a, t_list **stack_b);
void	rotatea(t_list **stack_a, int x);
void	rotateb(t_list **stack_b, int x);
void	rotater(t_list **stack_a, t_list **stack_b);
void	rrotatea(t_list **stack_a, int x);
void	rrotateb(t_list **stack_b, int x);
void	rrotater(t_list **stack_a, t_list **stack_b);
void	ft_quick_sort(int *arr, int start, int end);
int		*set_array(t_list *stack_a, int *t);
int		error_msg(char *msg);
int		sort_three(t_list **stack_a);
int		sort_four(t_list **stack_a, t_list **stack_b);
int		sort_five(t_list **stack_a, t_list **stack_b);
int		sort_big(t_list **stack_a, t_list **stack_b);
int		sort_stack(t_list *stack_a, t_list *stack_b, int size);
int		stack_sorted(t_list *head);
void	put_id(t_list **stack);

#endif
