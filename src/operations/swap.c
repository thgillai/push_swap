/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:23:31 by aglorios          #+#    #+#             */
/*   Updated: 2021/06/21 13:49:33 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	swap_ss(int *tab1, int *tab2, int len1, int len2)
{
	if (!swap(tab1, len1) || !swap(tab2, len2))
		return (0);
	return (1);
}

int	swap(int *tab, int len)
{
	int	tmp;

	tmp = 0;
	if (len < 1)
		return (0);
	tmp = tab[0];
	tab[0] = tab[1];
	tab[1] = tmp;
	return (1);
}
