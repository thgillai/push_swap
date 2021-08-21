/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 12:33:00 by thgillai          #+#    #+#             */
/*   Updated: 2021/08/21 17:15:30 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include <stdio.h>

void	check_arg_atoi(const char *str, int i)
{
	if (!ft_isdigit(str[i]))
		exit_error("Error\n");
}

int	ft_check(int neg, unsigned long int res)
{
	if (neg == -1 && res == 2147483648)
		return (0);
	exit_error("Error\n");
	return (0);
}

int	ft_atoi(const char *str)
{
	int					i;
	int					neg;
	unsigned long int	res;

	i = 0;
	neg = 1;
	res = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	check_arg_atoi(str, i);
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10 + str[i++] - '0';
	if (res >= 2147483648)
	{
		ft_check(neg, res);
	}
	return (res * neg);
}
