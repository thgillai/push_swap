/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:33:56 by shenquin          #+#    #+#             */
/*   Updated: 2021/05/26 13:38:26 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	push_a(t_pile *pile)
{
	int	tmp;

	if (!pile->b)
		return (0);
	else
	{
		tmp = pile->a[0];
		if (pile->first_a_malloc == 0)
		{
			pile->a = malloc(sizeof(int) * 1);
			pile->first_a_malloc++;
		}
		pile->a = ft_addbacktab(pile->a, tmp);
	}
	return (0);
}

int	push_b(t_pile *pile)
{
	int	tmp;

	if (!pile->a)
		return (0);
	else
	{
		tmp = pile->a[0];
		if (pile->first_b_malloc == 0)
		{
			pile->b = malloc(sizeof(int) * 1);
			pile->first_b_malloc++;
		}
		pile->b = ft_addbacktab(pile->b, tmp);
	}
	return (0);
}
