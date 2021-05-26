/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 16:30:48 by thgillai          #+#    #+#             */
/*   Updated: 2021/05/26 16:36:50 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	algo_main(t_pile *pile)
{
	if (pile->arg_nb_a <= 3)
		algo_3nb(pile);
	/*if (pile->arg_nb_a <= 5)
		algo_5nb(pile);
	else
	{
		// code
	}*/
	return (0);
}