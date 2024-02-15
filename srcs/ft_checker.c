/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 08:05:54 by jeada-si          #+#    #+#             */
/*   Updated: 2024/01/19 09:24:45 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_checker_(t_stack *stacks[2], char *line)
{
	if (ft_strlen(line) == 3 && !ft_strncmp(line, "ra\n", 3))
		ft_ra(stacks, 1, 0);
	else if (ft_strlen(line) == 3 && !ft_strncmp(line, "rb\n", 3))
		ft_rb(stacks, 1, 0);
	else if (ft_strlen(line) == 3 && !ft_strncmp(line, "rr\n", 3))
		ft_rr(stacks, 1, 0);
	else if (ft_strlen(line) == 4 && !ft_strncmp(line, "rra\n", 4))
		ft_rra(stacks, 1, 0);
	else if (ft_strlen(line) == 4 && !ft_strncmp(line, "rrb\n", 4))
		ft_rrb(stacks, 1, 0);
	else if (ft_strlen(line) == 4 && !ft_strncmp(line, "rrr\n", 4))
		ft_rrr(stacks, 1, 0);
	else
	{
		free(line);
		ft_putstr_fd("Error\n", 2);
		exit (EXIT_FAILURE);
	}
}

void	ft_checker(t_stack *stacks[2])
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		if (ft_strlen(line) == 3 && !ft_strncmp(line, "sa\n", 3))
			ft_sa(stacks, 1, 0);
		else if (ft_strlen(line) == 3 && !ft_strncmp(line, "sb\n", 3))
			ft_sb(stacks, 1, 0);
		else if (ft_strlen(line) == 3 && !ft_strncmp(line, "ss\n", 3))
			ft_ss(stacks, 1, 0);
		else if (ft_strlen(line) == 3 && !ft_strncmp(line, "pb\n", 3))
			ft_pb(stacks, 1, 0);
		else if (ft_strlen(line) == 3 && !ft_strncmp(line, "pa\n", 3))
			ft_pa(stacks, 1, 0);
		else
			ft_checker_(stacks, line);
		free(line);
	}
	return ;
}
