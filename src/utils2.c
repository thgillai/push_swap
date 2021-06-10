/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 16:02:36 by thgillai          #+#    #+#             */
/*   Updated: 2021/06/10 20:13:14 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_row(int *tab, int find)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (tab[i] == find)
			return (i);
		i++;
	}
	return (0);
}

int	*tabncpy(int *src, int start, int end, int len)
{
	int	i;
	int	a;
	int	*dest;

	dest = 0;
	a = 0;
	i = 0;
	if (!src || start < 0 || start > end || end > len)
		return (0);
	if (end > len)
		end = len;
	dest = malloc(sizeof(int *) * (end - start));
	if (!dest)
		return (0);
	i = start;
	while (i < end)
	{
		dest[a++] = src[i];
		i++;
	}
	dest[a] = 0;
	return (dest);
}

int	occurence(int *tab, int nb, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (tab[i] == nb)
			return (1);
		i++;
	}
	return (0);
}
