/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessamdi <oessamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 15:21:46 by oessamdi          #+#    #+#             */
/*   Updated: 2022/04/13 01:13:36 by oessamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotater(t_list **head_a, t_list **head_b)
{
	rotatea(head_a, 1);
	rotateb(head_b, 1);
}

void	rrotater(t_list **head_a, t_list **head_b)
{
	rrotatea(head_a, 1);
	rrotateb(head_b, 1);
}
