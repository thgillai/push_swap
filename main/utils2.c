/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 14:40:46 by thgillai          #+#    #+#             */
/*   Updated: 2021/06/21 14:56:53 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	check_if_rien(char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (av[1][i])
	{
		if (av[1][i] != ' ')
			j++;
		i++;
	}
	if (j == 0)
		exit_error("Error\n");
}
