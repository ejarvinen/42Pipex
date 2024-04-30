/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:22:10 by emansoor          #+#    #+#             */
/*   Updated: 2024/01/20 10:03:22 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* allocates and returns a new node
 * initializes parameter "content" with variable "content"
 * variable next is set to null */

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (new_node)
	{
		new_node->content = content;
		new_node->next = NULL;
		return (new_node);
	}
	return (NULL);
}
