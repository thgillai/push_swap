/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_5nb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 18:19:44 by thgillai          #+#    #+#             */
/*   Updated: 2021/05/26 21:30:06 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	test2(t_pile *pile)
{
	int	loop;
	int	i;

	i = 0;
	printf("pile a : ");
	if (pile->a)
	{
		for (loop = 0; loop < pile->arg_nb_a; loop++)
			printf("%d ", pile->a[loop]);
	}
	printf("\npile b : ");
	if (pile->b)
	{
		while (pile->b[i])
			i++;
		for (loop = 0; loop < i; loop++)
			printf("%d ", pile->b[loop]);
	}
	printf("\n");
}

int algo_5nb(t_pile *pile)
{
	int	i;
	int min;
	int row;

	i = 0;
	min = 0;
	row = 0;
	if (pile->arg_nb_a == 5)
	{
		while(i < 2)
		{
			push_b(pile);
			ft_putstr_fd("pb\n", 1);
			i++;
		}
		algo_3nba(pile->a, 3);
		ft_putstr_fd("\ntwo pile nb5 :\n", 1);
		test2(pile);
		ft_putstr_fd("_____________\n", 1);
		while (pile->arg_nb_b)
		{
			i = 0;
			min = pile->b[0];
			printf("\nmin : %i\n", min);
			while (pile->a[i])
			{
				if (pile->a[i] > pile->b[0])
				{
					printf("\npile[i] : %i\n", pile->a[i]);
					if (min < pile->a[i])
					{
//						min = pile->a[i];
						row = i;
						break;
					}
				}
				i++;
			}
			printf("\nrow : %i\n", row);
			if (row == 0 && pile->a[0] < pile->b[0])
			{
				i = 0;
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
				if (row <= 3)
				{
					while (row--)
					{
						ft_putstr_fd("ra\n", 1);
					rotate(pile->a);
					}
				}
				if (row > 3)
				{					
					while (!(pile->a[0] == min))
					{
						ft_putstr_fd("rra\n", 1);
						rot_rot(pile->a);
					}
				}
			}
			if (row == 1)
			{
				rotate(pile->a);
				ft_putstr_fd("ra\n", 1);
			}
			if (row == 2)
			{
				rot_rot(pile->a);
				ft_putstr_fd("rra\n", 1);
			}
			if (row == 2 && pile->arg_nb_a == 4)
			{
				rot_rot(pile->a);
				ft_putstr_fd("rra\n", 1);
			}
			row = 0;
			push_a(pile);
			ft_putstr_fd("pa\n", 1);
		}
		i = 0;
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
		if (row <= 3)
		{
			while (row--)
			{
				ft_putstr_fd("ra\n", 1);
				rotate(pile->a);
			}
		}
		if (row > 3)
		{
			while (!(pile->a[0] == min))
			{
				ft_putstr_fd("rra\n", 1);
				rot_rot(pile->a);
			}
		}
	}
//	ft_putstr_fd("\nfin algo nb 5 :\n", 1);
//	test2(pile);
//	ft_putstr_fd("_____________\n", 1);
	return (0);
}
