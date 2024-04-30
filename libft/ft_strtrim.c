/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 09:10:50 by emansoor          #+#    #+#             */
/*   Updated: 2024/02/07 10:16:11 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* allocates and returns a copy of "s1" with the characters
 * specified in "set" removed from the beginning and the end
 * of the string */

static char	*rtn_empty(void)
{
	char	*trim;

	trim = (char *)malloc(sizeof(char) * 1);
	if (!trim)
		return (NULL);
	trim[0] = '\0';
	return (trim);
}

static unsigned int	counter(char const *s1, char const *set, size_t slen)
{
	size_t			sindex;
	size_t			setindex;
	size_t			setlen;
	unsigned int	count;

	sindex = 0;
	setindex = 0;
	count = 0;
	setlen = ft_strlen(set);
	while (sindex < slen)
	{
		if (s1[sindex] != set[setindex] && setindex == setlen)
			break ;
		if (s1[sindex] == set[setindex])
		{
			count++;
			sindex++;
			setindex = -1;
		}
		setindex++;
	}
	return (count);
}

static size_t	length(char const *s1, char const *set, size_t slen)
{
	size_t	sindex;
	size_t	setindex;
	size_t	setlen;

	sindex = slen - 1;
	setindex = 0;
	setlen = ft_strlen(set);
	while (0 < sindex)
	{
		if (s1[sindex] != set[setindex] && setindex == setlen)
			break ;
		if (s1[sindex] == set[setindex])
		{
			slen--;
			sindex--;
			setindex = -1;
		}
		setindex++;
	}
	return (slen);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*trim;
	size_t			slen;
	unsigned int	count;

	if (s1)
	{
		slen = ft_strlen(s1);
		if (!slen)
		{
			if (set)
			{
				if (!ft_strlen(set))
					return (rtn_empty());
				return (rtn_empty());
			}
			return ((char *)s1);
		}
		count = counter(s1, set, slen);
		slen = length(s1, set, slen);
		if (count >= slen)
			return (rtn_empty());
		trim = ft_substr(s1, count, slen - count);
		return (trim);
	}
	return (NULL);
}
