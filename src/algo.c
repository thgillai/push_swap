/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:12:00 by thgillai          #+#    #+#             */
/*   Updated: 2021/06/01 16:49:18 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*int	find_min(t_pile *pile)
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
	int	i;

	i = 0;
	while (pile->arg_nb_a)
		find_min(pile);
	while (pile->arg_nb_b)
	{
		push_a(pile);
		ft_putstr_fd("pa\n", 1);
	}
	return (0);
}*/

int	fill_chunk(t_pile *pile, t_data *data)
{
	int i;

	i = 0;
	data->min = ft_min(pile->a);
	while (i < pile->arg_nb_a)
	{
		if (data->min == pile->a[i])
		{
			data->row = i;
			break ;
		}
		i++;
	}
	i = 0;
	if (data->row > pile->arg_nb_a / 2)
	{
		while (data->row < pile->arg_nb_a)
		{
			rot_rot(pile->a);
			ft_putstr_fd("rra", 1);
			data->row++;
		}
		rot_rot(pile->a);
		ft_putstr_fd("rra", 1);
	}
	else
	{
		while (data->row)
		{
			rotate(pile->a);
			ft_putstr_fd("ra", 1);
			data->row--;
		}
	}
	push_b(pile);
	return (0);
}

// Work inprogress


int	algo(t_pile *pile)
{
	int i;
	int *ref;
	t_data *data;

	i = 0;
	data = ft_calloc(1, sizeof(t_data));
	ref = NULL;
	ref = ft_tabcpy(ref, pile->a);
	bubble_sort(ref, pile->arg_nb_a);
	data->chunk_size = pile->arg_nb_a / 5;
	if (pile->arg_nb_a % data->chunk_size != 0)
		data->chunk_nb++;
	while (data->chunk_nb < 5)
	{
		while (pile->a[i])
		{
			if ((ref[0] <= pile->a[i]) &&
				pile->a[i] <= ref[pile->arg_nb_a / data->chunk_nb - 1])
				push_b(pile);
			i++;
		}
		data->chunk_nb++;
	}
	return (0);
}
