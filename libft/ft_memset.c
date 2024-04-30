/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:30:46 by emansoor          #+#    #+#             */
/*   Updated: 2024/01/20 10:03:35 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* fills the first n bytes of the memory area pointed to
 * by ptr with the constant byte x */

void	*ft_memset(void *ptr, int x, size_t n)
{
	size_t			i;
	char			*temp;
	unsigned char	c;

	i = 0;
	temp = (char *)ptr;
	c = (unsigned char)x;
	while (i < n)
	{
		temp[i] = c;
		i++;
	}
	return (ptr);
}
