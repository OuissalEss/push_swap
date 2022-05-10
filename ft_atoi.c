/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessamdi <oessamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 18:49:56 by oessamdi          #+#    #+#             */
/*   Updated: 2022/05/10 19:07:45 by oessamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (str[i] != '\0' || (sign == 1 && res > 2147483647)
		|| (sign == -1 && res > 2147483648))
		*checker = -1;
	return ((int) res * sign);
}
