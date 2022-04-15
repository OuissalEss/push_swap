/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotateb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessamdi <oessamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 15:21:46 by oessamdi          #+#    #+#             */
/*   Updated: 2022/04/13 01:10:21 by oessamdi         ###   ########.fr       */
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
	}
	if (x != 1)
		printf("rb\n");
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
		blast = NULL;
	}
	if (x != 1)
		printf("rrb\n");
}
