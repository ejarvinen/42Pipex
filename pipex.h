/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 07:26:25 by emansoor          #+#    #+#             */
/*   Updated: 2024/05/03 15:11:02 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>
# include "libft/libft.h"

# define READ_END 0
# define WRITE_END 1

typedef struct s_cmds
{
	char			**command;
	char			*path;
	int				c_pid;
	int				fd_infile;
	int				fd_outfile;
	int				id;
	int				commands;
	struct s_cmds	*next;
}			t_cmds;

void	free_array(char **array);
int		substrlen(char **array);
int		collect_commands(int argc, char **argv, t_cmds **cmds, char **paths);
char	*full_path(char *path, char *command);
int		*pipesetup(void);
void	run_commands(t_cmds **cmds, char **envp);
void	error(t_cmds **cmds, int *pipefds, int exitcode);
void	close_files(t_cmds **cmds);

/* LINKED LIST TOOLS */
t_cmds	*ft_lstnew_pipex(char **cmd, char **paths, int index);
int		ft_lstsize_pipex(t_cmds *lst);
t_cmds	*ft_lstlast_pipex(t_cmds *lst);
void	ft_lstadd_back_pipex(t_cmds **lst, t_cmds *new);
void	ft_lstclear_pipex(t_cmds **lst, void (*del)(void*));
t_cmds	*find_prev(t_cmds **cmds, int index);

#endif