/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:15:58 by emansoor          #+#    #+#             */
/*   Updated: 2024/01/20 10:03:30 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* copies n bytes from memory area from to memory area to */

void	*ft_memcpy(void *to, const void *from, size_t n)
{
	size_t	i;
	char	*dest;
	char	*src;

	if (to != 0 || from != 0)
	{
		i = 0;
		dest = (char *)to;
		src = (char *)from;
		while (i < n)
		{
			dest[i] = src[i];
			i++;
		}
	}
	return (to);
}
