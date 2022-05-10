/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstfonctions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessamdi <oessamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 18:49:56 by oessamdi          #+#    #+#             */
/*   Updated: 2022/05/10 19:46:53 by oessamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lstsize(t_list *lst)
{
	t_list	*l;
	int		compteur;

	l = lst;
	compteur = 0;
	while (l)
	{
		l = l->next;
		compteur++;
	}
	return (compteur);
}

t_list	*lstlast(t_list *lst)
{
	t_list	*l;

	l = lst;
	if (l)
	{
		while (l->next)
			l = l->next;
	}
	return (l);
}

t_list	*lstblast(t_list *lst)
{
	t_list	*l;
	t_list	*bl;

	l = lst;
	bl = l;
	if (l)
	{
		while (l->next)
		{
			bl = l;
			l = l->next;
		}
	}
	return (bl);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*l;

	l = *lst;
	if (l)
	{
		while (l -> next)
			l = l -> next;
		l -> next = new;
	}
	else
		*lst = new;
}

void	free_list(t_list **head)
{
	t_list	*h;
	t_list	*l;

	h = *head;
	while (h)
	{
		l = h;
		h = h->next;
		free(l);
		l = NULL;
	}
}
