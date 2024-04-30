/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:25:11 by emansoor          #+#    #+#             */
/*   Updated: 2024/01/20 10:03:55 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* applies function "f" on each character of the string "s"
 * passed as argument, passing its index as first argument
 * each character is passed by address to "f" */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (s)
	{
		i = 0;
		while (s[i] != 0)
		{
			(*f)(i, &s[i]);
			i++;
		}
	}
}
