/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessamdi <oessamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:22:11 by oessamdi          #+#    #+#             */
/*   Updated: 2022/04/22 10:15:46 by oessamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_b(t_list **stack_a, t_list **stack_b, t_list *top)
{
	int		middle;
	t_list	*sa_last;
	t_list	*sb_last;

	middle = lstsize(*stack_a) / 2;
	sb_last = lstlast(*stack_b);
	sa_last = lstlast(*stack_a);
	if (top->order != 0 && top->nb <= sa_last->nb)
		sort_big(stack_a, stack_b);
	while ((*stack_a)->nb != top->nb)
	{
		if (((*stack_b)->order == (*stack_a)->order + 1) || ((*stack_b)->order == 0))
			rotatea(stack_a, 1);
		else if (((*stack_a)->order == (*stack_a)->next->order + 1) 
				&& ((*stack_a)->next->order == sa_last->order + 1))
			swapa(stack_a, 1);
		else
			pushb(stack_a, stack_b);
	}
}

static void	push_a(t_list **stack_a, t_list **stack_b)
{
	int		middle;
	t_list	*sa_last;
	t_list	*sb_last;

	middle = lstsize(*stack_a) / 2;
	sb_last = lstlast(*stack_b);
	sa_last = lstlast(*stack_a);
	while (*stack_b)
	{
		printf("middle %d\n", middle);
		printf("iciii %d\n", (*stack_b)->nb);
		printf("iciii %d\n", (*stack_b)->next->id);
		printf("iciii %d\n", (*stack_a)->nb);
		printf("iciii %d\n", (*stack_a)->next->nb);
		printf("iciii %d\n", sa_last->nb);
		if (((*stack_b)->order == sa_last->order + 1) || ((*stack_a)->order == 0))
			rotatea(stack_a, 1);
		else if ((*stack_b)->order >= middle)
			pusha(stack_b, stack_a);
		else if (((*stack_b)->order == 0) || ((*stack_b)->order == sa_last->order + 1))
		{
			pusha(stack_b, stack_a);
			rotatea(stack_a, 1);
		}
		else if ((sb_last->order == 0) || (sb_last->order == sa_last->order + 1))
		{
			rrotateb(stack_b, 1);
			pusha(stack_b, stack_a);
			rotatea(stack_a, 1);
		}
		else
			rotateb(stack_b, 1);
	}
}

int	sort_big(t_list **stack_a, t_list **stack_b)
{
	int		min;
	int		middle;
	t_list	*top;

	min = 0;
	middle = lstsize(*stack_a) / 2;
	while (min < middle)
	{
		if ((*stack_a)->order < middle)
		{
			printf("push b : %d\n", (*stack_a)->nb);
			pushb(stack_a, stack_b);
			min++;
		}
		else
			rotatea(stack_a, 1);
	}
	if (stack_sorted(*stack_a) != 1 && *stack_b)
	{
		top = (*stack_a);
		push_a(stack_a, stack_b);
		put_id(stack_b);
		push_b(stack_a, stack_b, top);
	}
	return (0);
}
