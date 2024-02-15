/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 09:51:42 by jeada-si          #+#    #+#             */
/*   Updated: 2024/01/19 07:48:38 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*ft_swap(t_stack *stack)
{
	t_stack	*last;
	t_stack	*node;

	last = ft_get_last(stack);
	last->next = stack->next;
	node = stack;
	stack->top = 0;
	stack->next->top = 1;
	stack = stack->next;
	node->next = stack->next;
	stack->next = node;
	return (stack);
}

void	ft_sa(t_stack *stacks[2], int n, int print)
{	
	while (n--)
	{
		stacks[A] = ft_swap(stacks[A]);
		if (print)
			ft_putstr_fd("sa\n", 1);
	}
}

void	ft_sb(t_stack *stacks[2], int n, int print)
{	
	while (n--)
	{
		stacks[B] = ft_swap(stacks[B]);
		if (print)
			ft_putstr_fd("sb\n", 1);
	}
}

void	ft_ss(t_stack *stacks[2], int n, int print)
{
	while (n--)
	{
		stacks[A] = ft_swap(stacks[A]);
		stacks[B] = ft_swap(stacks[B]);
		if (print)
			ft_putstr_fd("ss\n", 1);
	}
}
