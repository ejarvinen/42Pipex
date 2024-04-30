/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:33:45 by emansoor          #+#    #+#             */
/*   Updated: 2024/02/07 10:01:27 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* scans the initial n bytes of the memory area pointed
 * to by str for the first instance of chr */

void	*ft_memchr(const void *str, int chr, size_t n)
{
	unsigned char	c;
	size_t			index;
	unsigned char	*ptr;

	index = 0;
	ptr = (unsigned char *)str;
	c = (unsigned char)chr;
	while (index < n)
	{
		if (ptr[index] == c)
			return ((void *)str + index);
		index++;
	}
	return (0);
}
