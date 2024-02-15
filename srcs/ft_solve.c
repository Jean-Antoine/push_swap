/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 12:10:08 by jeada-si          #+#    #+#             */
/*   Updated: 2024/01/19 10:18:27 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_solve_size_3(t_stack *stacks[2])
{
	int		value_1;
	int		value_2;
	int		value_3;

	value_1 = stacks[A]->value;
	value_2 = stacks[A]->next->value;
	value_3 = stacks[A]->next->next->value;
	if (ft_is_sorted_asc(stacks[A]))
		return ;
	if (value_1 < value_2 && value_2 > value_3 && value_3 < value_1)
		return (ft_rra(stacks, 1, 1));
	if (value_1 > value_2 && value_2 < value_3 && value_3 < value_1)
		return (ft_ra(stacks, 1, 1));
	if (value_1 < value_2 && value_2 > value_3 && value_3 > value_1)
		return (ft_rra(stacks, 1, 1), ft_sa(stacks, 1, 1));
	if (value_1 > value_2 && value_2 < value_3 && value_3 > value_1)
		return (ft_sa(stacks, 1, 1));
	if (value_1 > value_2 && value_2 > value_3 && value_3 < value_1)
		return (ft_sa(stacks, 1, 1), ft_rra(stacks, 1, 1));
}

static void	ft_get_smallest_on_top(t_stack *stacks[2])
{
	t_stack	*node;

	ft_set_moves_to_top(stacks[0]);
	node = stacks[0];
	while (node->index != 0)
		node = node->next;
	if (node->rr < node->r)
		return (ft_rra(stacks, node->rr, 1));
	ft_ra(stacks, node->r, 1);
}

void	ft_solve(t_stack *stacks[2])
{
	int		size;
	int		i;

	if (ft_is_sorted_asc(stacks[A]))
		return ;
	size = ft_get_size(stacks[0]);
	if (ft_get_size(stacks[A]) == 2)
		return (ft_putstr_fd("sa\n", 1));
	if (size == 3)
		return (ft_solve_size_3(stacks));
	if (size > 200)
		ft_push_quantiles(stacks, 8);
	else
	{
		i = 0;
		while (i++ < size - 3)
			ft_push_cheapest(B, stacks);
	}
	ft_solve_size_3(stacks);
	i = 0;
	while (stacks[1])
		ft_push_cheapest(A, stacks);
	ft_get_smallest_on_top(stacks);
}
