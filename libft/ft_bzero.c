/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:32:36 by emansoor          #+#    #+#             */
/*   Updated: 2024/01/20 10:02:06 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* sets the first n bytes of area starting at s to zero */

void	ft_bzero(void *s, size_t n)
{
	char	*temp;

	temp = (char *)s;
	while (0 < n)
	{
		temp[n - 1] = '\0';
		n--;
	}
}
