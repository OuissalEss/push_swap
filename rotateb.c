/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotateb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessamdi <oessamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 15:21:46 by oessamdi          #+#    #+#             */
/*   Updated: 2022/05/10 18:35:00 by oessamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotateb(t_list **head, int x)
{
	t_list	*h;
	t_list	*last;
	int		size;

	size = lstsize(*head);
	if (size > 1)
	{
		h = *head;
		last = lstlast(*head);
		last->next = *head;
		*head = h->next;
		h->next = NULL;
		if (x != 0)
			write(1, "rb\n", 3);
	}
}

void	rrotateb(t_list **head, int x)
{
	t_list	*last;
	t_list	*blast;
	int		size;

	size = lstsize(*head);
	if (size > 1)
	{
		last = lstlast(*head);
		blast = lstblast(*head);
		last->next = *head;
		*head = last;
		blast->next = NULL;
		if (x != 0)
			write(1, "rrb\n", 4);
	}
}
