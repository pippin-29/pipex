/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <daniel42.c@engineer.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:18:42 by dhadding          #+#    #+#             */
/*   Updated: 2023/05/24 20:43:42 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv)
{
	if (argc == 5)
	{
		init_struct();
		parse_args(argv);
		unlink(g_data->outfile);
		create_fd_io();
		execute();
	}
	else
	{
		ft_printf("Please Enter 4 Arguments\n");
		ft_printf("Use Format -- ./pipex infile 'cmd1' 'cmd2' outfile\n");
		exit(1);
	}
	return (0);
}
