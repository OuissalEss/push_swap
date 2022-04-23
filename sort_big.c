/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessamdi <oessamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:22:11 by oessamdi          #+#    #+#             */
/*   Updated: 2022/04/23 18:08:48 by oessamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_b(t_list **stack_a, t_list **stack_b, t_list *top)
{
	int		middle;
	t_list	*sa_last;
	t_list	*sb_last;

	middle = lstsize(*stack_b) / 2;
	sb_last = lstlast(*stack_b);
	sa_last = lstlast(*stack_a);
	if (top->order != 0 && top->nb <= sa_last->nb)
		sort_big(stack_a, stack_b);
	while ((*stack_a)->order != 0)
	{
		sb_last = lstlast(*stack_b);
		sa_last = lstlast(*stack_a);
		if (((*stack_a)->order == sa_last->order + 1) || ((*stack_a)->order == 0))
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
	while (*stack_b)
	{
		sb_last = lstlast(*stack_b);
		sa_last = lstlast(*stack_a);
		if ((((*stack_a)->order == sa_last->order + 1)
			|| ((*stack_a)->order == 0)) && (stack_sorted(*stack_a) != 1))
			rotatea(stack_a, 1);
		else if ((*stack_b)->order >= middle)
			pusha(stack_b, stack_a);
		else if (((*stack_a)->order == (*stack_a)->next->order + 1) 
				&& ((*stack_a)->next->order == sa_last->order + 1))
			swapa(stack_a, 1);
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

static void	sort_a(t_list **stack_a)
{
	int		middle;
	t_list	*sa_last;

	middle = lstsize(*stack_a) / 2;
	sa_last = lstlast(*stack_a);
	while ((((*stack_a)->order == sa_last->order + 1) || ((*stack_a)->order == 0)
			|| ((*stack_a)->next->order == sa_last->order + 1)) && (stack_sorted(*stack_a) != 1))
	{
		if ((*stack_a)->next->order == sa_last->order + 1)
			swapa(stack_a, 1);
		else
			rotatea(stack_a, 1);

		sa_last = lstlast(*stack_a);
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
			pushb(stack_a, stack_b);
			min++;
		}
		else
			rotatea(stack_a, 1);
	}
	while (stack_sorted(*stack_a) != 1 || *stack_b != NULL)
	{
		top = (*stack_a);
		push_a(stack_a, stack_b);
		sort_a(stack_a);
		put_id(stack_b);
		push_b(stack_a, stack_b, top);
	}
	return (0);
}
