/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_quantiles.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 08:21:01 by jeada-si          #+#    #+#             */
/*   Updated: 2024/01/19 07:54:15 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_quantile(int value, int n, int size)
{
	int	i;

	i = 0;
	while (++i < n)
		if (value < (size * i / n))
			return (i);
	return (n);
}

static void	ft_set_quantiles(t_stack *stack, int size, int n)
{
	while (1)
	{
		stack->quantile = ft_quantile(stack->index, n, size);
		stack = stack->next;
		if (stack->top)
			return ;
	}
}

void	ft_push_quantiles(t_stack *stacks[2], int n)
{
	int		size;
	t_stack	*node;
	int		i;
	int		j;

	size = ft_get_size(stacks[A]);
	ft_set_quantiles(stacks[A], size, n);
	i = 0;
	while (++i <= n / 2)
	{
		j = size;
		while (j-- && size != 3)
		{
			node = stacks[A];
			if (node->quantile == i && size--)
				ft_pb(stacks, 1, 1);
			else if (node->quantile == n - i + 1 && size--)
			{
				ft_pb(stacks, 1, 1);
				ft_rb(stacks, 1, 1);
			}
			else
				ft_ra(stacks, 1, 1);
		}
	}
}
