/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:12:00 by thgillai          #+#    #+#             */
/*   Updated: 2021/05/26 13:00:27 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	find_min(t_pile *pile)
{
	int i;
	int min;

	i = 0;
	min = pile->a[i];
	while(pile->a[i])
	{
		if (pile->a[i] < min )
			min = pile->a[i];
		i++;
	}
	i = 0;
	while (pile->a[i])
	{
		if (min == pile->a[i])
			break ;
		i++;
	}
	while (i > 1)
	{
		rotate(pile->a);
		i--;
	}
	push_b(pile);
	return (0);
}

int algo(t_pile *pile)
{
	int loop;

	loop = pile->arg_nb_a;
	while (loop != 0)
	{
		find_min(pile);
		loop--;
	}
	return (0);
}
