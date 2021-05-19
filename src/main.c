/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 13:15:10 by thgillai          #+#    #+#             */
/*   Updated: 2021/05/19 15:41:29 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	test(int ac, t_pile *pile)
{
	int loop;

	ac = 0;
	printf("pile a : ");
	for(loop = 0; loop < 4 ; loop++)
		printf("%d ", pile->a[loop]);
	printf("\n");
	printf("pile b : ");
	for(loop = 0; loop < 4 ; loop++)
		printf("%d ", pile->b[loop]);
	printf("\n");
}

void	pile_arg(char *arg, t_pile *pile)
{
	int j;

	j = 0;
	while (arg[j])
	{
		if (!ft_isdigit(arg[j]))
			exit_error("Error\n");
		j++;
	}
	pile->a[pile->arg_nb_a] = ft_atoi(arg);
	if (pile->a[pile->arg_nb_a] < 0 || pile->a[pile->arg_nb_a] > 2147483647)
		exit_error("Error\n");
	pile->arg_nb_a++;
}

void	pile_doublons(int arg, t_pile *pile)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < pile->arg_nb_a)
	{
		if (arg == pile->a[i])
			count++;
		i++;
	}
	if (count > 1)
		exit_error("Error\n");
}

void	ft_freetab(char **tabs)
{
	int a;

	a = 0;
	while (tabs[a])
	{
		free(tabs[a]);
		tabs[a] = NULL;
		a++;
	}
	free(tabs);
	tabs = NULL;
}

void	arg_is_str(char *av, t_pile *pile)
{
	int		i;
	int		j;
	int		b;
	char	**str;

	i = 0;
	j = 0;
	b = 0;

	str = ft_split(av, ' ');
	while (str[b] != NULL)
		b++;
	while (i < (b - 1) && str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (!ft_isdigit(str[i][j++]))
				exit_error("Error\n");
		}
		i++;
	}
	pile->b = ft_calloc(b, sizeof(int *));
	pile->a = malloc(sizeof (int) * b);
	if (!pile->a)
		exit_error("Error\n");
	j = 0;
	i = 0;
	pile->arg_nb_a = b;
	while (b--)
		pile->a[j++] = ft_atoi(str[i++]);
	ft_freetab(str);
}

int	main(int ac, char **av)
{
	t_pile *pile;
	int	i;

	i = 1;
	pile = ft_calloc(1, sizeof(t_pile));
	if (ac < 2)
		exit_error("Error\n");
	if (ac == 2)
		arg_is_str(av[1], pile);
	else
	{
		pile->a = malloc(sizeof(int *) * ac);
		if (!pile->a)
			return (0);
		while (i < ac)
			pile_arg(av[i++], pile);
	}
	pile->b = ft_calloc(ac, sizeof(int *));
	while (i)
		pile_doublons(pile->a[i--], pile);
	test(ac - 1, pile);
	return (0);
}