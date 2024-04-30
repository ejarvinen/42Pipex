/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:56:58 by emansoor          #+#    #+#             */
/*   Updated: 2024/01/20 10:02:26 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* tests for any uppercase or lowercase character */

int	ft_isalpha(int c)
{
	if ((96 < c && c < 123) || (64 < c && c < 91))
		return (1);
	return (0);
}
