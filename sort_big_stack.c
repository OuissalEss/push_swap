/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessamdi <oessamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:54:11 by oessamdi          #+#    #+#             */
/*   Updated: 2022/05/11 00:47:35 by oessamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_to_b(t_list **sa, t_list **sb, t_vars *v)
{
	int	i;

	i = v->last + 1;
	while (--i >= v->first)
	{
		if (!(*sa))
			return ;
		if ((*sa)->nb == v->tab[i])
		{
			pushb(sa, sb, 1);
			if ((*sb)->nb <= v->tab[v->middle])
				rotateb(sb, 1);
			return ;
		}
	}
	rotatea(sa, 1);
}

static void	push_to_a2(t_list **sa, t_list **sb, t_vars *v)
{
	t_list	*sa_last;

	sa_last = lstlast(*sa);
	if (sa_last && (sa_last->nb == v->tab[v->last]
			|| sa_last->nb < (*sb)->nb))
	{
		pusha(sb, sa, 1);
		rotatea(sa, 1);
	}
	else
	{
		if (rb_or_rrb(*sb, v->tab[v->i]) == 1)
			rotateb(sb, 1);
		else
			rrotateb(sb, 1);
	}
}

static void	push_to_a(t_list **sa, t_list **sb, t_vars *v)
{
	t_list	*sa_last;

	v->i = v->last;
	while (*sb)
	{
		sa_last = lstlast(*sa);
		if ((*sb)->nb == v->tab[v->i])
		{
			pusha(sb, sa, 1);
			v->i--;
		}
		else if (sa_last && sa_last->nb == v->tab[v->i])
		{
			rrotatea(sa, 1);
			v->i--;
		}
		else
			push_to_a2(sa, sb, v);
	}
}

void	update_first_last(t_list **sb, t_vars *v)
{
	if (lstsize(*sb) == v->last - v->first)
	{
		v->first -= v->div;
		v->last += v->div;
	}
}

void	sort_big_stack(t_list **sa, t_list **sb, t_vars *v)
{
	if (v->size <= 155)
		v->div = v->size / 5;
	else
		v->div = v->size / 11;
	v->middle = v->size / 2;
	v->first = v->middle - v->div;
	v->last = v->middle + v->div;
	while (*sa)
	{
		if (v->first < 0 || v->last > v->size)
		{
			v->first = 0;
			v->last = v->size - 1;
		}
		push_to_b(sa, sb, v);
		update_first_last(sb, v);
	}
	push_to_a(sa, sb, v);
	while ((*sa)->order != 0)
		rrotatea(sa, 1);
}
