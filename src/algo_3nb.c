/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_3nb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 15:27:24 by thgillai          #+#    #+#             */
/*   Updated: 2021/05/26 16:45:15 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	max_handler(t_pile *pile)
{
	int	i;
	int	row;
	int	max;

	i = 0;
	row = 0;
	max = pile->a[i];
	while (pile->a[i])
	{
		if (max < pile->a[i])
		{
			max = pile->a[i];
			row = i;
		}
		i++;
	}
	if (row == 0)
	{
		rot_rot(pile->a);
		ft_putstr_fd("rra\n", 1);
	}
	if (row == 1)
	{
		rotate(pile->a);
		ft_putstr_fd("ra\n", 1);
	}
	return (0);
}

int	min_handler(t_pile *pile)
{
	int	i;
	int	row;
	int	min;

	i = 0;
	row = 0;
	min = pile->a[i];
	while (pile->a[i])
	{
		if (min > pile->a[i])
		{
			min = pile->a[i];
			row = i;
		}
		i++;
	}
	if (row == 1)
	{
		swap(pile->a);
		ft_putstr_fd("sa\n", 1);
	}
	return (0);
}

int	algo_3nb(t_pile *pile)
{
	if (pile->arg_nb_a == 1)
		return (0);
	if (pile->arg_nb_a == 2)
	{
		if (pile->a[0] > pile->a[1])
		{
			swap(pile->a);
			ft_putstr_fd("sa\n", 1);
		}
		else
			return (0);
	}
	if (pile->arg_nb_a == 3)
	{
		max_handler(pile);
		min_handler(pile);
	}
	return (0);
}
