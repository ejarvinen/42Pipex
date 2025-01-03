/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 08:23:49 by emansoor          #+#    #+#             */
/*   Updated: 2024/05/05 13:58:21 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
closes reading end, redirects stdin from infile & redirects stdout to
writing end
*/
static void	first_command(t_cmds **cmds, t_cmds *cmd, int *pipefds)
{
	t_cmds	*next;

	next = *cmds;
	next = next->next;
	close(next->fd_outfile);
	close(pipefds[READ_END]);
	dup2(cmd->fd_infile, STDIN_FILENO);
	close(cmd->fd_infile);
	dup2(pipefds[WRITE_END], STDOUT_FILENO);
	close(pipefds[WRITE_END]);
}

/*
closes writing end, redirects stdin from reading end and redirects
stdout to outfile
*/
static void	scnd_command(t_cmds **cmds, t_cmds *cmd, int *pipefds)
{
	t_cmds	*prev;

	prev = *cmds;
	close(prev->fd_infile);
	close(pipefds[WRITE_END]);
	if (dup2(pipefds[READ_END], STDIN_FILENO) < 0)
	{
		perror("dup2");
		error(cmds, pipefds, 1);
	}
	close(pipefds[READ_END]);
	if (dup2(cmd->fd_outfile, STDOUT_FILENO) < 0)
	{
		perror("dup2");
		error(cmds, pipefds, 1);
	}
	close(cmd->fd_outfile);
}

/*
sets up pipe, stdin and stdout according to cmd and runs the command
*/
static void	execute(t_cmds **cmds, t_cmds *cmd, int *pipefds, char **envp)
{
	if (cmd->id == 0)
	{
		first_command(cmds, cmd, pipefds);
	}
	else if (cmd->id == cmd->commands - 1)
	{
		scnd_command(cmds, cmd, pipefds);
	}
	if (execve(cmd->path, cmd->command, envp) == -1
		&& cmd->id == cmd->commands - 1)
	{
		perror("execve");
		error(cmds, pipefds, 1);
	}
}

/*
forks a child process to execute a command
*/
static void	child_process(t_cmds **cmds, t_cmds *cmd, int *pipefds, char **envp)
{
	cmd->c_pid = fork();
	if (cmd->c_pid == 0)
	{
		execute(cmds, cmd, pipefds, envp);
	}
	if (cmd->id == cmd->commands - 1)
	{
		close(pipefds[READ_END]);
		close(pipefds[WRITE_END]);
	}
}

/*
initiates child processes and waits for them to finish
*/
void	run_commands(t_cmds **cmds, char **envp)
{
	t_cmds	*command;
	int		*pipefds;
	int		status;

	command = *cmds;
	pipefds = pipesetup();
	if (!pipefds)
		error(cmds, NULL, 1);
	child_process(cmds, command, pipefds, envp);
	command = command->next;
	child_process(cmds, command, pipefds, envp);
	command = *cmds;
	while (command)
	{
		waitpid(command->c_pid, &status, 0);
		if (command->id == 0)
			close(command->fd_infile);
		if (command->id == 1)
			close(command->fd_outfile);
		if (WIFEXITED(status) && command->id == command->commands - 1)
			error(cmds, pipefds, status);
		command = command->next;
	}
}

// still returns 0 for execve errors