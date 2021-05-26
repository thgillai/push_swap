/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenquin <shenquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:12:00 by thgillai          #+#    #+#             */
/*   Updated: 2021/05/26 16:37:33 by shenquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	test2(t_pile *pile)
{
	int	loop;
	int	i;

	i = 0;
	/*printf("pile a : ");
	for(loop = 0; loop < pile->arg_nb_a; loop++)
		printf("%d ", pile->a[loop]);
	if (!rot_rot(pile->a))
		exit_error("Error\n");
	if (!swap(pile->b))
		exit_error("Error\n");*/
	printf("pile a : ");
	for (loop = 0; loop < pile->arg_nb_a; loop++)
		printf("%d ", pile->a[loop]);
	printf("\npile b : ");
	while (pile->b && pile->b[i])
		i++;
	for (loop = 0; loop < i; loop++)
		printf("%d ", pile->b[loop]);
	printf("\n");
}

int	find_min(t_pile *pile)
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
	printf("min = %d\n", min);
	while (pile->a[i])
	{
		if (min == pile->a[i++])
			break ;
	}
	printf("\ni : %i\n", i);
	while (i > 1)
	{
		rot_rot(pile->a);
		printf("pilea[0] rot = %d\n", pile->a[0]);
		i--;
	}
	printf("pilea[0] = %d\n", pile->a[0]);
	push_b(pile);
	return (0);
}

int	algo(t_pile *pile)
{
//	int	loop;
	test2(pile);
	//int loop = pile->arg_nb_a;
	while (pile->arg_nb_a)
	{
//		push_b(pile);
		find_min(pile);
//		test2(pile);
		//loop--;
	}
	return (0);
}
