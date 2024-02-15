/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_sorted_index.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:30:09 by jeada-si          #+#    #+#             */
/*   Updated: 2024/01/15 17:17:12 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap_values(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int	*ft_quick_sort_index(int *vec, int size)
{
	int	*index;
	int	i;
	int	j;

	index = (int *)malloc(sizeof(int) * size);
	if (!index)
	{
		free(vec);
		exit(EXIT_FAILURE);
	}
	i = -1;
	while (++i < size)
		index[i] = i;
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size - 1)
			if (vec[index[j]] > vec[index[j + 1]])
				ft_swap_values(&index[j], &index[j + 1]);
	}
	return (index);
}

int	*ft_get_sorted_index(int *vec, int size)
{
	int	*index;
	int	*out;
	int	i;

	index = ft_quick_sort_index(vec, size);
	out = (int *)malloc(sizeof(int) * size);
	if (!out)
	{
		free(vec);
		free(index);
		exit(EXIT_FAILURE);
	}
	i = -1;
	while (++i < size)
	{
		out[index[i]] = i;
	}
	free(index);
	return (out);
}
