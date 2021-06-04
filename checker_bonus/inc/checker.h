/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglorios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 14:23:09 by aglorios          #+#    #+#             */
/*   Updated: 2021/06/03 11:55:30 by aglorios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include "../../libft/inc/libft.h"
# include "../../inc/push_swap.h"
# include <stdio.h>

int		checker_algo(t_pile *pile);

int		get_next_linec(int fd, char **line);
int		ft_strlen2c(char *str);
int		is_linec(char *save);
void	norme_gnlc(char *reste, int i, int *j, char *new);

#endif
