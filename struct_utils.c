/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:24:07 by emansoor          #+#    #+#             */
/*   Updated: 2024/04/30 10:29:37 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
creates a new node with given input
*/
t_cmds	*ft_lstnew_pipex(char **cmd, char *path)
{
	t_cmds	*new_node;

	new_node = malloc(sizeof(t_cmds));
	if (new_node)
	{
		new_node->command = cmd;
		new_node->path = full_path(path, cmd[0]);
		if (!new_node->path)
		{
			free(new_node);
			return (NULL);
		}
		new_node->c_pid = -1;
		new_node->fd_infile = -1;
		new_node->fd_outfile = -1;
		new_node->next = NULL;
		return (new_node);
	}
	perror("malloc");
	return (NULL);
}

/*
returns the number of nodes in lst
*/
int	ft_lstsize_pipex(t_cmds *lst)
{
	int	nodes;

	nodes = 0;
	while (lst)
	{
		lst = lst->next;
		nodes++;
	}
	return (nodes);
}

/*
returns the last node in lst
*/
t_cmds	*ft_lstlast_pipex(t_cmds *lst)
{
	t_cmds	*temp;

	if (lst)
	{
		temp = lst;
		while (temp->next)
			temp = temp->next;
		return (temp);
	}
	return (NULL);
}

/*
adds node new in the back of the list lst
*/
void	ft_lstadd_back_pipex(t_cmds **lst, t_cmds *new)
{
	t_cmds	*last;

	if (new)
	{
		if (*lst)
		{
			last = ft_lstlast_pipex(*lst);
			last->next = new;
		}
		else
			*lst = new;
	}
}

/*
frees a linked list
*/
void	ft_lstclear_pipex(t_cmds **lst, void (*del)(void*))
{
	t_cmds	*node;

	node = *lst;
	while (*lst)
	{
		*lst = (*lst)->next;
		free_array(node->command);
		(*del)(node->path);
		free(node);
		node = *lst;
	}
	*lst = NULL;
}
