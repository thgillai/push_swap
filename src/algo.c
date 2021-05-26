/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:12:00 by thgillai          #+#    #+#             */
/*   Updated: 2021/05/26 18:34:14 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	find_min(t_pile *pile)
{
	int	i;
	int	min;

	i = 0;
	min = pile->a[i];
	while (pile->a[i])
	{
		if (pile->a[i] < min)
			min = pile->a[i];
		i++;
	}
	i = 0;
	while (pile->a[i])
	{
		if (min == pile->a[i++])
			break ;
	}
	while (i > 1)
	{
		rotate(pile->a);
		ft_putstr_fd("ra\n", 1);
		i--;
	}
	push_b(pile);
	ft_putstr_fd("pb\n", 1);
	return (0);
}

int	algo(t_pile *pile)
{
	int i;

	i = 0;
	while (pile->arg_nb_a)
		find_min(pile);
	while (pile->arg_nb_b)
	{
		push_a(pile);
		ft_putstr_fd("pa\n", 1);
	}
	return (0);
}
