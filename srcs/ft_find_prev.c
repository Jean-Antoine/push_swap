/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_prev.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 10:35:08 by jeada-si          #+#    #+#             */
/*   Updated: 2024/01/18 16:17:05 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_find_prev(int index, t_stack *stack, int asc)
{
	while (1)
	{
		if (!asc && stack->index > index && index > stack->next->index)
			return (stack->next);
		else if (!asc && stack->index < stack->next->index)
		{
			if (stack->index > index)
				return (stack->next);
			else if (stack->next->index < index)
				return (stack->next);
		}
		if (asc && stack->index < index && index < stack->next->index)
			return (stack->next);
		else if (asc && stack->index > stack->next->index)
		{
			if (stack->index < index)
				return (stack->next);
			else if (stack->next->index > index)
				return (stack->next);
		}
		stack = stack->next;
	}
}
