/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessamdi <oessamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 15:21:46 by oessamdi          #+#    #+#             */
/*   Updated: 2022/04/13 02:44:33 by oessamdi         ###   ########.fr       */
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
	}
	if (x == 2)
		printf("sa\n");
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
	}
	if (x != 1)
		printf("sb\n");
}

void	swaps(t_list **head_a, t_list **head_b)
{
	swapa(head_a, 1);
	swapb(head_b, 1);
	printf("ss\n");
}
