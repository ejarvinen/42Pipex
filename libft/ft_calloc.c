/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:11:40 by emansoor          #+#    #+#             */
/*   Updated: 2024/02/07 09:58:31 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* allocates memory for an array of nmemb elements of size bytes each and
 * returns a pointer to the allocated memory */

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr_to_mem;

	ptr_to_mem = malloc(nmemb * size);
	if (ptr_to_mem)
	{
		ft_bzero(ptr_to_mem, nmemb * size);
		return (ptr_to_mem);
	}
	return (0);
}
