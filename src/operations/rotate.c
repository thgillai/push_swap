/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:43:48 by thgillai          #+#    #+#             */
/*   Updated: 2021/06/21 13:49:31 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	rot_rot(int *tab, int len)
{
	int	i;
	int	j;
	int	*temp;

	i = 1;
	j = 0;
	temp = ft_tabcpy(NULL, tab, len);
	if (!temp)
		return (0);
	while (i < len)
	{
		tab[i++] = temp[j++];
	}
	tab[0] = temp[len - 1];
	free(temp);
	return (1);
}

int	rev_rot_rot(int *tab1, int *tab2, int len1, int len2)
{
	if (!rotate(tab1, len1) || !rotate(tab2, len2))
		return (0);
	return (1);
}

int	rotate(int *tab, int len)
{
	int	i;
	int	j;
	int	*temp;

	i = 1;
	j = 0;
	temp = ft_tabcpy(NULL, tab, len);
	if (!temp)
		return (0);
	while (i < len)
	{
		tab[j++] = temp[i++];
	}
	tab[j] = temp[0];
	free(temp);
	return (1);
}

int	rev_rot(int *tab1, int *tab2, int len1, int len2)
{
	if (!rot_rot(tab1, len1) || !rot_rot(tab2, len2))
		return (0);
	return (1);
}
