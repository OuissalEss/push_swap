/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrayfonctions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessamdi <oessamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 23:30:21 by oessamdi          #+#    #+#             */
/*   Updated: 2022/04/22 09:40:43 by oessamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*set_array(t_list *stack_a, int *t)
{
	t_list	*lst;
	int		i;

	i = 0;
	lst = stack_a;
	while (lst)
	{
		t[i] = lst->nb;
		lst = lst->next;
		i++;
	}
	return (t);
}

int	check_duplication(t_list *stack_a, int *tab)
{
	int	i;
	int	size;

	i = 0;
	size = lstsize(stack_a);
	tab = set_array(stack_a, tab);
	ft_quick_sort(tab, 0, size - 1);
	i = 0;
	while (i < size - 1)
	{
		if (tab[i] == tab[i + 1])
			return (-1);
		i++;
	}
	return (1);
}
