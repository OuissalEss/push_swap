/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessamdi <oessamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:22:11 by oessamdi          #+#    #+#             */
/*   Updated: 2022/04/19 21:00:03 by oessamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_msg(char *msg)
{
	printf("%s\n", msg);
	return (0);
}

int	sort_stack(t_list *stack_a, t_list *stack_b, int size)
{
	(void)stack_a;
	if (size == 1)
		return (0);
	if (size == 3)
		return (sort_three(&stack_a));
	if (size == 4)
		return (sort_four(&stack_a, &stack_b));
	if (size == 5)
		return (sort_five(&stack_a, &stack_b));
	else
		return (sort_big(&stack_a, &stack_b));
	return (0);
}

int	main(int ac, char **av)
{
	int		size;
	int		*tab;
	t_list	*stack_a;
	t_list	*stack_b;

	size = 1;
	stack_b = NULL;
	if (ac < 2)
		return (error_msg("Wrong number of arguments"));
	size = init_list(&stack_a, ac, av);
	tab = malloc(sizeof(int) * size);
	if (size == -1)
		return (error_msg("Error"));
	if (check_duplication(stack_a, tab) == -1)
		return (error_msg("Error"));
	put_order(&stack_a, tab);
	sort_stack(stack_a, stack_b, size);
	printf("sorted = %d\n", stack_sorted(stack_a));
	return (0);
}

// int	main(int ac, char **av)
// {
// 	int		size;
// 	int		*tab;
// 	t_list	*stack_a;
// 	t_list	*stack_b;
// 	t_list	**tmp;
// 	t_list	*head;

// 	size = 1;
// 	stack_b = NULL;
// 	if (ac < 2)
// 		return (error_msg("Wrong number of arguments"));
// 	size = init_list(&stack_a, ac, av);
// 	tab = malloc(sizeof(int) * size);
// 	printf("size : %d\n", size);
// 	if (size == -1)
// 		return (error_msg("Error"));
// 	if (check_duplication(stack_a, tab) == -1)
// 		return (error_msg("Error"));
// 	tmp = &stack_a;
// 	head = *tmp;
// 	printf("\n\n");
// 	put_order(&stack_a, tab);
// 	while(head)
// 	{
// 		printf("nb : %d order : %d\n", head->nb, head->order);
// 		head= head->next;
// 	}
// 	printf("\n\n");
// 	sort_stack(stack_a, stack_b, size);
// 	printf("\n\n");
// 	printf("sorted = %d", stack_sorted(stack_a));
// 	printf("\n\n");
// 	head = stack_a;
// 	while(head)
// 	{
// 		printf(" iciiii%d \n",head->nb);
// 		head= head->next;
// 	}
// }



// int	main(int ac, char **av)
// {
// 	int		size;
// 	int		*tab;
// 	t_list	*stack_a;
// 	t_list	*stack_b;
// 	t_list	*head;
// 	t_list	*headb;

// 	size = 1;
// 	stack_b = NULL;
// 	if (ac < 2)
// 		return (error_msg("Wrong number of arguments"));
// 	size = init_list(&stack_a, ac, av);
// 	tab = malloc(sizeof(int) * size);
// 	printf("size : %d\n", size);
// 	if (size == -1)
// 		return (error_msg("Error"));
// 	if (check_duplication(stack_a, tab) == -1)
// 		return (error_msg("Error"));
	
// 	head = stack_a;
// 	headb = stack_b;
	
// 	put_order(&stack_a, tab);
	
// 	while(head)
// 	{
// 		printf("stack a => nb : %d order : %d\n", head->nb, head->order);
// 		head= head->next;
// 	}
// 	while(headb)
// 	{
// 		printf("stack b => nb : %d order : %d\n", headb->nb, headb->order);
// 		headb= headb->next;
// 	}
	
// 	pushb(&stack_a, &stack_b);
// 	pushb(&stack_a, &stack_b);
// 	pushb(&stack_a, &stack_b);
// 	rotateb(&stack_b, 2);
// 	printf("\n");
// 	head = stack_a;
// 	headb = stack_b;
// 	while(head)
// 	{
// 		printf("stack a => nb : %d order : %d\n", head->nb, head->order);
// 		head= head->next;
// 	}
// 	while(headb)
// 	{
// 		printf("stack b => nb : %d order : %d\n", headb->nb, headb->order);
// 		headb= headb->next;
// 	}
	
// 	rrotateb(&stack_b, 2);
// 	printf("\n");
// 	head = stack_a;
// 	headb = stack_b;
// 	while(head)
// 	{
// 		printf("stack a => nb : %d order : %d\n", head->nb, head->order);
// 		head= head->next;
// 	}
// 	while(headb)
// 	{
// 		printf("stack b => nb : %d order : %d\n", headb->nb, headb->order);
// 		headb= headb->next;
// 	}
	
	
	// pushb(&stack_a, &stack_b);
	
	// printf("\n");
	// head = stack_a;
	// while(head)
	// {
	// 	printf("stack a => nb : %d order : %d\n", head->nb, head->order);
	// 	head= head->next;
	// }
	// printf("\n");

	// headb = stack_b;
	// while(headb)
	// {
	// 	printf("stack b => nb : %d order : %d\n", headb->nb, headb->order);
	// 	headb= headb->next;
	// }
	

	// pusha(&stack_b, &stack_a);

	
	// printf("\n");
	// head = stack_a;
	// while(head)
	// {
	// 	printf("stack a => nb : %d order : %d\n", head->nb, head->order);
	// 	head= head->next;
	// }
	// printf("\n");

	// headb = stack_b;
	// while(headb)
	// {
	// 	printf("stack b => nb : %d order : %d\n", headb->nb, headb->order);
	// 	headb= headb->next;
	// }
// }