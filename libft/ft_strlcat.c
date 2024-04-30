/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:43:33 by emansoor          #+#    #+#             */
/*   Updated: 2024/02/07 10:07:29 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* appends string "from" to the end of "to" */

size_t	ft_strlcat(char *to, const char *from, size_t to_size)
{
	size_t	dest_len;
	size_t	src_index;

	if (to_size)
	{
		if (to_size <= ft_strlen(to))
			return (ft_strlen(from) + to_size);
		dest_len = ft_strlen(to);
		src_index = 0;
		while (from[src_index] != '\0' && dest_len + src_index < to_size - 1)
		{
			to[dest_len + src_index] = from[src_index];
			src_index++;
		}
		to[dest_len + src_index] = '\0';
		return (ft_strlen(from) + dest_len);
	}
	return (ft_strlen(from));
}
