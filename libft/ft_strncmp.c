/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:23:38 by emansoor          #+#    #+#             */
/*   Updated: 2024/02/07 10:18:56 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* compares at most the first n bytes of two strings s1 and s2 */

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index;

	if (n)
	{
		index = 0;
		while (index < n && (s1[index] != 0 || s2[index] != 0))
		{
			if (s1[index] != s2[index])
				return ((unsigned char)s1[index] - (unsigned char)s2[index]);
			index++;
		}
		if (ft_strlen(s1) > 1 && ft_strlen(s2) > 1)
			return ((unsigned char)s1[index - 1]
				- (unsigned char)s2[index - 1]);
		else
			return ((unsigned char)s1[index] - (unsigned char)s2[index]);
	}
	return (0);
}
