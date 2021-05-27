/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenquin <shenquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:38:58 by shenquin          #+#    #+#             */
/*   Updated: 2021/05/27 16:43:37 by shenquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	pile_doublons(int arg, t_pile *pile)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < pile->arg_nb_a)
	{
		if (arg == pile->a[i])
			count++;
		i++;
	}
	if (count > 1)
		exit_error("Error\n");
}

void	pile_arg(char *arg, t_pile *pile)
{
	int	j;

	j = 0;
	while (arg[j])
	{
		if (!ft_isdigit(arg[j]))
			exit_error("Error\n");
		j++;
	}
	pile->a[pile->arg_nb_a] = ft_atoi(arg);
	if (pile->a[pile->arg_nb_a] < 0 || pile->a[pile->arg_nb_a] > 2147483647)
		exit_error("Error\n");
	pile->arg_nb_a++;
}

int	algo_main(t_pile *pile)
{
	if (pile->arg_nb_a <= 3)
		algo_3nba(pile->a, pile->arg_nb_a);
	if (pile->arg_nb_a <= 5 && pile->arg_nb_a >= 4)
		algo_5nb(pile);
	else
	{
		algo(pile);
	}
	return (0);
}
