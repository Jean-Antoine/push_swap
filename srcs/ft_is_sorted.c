/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:30:31 by jeada-si          #+#    #+#             */
/*   Updated: 2024/01/15 17:12:34 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted_asc(t_stack *stack)
{
	while (!stack->next->top)
	{
		if (stack->index > stack->next->index)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	ft_is_sorted_desc(t_stack *stack)
{
	while (!stack->next->top)
	{
		if (stack->index < stack->next->index)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	ft_is_sorted(t_stack *stack)
{
	return (ft_is_sorted_asc(stack) || ft_is_sorted_desc(stack));
}
