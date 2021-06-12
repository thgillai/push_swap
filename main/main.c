/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 13:15:10 by thgillai          #+#    #+#             */
/*   Updated: 2021/06/12 12:49:35 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*void	test(t_pile *pile)
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
}*/

int	algo_parse(t_pile *pile, t_data *data)
{
	if (!is_sort(pile->a, pile->arg_nb_a))
		return (0);
	if (pile->arg_nb_a <= 3)
		algo_3nba(pile->a, pile->arg_nb_a);
	else if (pile->arg_nb_a <= 5 && pile->arg_nb_a >= 4)
		algo_5nb(pile);
	else
		algo(pile, data);
	return (0);
}

int	main(int ac, char **av)
{
	t_pile	*pile;
	t_data	*data;

	pile = ft_calloc(1, sizeof(t_pile));
	data = ft_calloc(1, sizeof(t_data));
	pile->count_arg = 1;
	if (ac < 2)
		exit_error("Error\n");
	if (!arg_to_pile(ac, av, pile))
		return (0);
	while (pile->count_arg != 0)
		pile_doublons(pile->a[--pile->count_arg], pile);
	algo_parse(pile, data);
	//test(pile);
	free_struct(pile);
	return (0);
}
