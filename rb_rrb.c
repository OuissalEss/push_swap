/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_rrb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessamdi <oessamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 21:42:55 by oessamdi          #+#    #+#             */
/*   Updated: 2022/05/10 21:43:13 by oessamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rb_or_rrb(t_list *sb, int n)
{
	int		i;
	int		size_b;
	t_list	*lst;

	i = 1;
	lst = sb;
	size_b = lstsize(sb);
	while (lst->nb != n)
	{
		i++;
		lst = lst->next;
	}
	if (i <= size_b / 2)
		return (1);
	return (2);
}
