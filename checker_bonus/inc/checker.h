/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenquin <shenquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 14:23:09 by aglorios          #+#    #+#             */
/*   Updated: 2021/06/15 13:59:01 by shenquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include "../../libft/inc/libft.h"
# include "../../inc/push_swap.h"

int		checker_algo(t_pile *pile);

int		get_next_linec(int fd, char **line);
int		ft_strlen2c(char *str);
int		is_linec(char *save);
void	norme_gnlc(char *reste, int i, int *j, char *new);

#endif
