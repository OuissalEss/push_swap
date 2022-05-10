/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessamdi <oessamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:22:11 by oessamdi          #+#    #+#             */
/*   Updated: 2022/05/10 19:50:34 by oessamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	print_stack(t_list *stack_a)
// {
// 	t_list	*sa;
	
// 	sa = stack_a;
// 	int i = 0;
// 	while (sa)
// 	{
// 		printf("%d = %d\n", i, sa->nb);
// 		sa = sa->next;
// 		i++;
// 	}
// }

int	sort_stack(t_list *stack_a, t_list *stack_b, t_vars	*vars)
{
	if (vars->size == 1)
		return (0);
	if (vars->size == 3)
		sort_three(&stack_a);
	else if (vars->size == 4)
		sort_four(&stack_a, &stack_b);
	else if (vars->size == 5)
		sort_five(&stack_a, &stack_b);
	else
		sort_big_stack(&stack_a, &stack_b, vars);
	free_list(&stack_a);
	return (0);
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
	put_order(&stack_a, vars.tab);
	sort_stack(stack_a, stack_b, &vars);
	return (0);
}
