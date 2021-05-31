/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglorios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 14:31:50 by aglorios          #+#    #+#             */
/*   Updated: 2021/05/31 16:16:11 by aglorios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

int ft_cmd(t_pile *pile, char *cmd)
{
	if (!(ft_strncmp(cmd, "sa", 3)))
		swap(pile->a);
	else if (!(ft_strncmp(cmd, "sb", 3)))
		swap(pile->b);
	else if (!(ft_strncmp(cmd, "ss", 3)))
		swap_ss(pile->a, pile->b);
	else if (!(ft_strncmp(cmd, "pa", 3)))
		write(1, "pa\n", 3);
	else if (!(ft_strncmp(cmd, "pb", 3)))
		write(1, "pb\n", 3);
	else if (!(ft_strncmp(cmd, "ra", 3)))
		write(1, "ra\n", 3);
	else if (!(ft_strncmp(cmd, "rb", 3)))
		write(1, "rb\n", 3);
	else if (!(ft_strncmp(cmd, "rr", 3)))
		write(1, "rr\n", 3);
	else if (!(ft_strncmp(cmd, "rra", 4)))
		write(1, "rra\n", 4);
	else if (!(ft_strncmp(cmd, "rrb", 4)))
		write(1, "rrb\n", 4);
	else if (!(ft_strncmp(cmd, "rrr", 4)))
		write(1, "rrr\n", 4);
	else
		return (0);
	return (1);
}

int	checker_algo(t_pile *pile)
{
	char *cmd;

	cmd = NULL;
	while (1)
	{
		if (get_next_linec(0, &cmd) != 0)
		{
			if (!ft_cmd(pile, cmd))
				break;
			free(cmd);
		}
	}
	if (is_sort(pile->a) == -1 || pile->arg_nb_b)
	{
		ft_putstr_fd("KO\n", 1);
		return (0);
	}
	ft_putstr_fd("OK\n", 1);
	return (1);
}
