/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 10:20:13 by jeada-si          #+#    #+#             */
/*   Updated: 2024/01/17 09:31:11 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_free_stack(t_stack *stack)
{
	t_stack	*tmp;

	if (!stack)
		return (NULL);
	stack = stack->next;
	while (!stack->top || !stack->next)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
	free(stack);
	return (NULL);
}

void	ft_free_stacks(t_stack *stacks[2])
{
	ft_free_stack(stacks[A]);
	ft_free_stack(stacks[B]);
}
