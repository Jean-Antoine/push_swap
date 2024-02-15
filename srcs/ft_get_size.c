/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:37:21 by jeada-si          #+#    #+#             */
/*   Updated: 2024/01/15 17:12:34 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_size(t_stack *stack)
{
	int	i;

	if (!stack)
		return (0);
	if (stack->next == stack)
		return (1);
	i = 1;
	stack = stack->next;
	while (!stack->top && i++)
		stack = stack->next;
	return (i);
}
