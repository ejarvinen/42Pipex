/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:59:52 by emansoor          #+#    #+#             */
/*   Updated: 2024/01/20 10:03:42 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* outputs integer "n" to the given file descriptor */

static void	reverse_write(char *narr, unsigned int j_ptr, int fd)
{
	while (j_ptr > 0)
	{
		write(fd, &narr[j_ptr - 1], 1);
		j_ptr--;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	long			i;
	char			arr[10];
	unsigned int	j;

	i = (long)n;
	j = 0;
	if (i < 0)
	{
		write(fd, "-", 1);
		i = i * (-1);
	}
	if (i == 0)
	{
		arr[j] = (i + 48);
		write(fd, &arr[0], 1);
	}
	while (i > 0)
	{
		arr[j] = (i % 10 + 48);
		i = i / 10;
		j++;
	}
	reverse_write(arr, j, fd);
}
