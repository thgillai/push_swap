/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 12:24:14 by aglorios          #+#    #+#             */
/*   Updated: 2021/06/10 20:00:49 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

/*void	test_pile(t_pile *pile)
{
	int	loop;
	int	i;

	i = 0;
	printf("\npile a : ");
	for (loop = 0; loop < pile->arg_nb_a; loop++)
		printf("%d ", pile->a[loop]);
	printf("\npile b : ");
	for (loop = 0; loop < pile->arg_nb_b; loop++)
		printf("%d ", pile->b[loop]);
	printf("\n");
}*/

int	main(int ac, char **av)
{
	t_pile	*pile;

	pile = ft_calloc(1, sizeof(t_pile));
	pile->count_arg = 1;
	if (ac < 2)
		exit_error("Error\n");
	if (!arg_to_pile(ac, av, pile))
		return (0);
	while (pile->count_arg != 0)
		pile_doublons(pile->a[--pile->count_arg], pile);
	checker_algo(pile);
	free_struct(pile);
	return (0);
}
