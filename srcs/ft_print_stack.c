/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 09:57:14 by jeada-si          #+#    #+#             */
/*   Updated: 2024/01/19 07:12:42 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*ft_print_stack_(t_stack *stack)
{
	if (stack)
	{
		ft_printf("%-4d", stack->value);
		stack = stack->next;
		if (stack->top)
			stack = NULL;
	}
	else
		ft_printf("    ");
	return (stack);
}

void	ft_print_stacks(t_stack *stack[2])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = stack[0];
	stack_b = stack[1];
	while (stack_a || stack_b)
	{
		stack_a = ft_print_stack_(stack_a);
		stack_b = ft_print_stack_(stack_b);
		ft_printf("\n");
	}
	ft_printf("%-4c%-4c\n", '-', '-');
	ft_printf("%-4c%-4c\n", 'a', 'b');
	return ;
}
