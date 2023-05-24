/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <daniel42.c@engineer.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:15:40 by dhadding          #+#    #+#             */
/*   Updated: 2023/05/24 20:44:37 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

extern t_pipex	*g_data;

void	execute(void)
{
	int	end[2];

	if (pipe(end) == -1)
	{
		perror("Error: Pipe");
		exit(-1);
	}
	g_data->pid = fork();
	if (g_data->pid < 0)
	{
		perror("Error: Fork");
		exit(-1);
	}	
	if (g_data->pid == 0)
		child_process(end);
	parent_process(end);
}
