/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackfonctions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessamdi <oessamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 23:35:47 by oessamdi          #+#    #+#             */
/*   Updated: 2022/04/15 21:44:02 by oessamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_list(t_list **head, int ac, char **av)
{
	int		i;
	int		x;
	t_list	*new;

	i = 1;
	x = 0;
	*head = NULL;
	while (i < ac)
	{
		new = malloc(sizeof(t_list));
		if (!new)
			return (-1);
		new->element = ft_atoi(av[i], &x);
		new->next = NULL;
		ft_lstadd_back(head, new);
		if (x == -1)
		{
			free_list(head);
			*head = NULL;
			return (-1);
		}
		i++;
	}
	return (lstsize(*head));
}

void	search_change_order(t_list *stack_a, int x, int i)
{
	t_list	*lst;

	lst = stack_a;
	while (lst)
	{
		if (lst->element == x)
		{
			lst->order = i;
			return ;
		}
		lst = lst->next;
	}
}

int	put_order(t_list **stack_a, int *tab)
{
	int	size;
	int	i;

	i = 0;
	size = lstsize(*stack_a);
	while (i < size)
	{
		search_change_order(*stack_a, tab[i], i);
		i++;
	}
	return (1);
}

int	stack_sorted(t_list *head)
{
	t_list	*h;

	h = head;
	while (h && h->next)
	{
		if (h->element > h->next->element)
			return (-1);
		h = h->next;
	}
	return (1);
}
