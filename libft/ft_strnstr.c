/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:13:41 by emansoor          #+#    #+#             */
/*   Updated: 2024/02/07 10:11:49 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* finds the first occurrence of the substring needle in the string
 * hstack in at most len bytes */

char	*ft_strnstr(const char *hstack, const char *needle, size_t len)
{
	size_t	i_hstack;
	size_t	j_needle;

	i_hstack = 0;
	j_needle = 0;
	if (!len || !ft_strlen(hstack))
	{
		if (ft_strlen(needle) == 0)
			return ((char *)hstack);
		return (NULL);
	}
	while ((i_hstack + j_needle) <= len && hstack[i_hstack] != 0)
	{
		if (needle[j_needle] == 0)
			return ((char *)hstack + i_hstack);
		else if (hstack[i_hstack + j_needle] == needle[j_needle])
			j_needle++;
		else
		{
			i_hstack++;
			j_needle = 0;
		}
	}
	return (NULL);
}
