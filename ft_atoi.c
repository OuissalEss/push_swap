/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessamdi <oessamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 18:49:56 by oessamdi          #+#    #+#             */
/*   Updated: 2022/05/10 21:27:22 by oessamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_min_max(char c, int sign, unsigned long res, int *checker)
{
	if (c != '\0' || (sign == 1 && res > 2147483647)
		|| (sign == -1 && res > 2147483648))
		*checker = -1;
}

int	ft_atoi(char const *str, int *checker)
{
	unsigned long	res;
	int				sign;
	int				i;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	if (str[i] == '\0')
		*checker = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + str[i] - '0';
		i++;
	}
	check_min_max(str[i], sign, res, checker);
	return ((int) res * sign);
}
