/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 17:59:37 by thgillai          #+#    #+#             */
/*   Updated: 2021/06/10 19:34:05 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int opti_row(t_pile *pile, t_data *data)
{
	int opti;
	int row_f;
	int row_b;

	opti = 0;
	row_f = 0;
	row_b = 0;
	while (opti < pile->arg_nb_a)
	{
		if (occurence(data->refchunk, pile->a[0], data->chunk_size) == 1)
			row_f = opti;
		opti++;
	}
	opti = pile->arg_nb_a - 1;
	while (opti)
	{
		if (occurence(data->refchunk, pile->a[0], data->chunk_size) == 1)
			row_b = opti;
		opti--;
	}
	if (row_f < row_b)
		return (1) ;
	return (0);
}

int ft_pos(int *pile, int pos, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (pile[i] == pos)
			return (i);
		i++;
	}
	return (0);
}

int	push_to_a(t_pile *pile, t_data *data, int i)
{	
	while (pile->arg_nb_b)
	{
		data->max = ft_max(pile->b, pile->arg_nb_b);
		i = ft_pos(pile->b, data->max, pile->arg_nb_b);
		while (pile->b[0] != data->max)
		{
			if (i > pile->arg_nb_b / 2)
			{
				rot_rot(pile->b, pile->arg_nb_b);
				ft_putstr_fd("rrb\n", 1);
			}
			else
			{
				rotate(pile->b, pile->arg_nb_b);
				ft_putstr_fd("rb\n", 1);
			}
		}
		push_a(pile);
		ft_putstr_fd("pa\n", 1);
	}
	return (0);
}

int	push_to_b(t_pile *pile, t_data *data, int i, int j)
{
	int start;
	int end;

	start = ((data->refsize/ data->chunk_nb) * (j));
	end = ((data->refsize / data->chunk_nb) * (j + 1));
	data->chunk_size = end - start;
	i = data->chunk_size;
	data->refchunk = tabncpy(data->ref, start, end, data->refsize);

	while (i)
	{
		if (occurence(data->refchunk, pile->a[0], data->chunk_size) == 1)
		{
			push_b(pile);
			ft_putstr_fd("pb\n", 1);
			i--;
		}
		else if (i)
		{
			if (opti_row(pile, data))
			{
				rotate(pile->a, pile->arg_nb_a);
				ft_putstr_fd("ra\n", 1);
			}
			else
			{
				rot_rot(pile->a, pile->arg_nb_a);
				ft_putstr_fd("rra\n", 1);
			}
		}
	}

	return (0);
}

int	algo(t_pile *pile, t_data *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	data->ref = 0;
	data->ref = ft_tabcpy(data->ref, pile->a, pile->arg_nb_a);
	data->refsize = pile->arg_nb_a;
	bubble_sort(data->ref, pile->arg_nb_a);
	data->refchunk = 0;
	if (pile->arg_nb_a < 499)
		data->chunk_nb = 6;
	else
		data->chunk_nb = 12;
	data->chunk_size = pile->arg_nb_a / data->chunk_nb;
	while (j < data->chunk_nb)
	{
		push_to_b(pile, data, i, j);
		free(data->refchunk);
		j++;
	}
	while (pile->arg_nb_a)
	{
		push_b(pile);
		ft_putstr_fd("pb\n", 1);
	}
	push_to_a(pile, data, i);
	free(data->ref);
	return (0);
}
