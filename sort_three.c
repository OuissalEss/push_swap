/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessamdi <oessamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:22:11 by oessamdi          #+#    #+#             */
/*   Updated: 2022/05/10 19:24:23 by oessamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **stack_a)
{
	while (stack_sorted(*stack_a) != 1)
	{
		if (((*stack_a)->nb > (*stack_a)->next->nb)
			&& ((*stack_a)->nb > (*stack_a)->next->next->nb))
			rotatea(stack_a, 1);
		if (((*stack_a)->nb < (*stack_a)->next->nb)
			&& ((*stack_a)->nb > (*stack_a)->next->next->nb))
			rrotatea(stack_a, 1);
		if ((((*stack_a)->nb < (*stack_a)->next->nb)
				&& ((*stack_a)->next->nb > (*stack_a)->next->next->nb))
			|| ((((*stack_a)->nb > (*stack_a)->next->nb)
					&& ((*stack_a)->next->nb < (*stack_a)->next->next->nb))))
			swapa(stack_a, 1);
	}
}
