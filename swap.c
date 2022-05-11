/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessamdi <oessamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 15:21:46 by oessamdi          #+#    #+#             */
/*   Updated: 2022/05/11 00:28:33 by oessamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swapa(t_list **head, int x)
{
	int		size;
	t_list	*h;

	size = lstsize(*head);
	if (size > 1)
	{
		h = *head;
		*head = h->next;
		h->next = h->next->next;
		(*head)->next = h;
		if (x != 0)
			write(1, "sa\n", 3);
	}
}

void	swapb(t_list **head, int x)
{
	int		size;
	t_list	*h;

	size = lstsize(*head);
	if (size > 1)
	{
		h = *head;
		*head = h->next;
		h->next = h->next->next;
		(*head)->next = h;
		if (x != 0)
			write(1, "sb\n", 3);
	}
}

void	swaps(t_list **head_a, t_list **head_b, int x)
{
	swapa(head_a, 0);
	swapb(head_b, 0);
	if (x != 0)
		write(1, "ss\n", 3);
}
