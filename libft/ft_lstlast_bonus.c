/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:25:47 by emansoor          #+#    #+#             */
/*   Updated: 2024/04/12 09:51:45 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* returns the last node of a linked list */

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temp;

	if (lst)
	{
		temp = lst;
		while (temp->next)
			temp = temp->next;
		return (temp);
	}
	return (NULL);
}
