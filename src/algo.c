/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:12:00 by thgillai          #+#    #+#             */
/*   Updated: 2021/06/10 16:01:25 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	test3(t_pile *pile)
{
	int	loop;

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

int	push_to_b(t_pile *pile, t_data *data, int i, int j)
{
	int start;
	int end;

	start = ((data->refsize/ data->chunk_nb) * (j));
	(void)j;
	end = ((data->refsize / data->chunk_nb) * (j + 1));
	data->chunk_size = end - start;
	i = data->chunk_size;
	data->refchunk = tabncpy(data->ref, start, end, data->refsize);
	while (i) // trouver la position de l occurence la plus proche et agir en fonction au lieu de tourner en rond ?
	{
		if (occurence(data->refchunk, pile->a[0], data->chunk_size) == 1)
		{
			push_b(pile);
			ft_putstr_fd("pb\n", 1);
			i--;
		}
		else if (i)
		{
			rotate(pile->a, pile->arg_nb_a);
			ft_putstr_fd("ra\n", 1);
		}
	}
	return (0);
}

int	push_to_a(t_pile *pile, t_data *data, int i)
{	
	while (pile->arg_nb_b) // je sais pas trop si on peut opti ici, plutot essayer d'avoir b un peu plus trier avant ?
	{
		data->max = ft_max(pile->b);
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

int	push_to_a_last_chunk(t_pile *pile, t_data *data, int i)
{	
	while (pile->arg_nb_b)
	{
		data->min = ft_max(pile->b);
		i = ft_pos(pile->b, data->min, pile->arg_nb_b);
		while (pile->b[0] != data->min)
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

/*int	last_chunk(t_pile *pile, t_data *data, int i)
{
	while (pile->a[0] != ft_min(pile->a))
	{
		push_b(pile);
		ft_putstr_fd("pb1\n", 1);
	}
	push_to_a_last_chunk(pile, data, i);
	data->min = ft_min(pile->a);
	i = ft_pos(pile->a, data->min, pile->arg_nb_a);
	while (pile->a[0] != ft_min(pile->a))
	{
		rotate(pile->a, pile->arg_nb_a);
		ft_putstr_fd("ra1\n", 1);
	}
	return (0);
}*/

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
