/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessamdi <oessamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:22:11 by oessamdi          #+#    #+#             */
/*   Updated: 2022/04/16 02:10:13 by oessamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_five(t_list **stack_a, t_list **stack_b)
{
	int	pb;

	pb = 0;
	while (pb < 2)
	{
		if ((*stack_a)->order == 0 || (*stack_a)->order == 4)
		{
			pushb(stack_a, stack_b);
			pb++;
		}
		else
			rotatea(stack_a, 2);
	}
	sort_three(stack_a);
	while (pb > 0)
	{
		pusha(stack_b, stack_a);
		if ((*stack_a)->order == 4)
			rotatea(stack_a, 2);
		pb--;
	}
	return (0);
}
