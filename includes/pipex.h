/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <daniel42.c@engineer.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 04:48:36 by dhadding          #+#    #+#             */
/*   Updated: 2023/05/26 05:21:55 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/includes/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_pipex
{
	int		fd_in;
	int		fd_out;
	char	*infile;
	char	**cmd1;
	char	**cmd2;
	char	*outfile;
	pid_t	pid;
}	t_pipex;

extern t_pipex	*g_data;

/* PROCESS.C */
void	parent_process(int *pipe);
void	child_process(int *pipe);

/* PROGRAM.C */
void	execute(void);

/* SETUP.C */
void	init_struct(void);
void	parse_args(char **argv);
void	create_fd_io(void);
#endif