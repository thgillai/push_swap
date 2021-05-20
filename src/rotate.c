/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:43:48 by thgillai          #+#    #+#             */
/*   Updated: 2021/05/20 17:07:30 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	*ft_tabcpy(int *dest, int *src)
{
	size_t	i;
	size_t len;

	i = 0;
	len = 0;
	if (!src)
		return (0);
	while (src[len])
		len++;
	dest = malloc(sizeof(int *) * len);
	if (!dest)
		return (0);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

int	rotate(int *pile)
{
	int i;
	int j;
	int len;
	int *temp;

	i = 1;
	temp = ft_tabcpy(NULL, pile);
	if (!temp)
		return (0);
	j = 0;
	len = 0;
	while (pile[len])
		len++;
	while (temp[i])
	{
		pile[i++] = temp[j++];
	}
	pile[0] = temp[len - 1];
	return (1);
}

/*int	rev_rot(int *pile)
{
	int i;
	int j;
	int len;
	int *temp;

	i = 1;
	temp = ft_tabcpy(NULL, pile);
	if (!temp)
		return (0);
	j = 0;
	len = 0;
	while (pile[len])
		len++;
	while (temp[i])
	{
		pile[i++] = temp[j++];
	}
	pile[0] = temp[len - 1];
	return (1);
}	work in progress */
