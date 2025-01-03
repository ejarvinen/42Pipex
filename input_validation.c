/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:30:06 by emansoor          #+#    #+#             */
/*   Updated: 2024/05/05 13:56:54 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
constructs a full path
*/
char	*full_path(char *path, char *command)
{
	char	*temp;
	char	*full_path;

	temp = ft_strjoin(path, "/");
	if (!temp)
		return (NULL);
	full_path = ft_strjoin(temp, command);
	if (!path)
	{
		free(temp);
		return (NULL);
	}
	free(temp);
	return (full_path);
}

/*
checks whether the calling process can access path for a given command;
returns index for accessible path in paths, -1 if path not found,
-2 if given command is an absolute path
*/
static int	validate_command(char *command, char **paths)
{
	char	*path;
	int		index;

	if (access(command, F_OK) == 0)
		return (-2);
	index = 0;
	while (paths[index])
	{
		path = full_path(paths[index], command);
		if (!path)
			break ;
		if (access(path, F_OK) == 0)
		{
			free(path);
			return (index);
		}
		free(path);
		index++;
	}
	return (-1);
}

/*
initializes and adds a new node to the command list
*/
static int	build_command_list(t_cmds **cmds, char **cmd,
char **paths, int pindex)
{
	t_cmds	*new;
	t_cmds	*last;
	int		index;

	new = ft_lstnew_pipex(cmd, paths, pindex);
	if (!new)
		return (1);
	ft_lstadd_back_pipex(cmds, new);
	last = ft_lstlast_pipex(*cmds);
	index = ft_lstsize_pipex(*cmds);
	last->id = index - 1;
	return (0);
}

/* 
builds a linked list of valid commands
*/
int	collect_commands(int argc, char **argv, t_cmds **cmds, char **paths)
{
	int		index;
	int		path;
	char	**cmd;

	index = 2;
	while (index < argc - 1)
	{
		cmd = ft_split(argv[index], ' ');
		if (substrlen(cmd) == 0)
		{
			perror(NULL);
			free(cmd);
			return (1);
		}
		path = validate_command(cmd[0], paths);
		if (build_command_list(cmds, cmd, paths, path) == 0)
			index++;
		else
		{
			free_array(cmd);
			return (1);
		}
	}
	return (0);
}
