/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 13:15:10 by thgillai          #+#    #+#             */
/*   Updated: 2021/05/17 14:44:13 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	check_arg(char *arg, t_pile pile)
{
	int j;

	j = 0;
	while (arg[j])
	{
		if (!ft_isdigit(arg[j]))
			exit_error("Error\n");
		j++;
	}
	pile.a[pile.arg_nb] = ft_atoi(arg);
	if (pile.a[pile.arg_nb] < 0 || pile.a[pile.arg_nb] > 2147483647)
		exit_error("Error\n");
	pile.arg_nb++;
}

void	check_doublons(char *arg, char **array)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (array[i])
	{
		if (ft_strcmp(arg, array[i]) == 0)
			count++;
		i++;
	}
	if (count > 1)
		exit_error("Error\n");
}

int	main(int ac, char **av)
{
	t_pile *pile;
	int	i;

	i = 1;
	pile = ft_calloc(1, sizeof(t_pile));
	pile->a = malloc(sizeof(int) * ac);
	if (!pile->a)
		return (0);
	if (ac < 2)
		exit_error("Error\n");
	while (av[i])
	{
		check_arg(av[i], *pile);
		check_doublons(av[i], av);
		i++;
	}
	return (0);
}
