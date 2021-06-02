/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 16:02:36 by thgillai          #+#    #+#             */
/*   Updated: 2021/06/02 16:04:33 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_row(int *tab, int find)
{
	int i;

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
	int		i;
	int		*dest;

//	printf("\nstart %i \n",start);
//	printf("\nend %i ", end);
//	printf("\nlen %i ",len);
//	printf("\nPILE COPY : ");
//	printf("\nsize : %i\n", end - start);
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
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	i = 0;
	while (i <= end - start)
		printf("end ncpy : %i ",dest[i++]);
//	printf("%i ",dest[i]);
//	printf("\n");
	return (dest);
}

int	occurence(int *tab, int nb, int len)
{
	int i;

	i = 0;

//	printf("\nnb = %i ",nb);
//	printf("\nlen = %i ",len);
	while (i < len)
	{
//		printf("\ntab : %i ",tab[i]);
		if (tab[i] == nb)
		{
//			printf("ok\n");
			return (1);
		}
		i++;
	}
//	printf("\nout occurence");
	return (0);
}
