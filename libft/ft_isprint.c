/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:12:48 by emansoor          #+#    #+#             */
/*   Updated: 2024/01/20 10:02:57 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* tests for any printing character, including space */

int	ft_isprint(int c)
{
	if ((31 < c) && (c < 127))
		return (1);
	return (0);
}
