/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:29:43 by emansoor          #+#    #+#             */
/*   Updated: 2024/02/07 10:12:29 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* returns a pointer to the last occurrence of the character
 * "chr" in the string "str" */

char	*ft_strrchr(const char *str, int chr)
{
	const char		*ptr;
	unsigned char	c;
	size_t			len;
	size_t			index;

	index = 0;
	ptr = 0;
	len = ft_strlen(str) + 1;
	c = (unsigned char)chr;
	while (index < len)
	{
		if (str[index] == c)
			ptr = str + index;
		index++;
	}
	return ((char *)ptr);
}
