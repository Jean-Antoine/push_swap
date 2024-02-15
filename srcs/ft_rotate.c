/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 10:21:15 by jeada-si          #+#    #+#             */
/*   Updated: 2024/01/19 07:50:20 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rotate(t_stack **stack)
{
	if (!*stack)
		return ;
	(*stack)->top = 0;
	(*stack)->next->top = 1;
	*stack = (*stack)->next;
}

void	ft_ra(t_stack *stacks[2], int n, int print)
{	
	while (n--)
	{
		ft_rotate(&stacks[A]);
		if (print)
			ft_putstr_fd("ra\n", 1);
	}
}

void	ft_rb(t_stack *stacks[2], int n, int print)
{	
	while (n--)
	{
		ft_rotate(&stacks[B]);
		if (print)
			ft_putstr_fd("rb\n", 1);
	}
}

void	ft_rr(t_stack *stacks[2], int n, int print)
{
	while (n--)
	{
		ft_rotate(&stacks[B]);
		ft_rotate(&stacks[A]);
		if (print)
			ft_putstr_fd("rr\n", 1);
	}
}
