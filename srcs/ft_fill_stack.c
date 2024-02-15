/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 06:50:01 by jeada-si          #+#    #+#             */
/*   Updated: 2024/01/19 06:52:36 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_free(char **ss, int n)
{
	while (n--)
		free(ss[n]);
	free(ss);
}

void	ft_fill_stack(int ac, char **av, t_stack *stacks[2])
{
	char	**s;
	int		n;

	if (ac == 2)
	{
		s = ft_split(av[1], ' ');
		n = 0;
		while (s[n])
			n++;
		stacks[A] = ft_parse_args(n, s);
	}
	else
		stacks[A] = ft_parse_args(ac - 1, &av[1]);
	stacks[B] = NULL;
	if (ac == 2)
		ft_free(s, n);
	if (!stacks[A])
		exit(EXIT_FAILURE);
}
