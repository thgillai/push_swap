/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 09:40:57 by thgillai          #+#    #+#             */
/*   Updated: 2021/05/22 09:41:17 by thgillai         ###   ########.fr       */
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