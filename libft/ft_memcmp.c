/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:06:44 by emansoor          #+#    #+#             */
/*   Updated: 2024/01/20 10:03:28 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* compares the first n bytes of the memory areas
 * buf1 and buf2 */

int	ft_memcmp(const void *buf1, const void *buf2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	if (n != 0)
	{
		i = 0;
		str1 = (unsigned char *)buf1;
		str2 = (unsigned char *)buf2;
		while (i < n)
		{
			if (str1[i] != str2[i])
				return (str1[i] - str2[i]);
			i++;
		}
	}
	return (0);
}
