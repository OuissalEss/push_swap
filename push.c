/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessamdi <oessamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 15:21:46 by oessamdi          #+#    #+#             */
/*   Updated: 2022/04/09 21:55:24 by oessamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pusha(t_list *head1, t_list *head2)
{
	int		size;
	t_list	*h1;

	size = lstsize(head1);
	if (size > 1)
	{
		h1 = head1;
		head1 = h1->next;
		h1->next = head2;
		head2 = h1;
	}
	printf("pa\n");
}

void	pushb(t_list *head1, t_list *head2)
{
	int		size;
	t_list	*h1;

	size = lstsize(head1);
	if (size > 1)
	{
		h1 = head1;
		head1 = h1->next;
		h1->next = head2;
		head2 = h1;
	}
	printf("pb\n");
}
