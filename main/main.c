/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 13:15:10 by thgillai          #+#    #+#             */
/*   Updated: 2021/06/10 15:44:48 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	test(t_pile *pile)
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
	int		i;

	system("leaks push_swap");
	i = 1;
	pile = ft_calloc(1, sizeof(t_pile));
	data = ft_calloc(1, sizeof(t_data));
	if (ac < 2)
		exit_error("Error\n");
	if (ac == 2)
	{
		arg_is_str(av[1], pile);
		i = pile->arg_nb_a - 1;
		test(pile);
	//	printf("slt/n");
	}
	else
	{
		pile->a = malloc(sizeof(int *) * ac);
		if (!pile->a)
			return (0);
		while (i < ac)
			pile_arg(av[i++], pile);
		i -= 1;
		pile->a[i] = 0;
	}
	while (i != 0)
		pile_doublons(pile->a[--i], pile);
	algo_parse(pile, data);
	test(pile);
	free_struct(pile);
	return (0);
}