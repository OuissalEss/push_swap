/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessamdi <oessamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 02:09:49 by oessamdi          #+#    #+#             */
/*   Updated: 2022/04/11 02:42:23 by oessamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_quick_sort(int *arr, int start, int end)
{
	int	n;

	if (start < end)
	{
		n = ft_partition(arr, start, end);
		ft_quick_sort(arr, start, n - 1);
		ft_quick_sort(arr, n + 1, end);
	}
}

int	ft_partition(int *arr, int start, int end)
{
	int	temp;
	int	comp;
	int	i;
	int	j;

	comp = arr[end];
	i = start - 1;
	j = start;
	while (j < end)
	{
		if (arr[j] <= comp)
		{
			i++;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
		j++;
	}
	temp = arr[i + 1];
	arr[i + 1] = arr[end];
	arr[end] = temp;
	return (i + 1);
}
