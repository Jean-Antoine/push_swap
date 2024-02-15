/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strppd_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:29:45 by jeada-si          #+#    #+#             */
/*   Updated: 2023/11/27 20:52:45 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strppd_c(char *str, char c)
{
	size_t	length;
	char	*out;

	length = ft_strlen(str);
	out = (char *)ft_calloc(length + 2, sizeof(char));
	*out = c;
	ft_strlcpy(&out[1], str, length + 1);
	free(str);
	return (out);
}
