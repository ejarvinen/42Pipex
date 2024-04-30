/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:49:51 by emansoor          #+#    #+#             */
/*   Updated: 2024/01/20 10:03:32 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* copies n bytes from memory area from to memory area to */

void	*ft_memmove(void *to, void *from, size_t n)
{
	char	*dest;
	char	*src;

	if (to != 0 || from != 0)
	{
		dest = (char *)to;
		src = (char *)from;
		if (dest < src)
			ft_memcpy(to, from, n);
		else
		{
			while (n > 0)
			{
				dest[n - 1] = src[n - 1];
				n--;
			}
		}
	}
	return (to);
}
