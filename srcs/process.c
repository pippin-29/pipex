/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <daniel42.c@engineer.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:54:35 by dhadding          #+#    #+#             */
/*   Updated: 2023/05/29 09:28:03 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

extern t_pipex	*g_data;

void	child_process(int *pipe)
{
	dup2(g_data->fd_in, STDIN_FILENO);
	dup2(pipe[1], STDOUT_FILENO);
	close(pipe[0]);
	if (execvp(g_data->cmd1[0], g_data->cmd1) == -1)
		exit(1);
}

void	parent_process(int *pipe)
{
	dup2(g_data->fd_out, STDOUT_FILENO);
	dup2(pipe[0], STDIN_FILENO);
	close(pipe[1]);
	if (execvp(g_data->cmd2[0], g_data->cmd2) == -1)
		exit(1);
}
