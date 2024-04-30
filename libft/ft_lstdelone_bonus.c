/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:54:30 by emansoor          #+#    #+#             */
/*   Updated: 2024/02/05 10:06:13 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* frees the memory of a node's content using the function "del"
 * and then frees the node itself */

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst)
	{
		(*del)(lst->content);
		free(lst);
	}
}
