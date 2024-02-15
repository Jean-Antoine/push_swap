/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 10:31:03 by jeada-si          #+#    #+#             */
/*   Updated: 2024/01/19 12:01:55 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_reverse_rotate(t_stack **stack)
{
	if (!*stack)
		return ;
	if ()
	*stack = ft_get_last(*stack);
	(*stack)->top = 1;
	(*stack)->next->top = 0;
}

void	ft_rra(t_stack *stacks[2], int n, int print)
{	
	while (n--)
	{
		ft_reverse_rotate(&stacks[A]);
		if (print)
			ft_putstr_fd("rra\n", 1);
	}
}

void	ft_rrb(t_stack *stacks[2], int n, int print)
{	
	while (n--)
	{
		ft_reverse_rotate(&stacks[B]);
		if (print)
			ft_putstr_fd("rrb\n", 1);
	}
}

void	ft_rrr(t_stack *stacks[2], int n, int print)
{
	while (n--)
	{
		ft_reverse_rotate(&stacks[B]);
		ft_reverse_rotate(&stacks[A]);
		if (print)
			ft_putstr_fd("rrr\n", 1);
	}
}
