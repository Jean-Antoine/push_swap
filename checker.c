/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 3034/01/19 07:14:49 by jeada-si          #+#    #+#             */
/*   Updated: 2024/01/19 11:55:03 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stacks[2];

	if (ac == 1)
		return (0);
	ft_fill_stack(ac, av, stacks);
	ft_checker(stacks);
	if (ft_is_sorted_asc(stacks[A]) && !stacks[B])
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	ft_print_stacks(stacks);
	ft_free_stacks(stacks);
	exit(EXIT_SUCCESS);
}
