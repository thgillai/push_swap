/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 13:09:11 by thgillai          #+#    #+#             */
/*   Updated: 2021/05/20 16:41:16 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/inc/libft.h"
# include <stdio.h>

typedef struct s_pile
{
	int *a;
	int *b;
	int arg_nb_a;
	int arg_nb_b;
	char	*input;
	t_list	*stacka;
	t_list	*firsta;
	t_list	*stackb;
	t_list	*firstb;
}	t_pile;

void	exit_error();
void	*ft_calloc(size_t count, size_t size);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
int		swap(int *tab);
int		swap_ss(int *tab1, int *tab2);
int		rotate(int *pile);

#endif
