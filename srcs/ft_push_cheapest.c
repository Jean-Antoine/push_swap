/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_cheapest.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:02:20 by jeada-si          #+#    #+#             */
/*   Updated: 2024/01/17 11:08:43 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_optimise_moves(t_move *move, t_stack *stacks[2])
{
	if (move->seq == RTO_RFROM && move->rto && move->rfrom)
	{
		ft_rr(stacks, move->rr, 1);
		move->rto -= move->rr;
		move->rfrom -= move->rr;
	}
	if (move->seq == RRTO_RRFROM && move->rrto && move->rrfrom)
	{
		ft_rrr(stacks, move->rrr, 1);
		move->rrto -= move->rrr;
		move->rrfrom -= move->rrr;
	}
}

static void	ft_push_to(int to, t_move move, t_stack *stacks[2])
{
	ft_optimise_moves(&move, stacks);
	ft_ra(stacks, (A == to) * move.rto, 1);
	ft_ra(stacks, (A == !to) * move.rfrom, 1);
	ft_rb(stacks, (B == to) * move.rto, 1);
	ft_rb(stacks, (B == !to) * move.rfrom, 1);
	ft_rra(stacks, (A == !to) * move.rrfrom, 1);
	ft_rra(stacks, (A == to) * move.rrto, 1);
	ft_rrb(stacks, (B == !to) * move.rrfrom, 1);
	ft_rrb(stacks, (B == to) * move.rrto, 1);
	if (to == A)
		ft_pa(stacks, 1, 1);
	else
		ft_pb(stacks, 1, 1);
}

void	ft_push_cheapest(int to, t_stack *stacks[2])
{
	t_stack	*node;
	t_stack	*prev;
	t_move	move_min;
	t_move	move;

	if (!stacks[to] || stacks[to]->next == stacks[to])
	{
		ft_pa(stacks, to == A, 1);
		return (ft_pb(stacks, to == B, 1));
	}
	ft_set_moves_to_top(stacks[A]);
	ft_set_moves_to_top(stacks[B]);
	node = stacks[!to];
	prev = ft_find_prev(node->index, stacks[to], to == A);
	move_min = ft_count_moves(node, prev);
	node = node->next;
	while (!node->top && move_min.min != 0)
	{
		prev = ft_find_prev(node->index, stacks[to], to == A);
		move = ft_count_moves(node, prev);
		if (move.min < move_min.min)
			move_min = move;
		node = node->next;
	}
	ft_push_to(to, move_min, stacks);
}
