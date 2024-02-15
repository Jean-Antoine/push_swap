/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 10:37:55 by jeada-si          #+#    #+#             */
/*   Updated: 2024/01/18 16:16:30 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_min_array_index(int *array, int size)
{
	int	i;
	int	min;

	min = 0;
	i = 0;
	while (++i < size)
		if (array[i] < array[min])
			min = i;
	return (min);
}

t_move	ft_count_moves(t_stack *node, t_stack *prev)
{
	t_move	move;
	int		count[4];

	move.rrfrom = node->rr;
	move.rfrom = node->r;
	move.rrto = prev->rr;
	move.rto = prev->r;
	move.rr = ft_min(move.rto, move.rfrom);
	move.rrr = ft_min(move.rrto, move.rrfrom);
	count[RTO_RFROM] = move.rto + move.rfrom;
	count[RTO_RRFROM] = move.rto + move.rrfrom;
	count[RRTO_RFROM] = move.rrto + move.rfrom;
	count[RRTO_RRFROM] = move.rrto + move.rrfrom;
	if (move.rto && move.rfrom)
		count[RTO_RFROM] -= move.rr;
	if (move.rrto && move.rrfrom)
		count[RRTO_RRFROM] -= move.rrr;
	move.min = ft_min_array(count, 4);
	move.seq = ft_min_array_index(count, 4);
	move.rrfrom *= (move.seq == RTO_RRFROM || move.seq == RRTO_RRFROM);
	move.rfrom *= (move.seq == RTO_RFROM || move.seq == RRTO_RFROM);
	move.rrto *= (move.seq == RRTO_RFROM || move.seq == RRTO_RRFROM);
	move.rto *= (move.seq == RTO_RFROM || move.seq == RTO_RRFROM);
	return (move);
}
