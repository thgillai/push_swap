/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norme_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenquin <shenquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 14:19:01 by thgillai          #+#    #+#             */
/*   Updated: 2021/06/15 13:58:58 by shenquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

void	norme_gnlc(char *reste, int i, int *j, char *new)
{
	while (reste[i + *j])
	{
		new[*j] = reste[i + *j];
		(*j)++;
	}
}
