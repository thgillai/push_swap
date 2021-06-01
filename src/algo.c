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

int	algo(t_pile *pile)
{
	int i;
	int j;
	int f;
	int *ref;
	t_data *data;

	i = 0;
	j = 0;
	data = ft_calloc(1, sizeof(t_data));
	ref = NULL;
	ref = ft_tabcpy(ref, pile->a);
	bubble_sort(ref, pile->arg_nb_a);
	data->chunk_size = pile->arg_nb_a / data->chunk_nb;
	if (pile->arg_nb_a % data->chunk_size != 0)
		data->chunk_nb++;
	while (j++ < data->chunk_nb)
	{
		while (pile->a[i++])
		{
			if (pile->a[i] >= ref[(pile->arg_nb_a / data->chunk_nb) * j]
				&& pile->a[i] < ref[(pile->arg_nb_a / data->chunk_nb) * (j + 1)])
				push_b(pile);
		}
	}

	return (0);
}
