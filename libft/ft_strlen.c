/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:26:24 by emansoor          #+#    #+#             */
/*   Updated: 2024/03/22 06:40:58 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* calculates the length of the string "str" */

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	if (str)
	{
		while (str[len] != 0)
			len++;
	}
	return (len);
}
