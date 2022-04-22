/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessamdi <oessamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:22:11 by oessamdi          #+#    #+#             */
/*   Updated: 2022/04/22 08:58:51 by oessamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_four(t_list **stack_a, t_list **stack_b)
{
	while ((*stack_a)->order != 0 && (*stack_a)->order != 3)
		rotatea(stack_a, 1);
	pushb(stack_a, stack_b);
	sort_three(stack_a);
	pusha(stack_b, stack_a);
	if ((*stack_a)->order == 3)
		rotatea(stack_a, 1);
	return (0);
}
