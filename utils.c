/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 08:26:55 by emansoor          #+#    #+#             */
/*   Updated: 2024/04/30 08:28:11 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
returns the number of substrings in 2D array
*/
int substrlen(char **array)
{
	int len;

	len = 0;
	if (*array)
	{
		while (array[len])
			len++;
	}
	return (len);
}
/*
frees a 2D array
*/
void free_array(char **array)
{
	int index;

	index = 0;
	while (array[index])
	{
		free(array[index]);
		index++;
	}
	free(array);
}
/*
finds a command from cmds according to given index
*/
t_cmds	*find_prev(t_cmds **cmds, int index)
{
	t_cmds	*prev;

	prev = *cmds;
	while (prev)
	{
		if (prev->id == index)
			return (prev);
		prev = prev->next;
	}
	return (NULL);
}

/*
creates a pipe and returns a pointer to the pipe descriptors
*/
int	*pipesetup(void)
{
	int	*pipefds;
	int	fds[2];

	pipefds = (int *)malloc(sizeof(int) * 2);
	if (!pipefds)
	{
		perror("malloc");
		return (NULL);
	}
	if (pipe(fds) < 0)
	{
		perror("pipe");
		free(pipefds);
		return (NULL);
	}
	pipefds[READ_END] = fds[READ_END];
	pipefds[WRITE_END] = fds[WRITE_END];
	return (pipefds);
}

void	error(t_cmds **cmds, int *pipefds)
{
	t_cmds	*command;
	
	close(pipefds[READ_END]);
	close(pipefds[WRITE_END]);
	free(pipefds);
	close_files(cmds);
	command = *cmds;
	free_array(command->paths);
	ft_lstclear_pipex(cmds, free);
	exit(1);
}
