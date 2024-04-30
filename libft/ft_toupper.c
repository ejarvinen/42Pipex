/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:28:24 by emansoor          #+#    #+#             */
/*   Updated: 2024/02/20 13:33:09 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* converts the letter "chr" to uppercase if possible */

int	ft_toupper(int chr)
{
	if (96 < chr && chr < 123)
		chr = chr - 32;
	return (chr);
}
