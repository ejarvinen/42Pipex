/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:33:15 by emansoor          #+#    #+#             */
/*   Updated: 2024/02/20 13:33:57 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* converts the letter "chr" to lowercase if possible */

int	ft_tolower(int chr)
{
	if (64 < chr && chr < 91)
		chr = chr + 32;
	return (chr);
}
