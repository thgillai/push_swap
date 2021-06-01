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
	int *ref;
	t_data *data;

	i = 0;
	j = 0;
	data = ft_calloc(1, sizeof(t_data));
	ref = NULL;
	data->chunk_nb = 5;
	ref = ft_tabcpy(ref, pile->a);
	bubble_sort(ref, pile->arg_nb_a);
	data->chunk_size = pile->arg_nb_a / data->chunk_nb;
	if (pile->arg_nb_a % data->chunk_size != 0)
		data->chunk_nb++;
	while (j++ < data->chunk_nb)
	{
		while (i++ < pile->arg_nb_a)
		{
			if (pile->a[0] >= ref[(pile->arg_nb_a / data->chunk_nb) * j]
				&& pile->a[0] < ref[(pile->arg_nb_a / data->chunk_nb) * (j + 1)])
				push_b(pile);
			else
				rotate(pile->a);
		}
	}
	/*printf("\npile A: ");
	for (int loop = 0; loop < pile->arg_nb_a; loop++)
		printf("%i ", pile->a[loop]);
	printf("\npile B: ");
	for (int loop1 = 0; loop1 < pile->arg_nb_b; loop1++)
		printf("%i ", pile->a[loop1]);
	printf("\n");*/
	return (0);
}
