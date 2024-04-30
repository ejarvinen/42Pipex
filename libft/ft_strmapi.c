/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 09:54:26 by emansoor          #+#    #+#             */
/*   Updated: 2024/03/22 06:41:07 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* applies function "f" to each character of the string "s"
 * and passing its index as first argument to create a new string
 * resulting from applications of "f" */

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	index;
	char			*str;

	if (s)
	{
		str = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
		if (str)
		{
			index = 0;
			while (s[index] != 0)
			{
				str[index] = s[index];
				index++;
			}
			str[index] = '\0';
			index = 0;
			while (s[index] != 0)
			{
				str[index] = (*f)(index, str[index]);
				index++;
			}
			return (str);
		}
	}
	return (NULL);
}
