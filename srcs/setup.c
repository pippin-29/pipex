/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <daniel42.c@engineer.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:49:47 by dhadding          #+#    #+#             */
/*   Updated: 2023/05/26 05:23:19 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

t_pipex	*g_data;

void	init_struct(void)
{
	g_data = malloc(sizeof(t_pipex));
	if (!g_data)
	{
		perror("Error: Memory Allocation For Struct!");
		exit(1);
	}
	g_data->fd_in = -1;
	g_data->fd_out = -1;
	g_data->infile = NULL;
	g_data->outfile = NULL;
	g_data->cmd1 = NULL;
	g_data->cmd2 = NULL;
}

void	parse_args(char **argv)
{
	g_data->infile = ft_strdup(argv[1]);
	g_data->cmd1 = ft_split(argv[2], ' ');
	g_data->cmd2 = ft_split(argv[3], ' ');
	g_data->outfile = ft_strdup(argv[4]);
}

void	create_fd_io(void)
{
	g_data->fd_in = open(g_data->infile, O_RDONLY);
	if (g_data->fd_in == -1)
		perror("Error: Infile Open");
	g_data->fd_out = open(g_data->outfile, O_CREAT | O_WRONLY, 0644);
	if (g_data->fd_out == -1)
		perror("Error: Outfile Open");
}
