/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 19:03:38 by emansoor          #+#    #+#             */
/*   Updated: 2024/02/07 09:56:56 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* converts a number in int representation to string */

static int	num_length(long nbr)
{
	int	length;

	length = 0;
	if (nbr < 0)
	{
		nbr = nbr * (-1);
		length++;
	}
	while (nbr > 0)
	{
		nbr = nbr / 10;
		length++;
	}
	return (length + 1);
}

static int	converter(char *str, long nbr, int index)
{
	while (nbr > 0)
	{
		str[index] = (nbr % 10 + 48);
		nbr = nbr / 10;
		index--;
	}
	return (index);
}

char	*ft_itoa(int n)
{
	int		index;
	char	*str;
	int		digit_count;
	long	nbr;

	nbr = (long)n;
	if (nbr == 0)
		return (ft_strdup("0"));
	digit_count = num_length(nbr);
	str = (char *)malloc(sizeof(char) * digit_count);
	if (str)
	{
		index = 0;
		str[digit_count - 1] = '\0';
		if (nbr < 0)
		{
			str[index] = '-';
			nbr = nbr * (-1);
		}
		index = converter(str, nbr, digit_count - 2);
		return (str);
	}
	return (NULL);
}
