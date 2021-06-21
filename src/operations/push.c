/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:33:56 by shenquin          #+#    #+#             */
/*   Updated: 2021/06/21 13:49:28 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	push_a(t_pile *pile)
{
	int	tmp;
	int	i;
	int	*tab_tmp;

	i = 0;
	tab_tmp = 0;
	if (pile->arg_nb_b)
	{
		tmp = pile->b[0];
		i = 1;
		while (i < pile->arg_nb_b)
		{
			tab_tmp = ft_addbacktab(tab_tmp, pile->b[i], i - 1);
			i++;
		}
		pile->a = addfronttab(pile->a, tmp, pile->arg_nb_a);
		free(pile->b);
		pile->b = ft_tabcpy(pile->b, tab_tmp, pile->arg_nb_b - 1);
		free(tab_tmp);
		pile->arg_nb_a += 1;
		pile->arg_nb_b -= 1;
	}
	return (0);
}

int	push_b(t_pile *pile)
{
	int	tmp;
	int	i;
	int	*tab_tmp;

	i = 0;
	tab_tmp = 0;
	if (pile->arg_nb_a)
	{
		tmp = pile->a[0];
		i = 1;
		while (i < pile->arg_nb_a)
		{
			tab_tmp = ft_addbacktab(tab_tmp, pile->a[i], i - 1);
			i++;
		}
		pile->b = addfronttab(pile->b, tmp, pile->arg_nb_b);
		free(pile->a);
		pile->a = ft_tabcpy(pile->a, tab_tmp, pile->arg_nb_a);
		free(tab_tmp);
		pile->arg_nb_b += 1;
		pile->arg_nb_a -= 1;
	}
	return (0);
}
