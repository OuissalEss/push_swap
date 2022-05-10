/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessamdi <oessamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 15:21:46 by oessamdi          #+#    #+#             */
/*   Updated: 2022/05/10 16:59:02 by oessamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotater(t_list **head_a, t_list **head_b)
{
	rotatea(head_a, 0);
	rotateb(head_b, 0);
	write(1, "rr\n", 3);
}

void	rrotater(t_list **head_a, t_list **head_b)
{
	rrotatea(head_a, 0);
	rrotateb(head_b, 0);
	write(1, "rrr\n", 4);
}
