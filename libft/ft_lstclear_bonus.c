/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 10:00:20 by emansoor          #+#    #+#             */
/*   Updated: 2024/04/07 09:14:16 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* deletes and frees every node in a linked list */
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*node;

	node = *lst;
	while (*lst)
	{
		*lst = (*lst)->next;
		(*del)(node->content);
		free(node);
		node = *lst;
	}
	*lst = NULL;
}
