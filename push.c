/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessamdi <oessamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 15:21:46 by oessamdi          #+#    #+#             */
/*   Updated: 2022/04/18 13:26:40 by oessamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pusha(t_list **stack_b, t_list **stack_a)
{
	int		size;
	t_list	*h1;

	size = lstsize(*stack_b);
	if (size > 0)
	{
		h1 = *stack_b;
		*stack_b = h1->next;
		h1->next = *stack_a;
		*stack_a = h1;
	}
	printf("pa\n");
}

void	pushb(t_list **stack_a, t_list **stack_b)
{
	int		size;
	t_list	*h1;

	size = lstsize(*stack_a);
	if (size > 0)
	{
		h1 = *stack_a;
		*stack_a = h1->next;
		h1->next = *stack_b;
		*stack_b = h1;
	}
	printf("pb\n");
}
