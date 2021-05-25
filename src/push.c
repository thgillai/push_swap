/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:33:56 by shenquin          #+#    #+#             */
/*   Updated: 2021/05/25 11:47:25 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	push_a(t_pile *pile)
{
	int tmp;

	if (!pile->b)
		return(0);
	else
		tmp = pile->b[0];
		pile->a = ft_addbacktab(pile->a, tmp);
	return(0);
}

int	push_b(t_pile *pile)
{
	int tmp;

	if (!pile->a)
		return (0);
	else
		tmp = pile->a[0];
		pile->b = ft_addbacktab(pile->b, tmp);
	return(0);
}
