/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 06:35:48 by emansoor          #+#    #+#             */
/*   Updated: 2024/04/30 12:57:26 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
finds allowed paths and splits them into 2D array
*/
static char	**path_finder(char **envp)
{
	int		index;
	char	**paths;

	index = 0;
	while (envp[index])
	{
		if (ft_strncmp(envp[index], "PATH=", 5) == 0)
			break ;
		index++;
	}
	if (!envp[index])
		return (NULL);
	paths = ft_split(envp[index] + 5, ':');
	if (!paths)
	{
		perror("ft_split");
		return (NULL);
	}
	return (paths);
}

/*
opens infile and saves it's file descriptor to first command
*/
static int	open_files(t_cmds **cmds, int argc, char **argv)
{
	t_cmds	*command;
	t_cmds	*last;

	command = *cmds;
	command->fd_infile = open(argv[1], O_RDONLY, 0777);
	if (command->fd_infile < 0)
	{
		perror("open");
		return (1);
	}
	last = ft_lstlast_pipex(*cmds);
	last->fd_outfile = open(argv[argc - 1], O_WRONLY | O_CREAT, 0777);
	if (last->fd_outfile < 0)
	{
		perror("open");
		return (1);
	}
	return (0);
}

/*
closes any open filedescriptors
*/
void	close_files(t_cmds **cmds)
{
	t_cmds	*command;

	command = *cmds;
	while (command)
	{
		if (command->fd_infile != -1)
			close(command->fd_infile);
		if (command->fd_outfile != -1)
			close(command->fd_outfile);
		command = command->next;
	}
}

/*
adds the number of pipes to each command's struct
*/
static void	add_cmdinfo(t_cmds **cmds, char **paths)
{
	t_cmds	*command;
	int		nbr_of_cmds;

	nbr_of_cmds = ft_lstsize_pipex(*cmds);
	command = *cmds;
	while (command)
	{
		command->commands = nbr_of_cmds;
		command = command->next;
	}
	command = *cmds;
	while (command)
	{
		if (command->id == 0)
			command->paths = paths;
		else
			command->paths = NULL;
		command = command->next;
	}
}

/*
it's a slightly above-average main
*/
int	main(int argc, char **argv, char **envp)
{
	t_cmds	*cmds;
	char	**paths;

	if (argc < 5)
		return (1);
	paths = path_finder(envp);
	if (!paths)
		return (1);
	cmds = NULL;
	if (collect_commands(argc, argv, &cmds, paths) > 0)
	{
		free_array(paths);
		ft_lstclear_pipex(&cmds, free);
		return (1);
	}
	add_cmdinfo(&cmds, paths);
	if (open_files(&cmds, argc, argv) > 0)
		error(cmds, NULL);
	run_commands(&cmds, envp);
	close_files(&cmds);
	free_array(paths);
	ft_lstclear_pipex(&cmds, free);
	return (0);
}
