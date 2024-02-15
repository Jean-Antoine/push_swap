/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:00:53 by jeada-si          #+#    #+#             */
/*   Updated: 2024/01/19 07:49:45 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_push(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*to_push;

	to_push = *stack_b;
	to_push->top = 1;
	if (*stack_b == (*stack_b)->next)
		*stack_b = NULL;
	else
	{
		ft_get_last(*stack_b)->next = (*stack_b)->next;
		*stack_b = (*stack_b)->next;
		(*stack_b)->top = 1;
	}
	if (!*stack_a)
	{
		*stack_a = to_push;
		(*stack_a)->next = *stack_a;
	}
	else
	{
		ft_get_last(*stack_a)->next = to_push;
		to_push->next = *stack_a;
		(*stack_a)->top = 0;
		*stack_a = to_push;
	}
}

void	ft_pa(t_stack *stacks[2], int n, int print)
{
	if (!stacks[1])
		return ;
	while (n--)
	{
		ft_push(&stacks[A], &stacks[B]);
		if (print)
			ft_putstr_fd("pa\n", 1);
	}	
}

void	ft_pb(t_stack *stacks[2], int n, int print)
{
	if (!stacks[0])
		return ;
	while (n--)
	{
		ft_push(&stacks[B], &stacks[A]);
		if (print)
			ft_putstr_fd("pb\n", 1);
	}	
}
