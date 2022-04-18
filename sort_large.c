/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessamdi <oessamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:22:11 by oessamdi          #+#    #+#             */
/*   Updated: 2022/04/18 16:15:34 by oessamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_min_to_b(t_list **stack_a, t_list **stack_b)
{
	int	min;
	int	middle;

	min = 0;
	middle = (lstsize(*stack_a) - 1) / 2;
	while (min <= middle)
	{
		if ((*stack_a)->order <= middle)
		{
			pushb(stack_a, stack_b);
			min++;
		}
		else
			rotatea(stack_a, 2);
	}
}

void	push_max_to_b(t_list **stack_a, t_list **stack_b)
{
	int	middle;
	int	max;

	max = lstsize(*stack_a) - 1;
	middle = max / 2;
	while (max > middle)
	{
		if ((*stack_a)->order > middle)
		{
			pushb(stack_a, stack_b);
			max--;
		}
		else
			rotatea(stack_a, 2);
	}
}

void	push_min_to_a(t_list **stack_a, t_list **stack_b)
{
	int		min;
	int		middle;
	t_list	*sa_last;
	t_list	*sb_last;

	min = 0;
	middle = (lstsize(*stack_a) - 1) / 2;
	while (min <= middle)
	{
		sa_last = lstlast(*stack_a);
		while (((*stack_b)->order != 0) && ((*stack_b)->order != sa_last->order + 1))
		{
			sb_last = lstlast(*stack_b);
			if (((*stack_b)->order == 0) || ((*stack_b)->order != sa_last->order + 1))
				rrotateb(stack_b, 2);
			else
				rotateb(stack_b, 2);
		}
		pusha(stack_b, stack_a);
		min++;
		sb_last = lstlast(*stack_b);
		if (((*stack_b)->order != (*stack_a)->order + 1)
			&& (sb_last->order != (*stack_a)->order + 1))
			rotater(stack_a, stack_b);
		else
			rotatea(stack_a, 2);
		
	}
}

void	push_max_to_a(t_list **stack_a, t_list **stack_b)
{
	int		m;
	int		middle;
	int		max;
	t_list	*sa_last;
	t_list	*sb_last;
	t_list	*head;
	t_list	*headb;

	max = lstsize(*stack_a) - 1;
	m = max;
	middle = max / 2;
	while (m > middle)
	{
		sa_last = lstlast(*stack_a);
		while (((*stack_b)->order != max) && ((*stack_b)->order != (*stack_a)->order - 1) && ((*stack_b)->order != sa_last->order + 1))
		{
			sb_last = lstlast(*stack_b);
			sa_last = lstlast(*stack_a);
			if (sa_last->order == (*stack_a)->order - 1)
				rotatea(stack_a, 2);
			head = *stack_a;
			headb = *stack_b;
			while(head)
			{
				printf("stack a => nb : %d order : %d\n", head->nb, head->order);
				head= head->next;
			}
			printf("\n\n");
			while(headb)
			{
				printf("stack b => nb : %d order : %d\n", headb->nb, headb->order);
				headb= headb->next;
			}
			printf("max = %d\n", max);
			printf("stack b last = %d\nstack a = %d\nstack a last = %d\n\n", sb_last->order, (*stack_a)->order, sa_last->order);
			if ((sb_last->order == max) || (sb_last->order == (*stack_a)->order - 1) || (sb_last->order == sa_last->order + 1))
				rrotateb(stack_b, 2);
			else
				rotateb(stack_b, 2);
		}
		pusha(stack_b, stack_a);
		m--;
		sb_last = lstlast(*stack_b);
		while (sa_last->order == (*stack_a)->order - 1)
			rotatea(stack_a, 2);
	}
	while ((*stack_a)->order != 0)
		rotatea(stack_a, 2);
}

int	sort_large(t_list **stack_a, t_list **stack_b)
{
	push_min_to_b(stack_a, stack_b);
	push_min_to_a(stack_a, stack_b);
	push_max_to_b(stack_a, stack_b);
	push_max_to_a(stack_a, stack_b);
	return (0);
}
