/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_moves_to_top.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:45:47 by jeada-si          #+#    #+#             */
/*   Updated: 2024/01/18 16:13:26 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_moves_to_top(t_stack *stack)
{
	int	i;
	int	size;

	if (!stack)
		return ;
	size = ft_get_size(stack);
	stack->rr = 0;
	stack->r = 0;
	stack = stack->next;
	i = 1;
	while (!stack->top)
	{
		stack->r = i;
		stack->rr = size - i;
		stack = stack->next;
		i++;
	}
}
