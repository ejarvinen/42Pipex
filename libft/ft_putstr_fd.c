/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:48:14 by emansoor          #+#    #+#             */
/*   Updated: 2024/01/20 10:03:44 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* outputs string "s" to the given file descriptor */

void	ft_putstr_fd(char *s, int fd)
{
	unsigned int	i;

	if (s)
	{
		i = 0;
		while (s[i] != 0)
		{
			write(fd, &s[i], 1);
			i++;
		}
	}
}
