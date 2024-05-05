/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:22:10 by emansoor          #+#    #+#             */
/*   Updated: 2024/05/03 08:13:41 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* returns a pointer to a new string which is a duplicate
 * of the string "str" */
char	*ft_strdup(const char *str)
{
	int		index;
	char	*ptr;

	index = 0;
	ptr = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (ptr)
	{
		while (str[index] != '\0')
		{
			ptr[index] = str[index];
			index++;
		}
		ptr[index] = '\0';
		return (ptr);
	}
	return (0);
}
