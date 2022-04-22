/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_id_in_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessamdi <oessamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 21:05:23 by oessamdi          #+#    #+#             */
/*   Updated: 2022/04/22 09:42:53 by oessamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_id(t_list **stack)
{
	t_list	*lst;
	int		size;
	int		i;
	int		*tab;

	i = 0;
	lst = *stack;
	size = lstsize(*stack);
	tab = malloc(sizeof(int) * size);
	tab = set_array(lst, tab);
	while (i < size)
	{
		while (lst)
		{
			if (lst->nb == tab[i])
			{
				lst->id = i;
				return ;
			}
			lst = lst->next;
		}
		i++;
	}
}
