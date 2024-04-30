/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:50:45 by emansoor          #+#    #+#             */
/*   Updated: 2024/02/07 10:02:49 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* return a pointer to the first occurrence of the
 * character "chr" in the string "str" */

char	*ft_strchr(const char *str, int chr)
{
	size_t			index;
	size_t			len;
	unsigned char	c;

	index = 0;
	c = (unsigned char)chr;
	len = ft_strlen(str) + 1;
	while (index < len)
	{
		if (str[index] == c)
			return ((char *)str + index);
		index++;
	}
	return (NULL);
}
