/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:25:17 by jeada-si          #+#    #+#             */
/*   Updated: 2024/01/19 11:59:30 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stacks[2];

	if (ac == 1)
		return (0);
	ft_fill_stack(ac, av, stacks);
	ft_sa(stacks, 1, 1);
	ft_pb(stacks, 1, 1);
	ft_rrr(stacks, 1, 1);
	ft_free_stacks(stacks);
	return (0);
}
