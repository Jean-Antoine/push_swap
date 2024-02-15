/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 10:02:06 by jeada-si          #+#    #+#             */
/*   Updated: 2024/01/18 14:57:02 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_is_valid_arg(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (!*str)
		return (0);
	while (*str)
		if (!ft_isdigit(*str++))
			return (0);
	return (1);
}

static int	ft_any_duplicate(int *vec, int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size - 1)
	{
		j = i;
		while (++j < size)
			if (vec[i] == vec[j])
				return (1);
	}
	return (0);
}

static void	ft_exit(t_stack *stack, int *values, int *index)
{
	if (stack)
		ft_free_stack(stack);
	if (values)
		free(values);
	if (index)
		free(index);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

static int	*ft_parse_to_int(int ac, char **av)
{
	int		*out;
	double	tmp;
	int		i;

	if (ac == 0)
		ft_exit(NULL, NULL, NULL);
	out = (int *)malloc(sizeof(int) * (ac));
	if (!out)
		exit(EXIT_FAILURE);
	i = -1;
	while (++i < ac)
	{
		if (!ft_is_valid_arg(av[i]))
			ft_exit(NULL, out, NULL);
		tmp = ft_atof(av[i]);
		if (tmp > INT_MAX || tmp < INT_MIN)
			ft_exit(NULL, out, NULL);
		out[i] = (int) tmp;
	}
	if (ft_any_duplicate(out, ac))
		ft_exit(NULL, out, NULL);
	return (out);
}

t_stack	*ft_parse_args(int ac, char **av)
{
	t_stack	*stack;
	t_stack	*node;
	int		*values;
	int		*index;
	int		i;

	values = ft_parse_to_int(ac, av);
	index = ft_get_sorted_index(values, ac);
	stack = ft_new_node(values[0], index[0], 1);
	if (!stack)
		ft_exit(stack, values, index);
	node = stack;
	i = 0;
	while (++i < ac)
	{
		node->next = ft_new_node(values[i], index[i], 0);
		if (!node->next)
			ft_exit(stack, values, index);
		node = node->next;
	}
	node->next = stack;
	free(values);
	free(index);
	return (stack);
}
