/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessamdi <oessamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 22:09:49 by oessamdi          #+#    #+#             */
/*   Updated: 2022/05/11 01:17:19 by oessamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_moves(t_list **sa, t_list **sb, char *move)
{
	if (ft_strncmp("sa\n", move, 3) == 0)
		swapa(sa, 0);
	else if (ft_strncmp("sb\n", move, 3) == 0)
		swapb(sb, 0);
	else if (ft_strncmp("ss\n", move, 3) == 0)
		swaps(sa, sb, 0);
	else if (ft_strncmp("pa\n", move, 3) == 0)
		pusha(sb, sa, 0);
	else if (ft_strncmp("pb\n", move, 3) == 0)
		pushb(sa, sb, 0);
	else if (ft_strncmp("ra\n", move, 3) == 0)
		rotatea(sa, 0);
	else if (ft_strncmp("rb\n", move, 3) == 0)
		rotateb(sb, 0);
	else if (ft_strncmp("rr\n", move, 3) == 0)
		rotater(sa, sb, 0);
	else if (ft_strncmp("rra\n", move, 4) == 0)
		rrotatea(sa, 0);
	else if (ft_strncmp("rrb\n", move, 4) == 0)
		rrotateb(sb, 0);
	else if (ft_strncmp("rrr\n", move, 4) == 0)
		rrotater(sa, sb, 0);
	else
		return (-1);
	return (1);
}

void	checker(t_list **stack_a, t_list **stack_b)
{
	int		cm;
	char	*move;

	move = get_next_line(0);
	while (move)
	{
		cm = check_moves(stack_a, stack_b, move);
		free(move);
		if (cm == -1)
		{
			write(2, "Error\n", 6);
			free_list(stack_a);
			free_list(stack_b);
			return ;
		}
		move = get_next_line(0);
	}
	if (stack_sorted(*stack_a) == 1 && *stack_b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_list(stack_a);
	free_list(stack_b);
}

int	main(int ac, char **av)
{
	t_vars	vars;
	t_list	*stack_a;
	t_list	*stack_b;

	stack_b = NULL;
	if (ac < 2)
		return (0);
	vars.size = init_list(&stack_a, ac, av);
	vars.tab = malloc(sizeof(int) * vars.size);
	if (vars.size == -1)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (check_duplication(stack_a, vars.tab) == -1)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	free(vars.tab);
	checker(&stack_a, &stack_b);
	return (0);
}
