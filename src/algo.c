/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:12:00 by thgillai          #+#    #+#             */
/*   Updated: 2021/06/02 15:30:40 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	test3(t_pile *pile)
{
	int	loop;
	int	i;

	i = 0;
	printf("\npile a : ");
	if (pile->a)
	{
		for (loop = 0; loop < pile->arg_nb_a; loop++)
			printf("%d ", pile->a[loop]);
	}
	printf("\npile b : ");
	if (pile->b)
	{
		for (loop = 0; loop < pile->arg_nb_b; loop++)
			printf("%d ", pile->b[loop]);
	}
	printf("\n");
}

int ft_min_pos(int *pile, int min, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (pile[i] == min)
			return (i);
		i++;
	}
	return (0);
}

int ft_max_pos(int *pile, int max, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (pile[i] == max)
			return (i);
		i++;
	}
	return (0);
}

int	push_to_b(t_pile *pile, t_data *data, int i, int j)
{
	i = pile->arg_nb_a + 1;
	free(data->refchunk);
	data->refchunk = 0;
	printf("\nchunk_size : %i", data->chunk_size);
	data->chunk_size = 0;
	data->chunk_size = ((pile->arg_nb_a / data->chunk_nb) * (j + 1)) - ((pile->arg_nb_a / data->chunk_nb) * j);
	printf("\nchunk_size : %i", data->chunk_size);
	data->refchunk = tabncpy(data->ref, ((pile->arg_nb_a / data->chunk_nb) * j), ((pile->arg_nb_a / data->chunk_nb) * (j + 1)), pile->arg_nb_a);
	while (i--)
	{
//		test3(pile);
		if (occurence(data->refchunk, pile->a[0], data->chunk_size) == 1 )
		{
			push_b(pile);
			ft_putstr_fd("pb\n", 1);
		}
		else
		{
			rotate(pile->a);
			ft_putstr_fd("ra\n", 1);
		}
	}
	return (0);
}

int	fill_chunk(t_pile *pile, t_data *data, int i, int j)
{
	push_to_b(pile, data, i, j);
	while (pile->arg_nb_b)
	{
//		test3(pile);
		data->max = ft_max(pile->b);
		i = ft_max_pos(pile->b, data->min, pile->arg_nb_b);
//		printf("\nmin : %i", data->min);
//		printf("\npos : %i", pile->b[0]);
//		printf("\ni : %i", i);
		while (pile->b[0] != data->max)
		{
			if (i > pile->arg_nb_b / 2)
			{
				rot_rot(pile->b);
				ft_putstr_fd("rrb\n", 1);
			}
			else
			{
				rotate(pile->b);
				ft_putstr_fd("rb\n", 1);
			}
		}
		push_a(pile);
		ft_putstr_fd("pa\n", 1);
	}
	return (0);
}

int	algo(t_pile *pile)
{
	int i;
	int j;
	t_data *data;

	i = 0;
	j = 0;
	data = ft_calloc(1, sizeof(t_data));
	data->ref = NULL;
	data->ref = ft_tabcpy(data->ref, pile->a);
	bubble_sort(data->ref, pile->arg_nb_a);
	data->refchunk = 0;
	data->chunk_nb = 5;
	data->chunk_size = pile->arg_nb_a / data->chunk_nb;
	if (pile->arg_nb_a % data->chunk_size != 0)
		data->chunk_nb++;
	while (j < data->chunk_nb)
	{
		fill_chunk(pile, data, i, j);
		j++;
		test3(pile);
	}
	return (0);
}