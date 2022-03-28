/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeon <youjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:24:45 by youjeon           #+#    #+#             */
/*   Updated: 2022/03/28 18:28:21 by youjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	map_read(char *filename, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd <= 0)
		print_err("File open fail.\n");
	line = get_next_line(fd);
	game->hei = 0;
	game->walk_cnt = 0;
	game->wid = ft_strlen(line) - 1;
	game->str_line = ft_strdup_without_newline(line);
	free(line);
	while (line)
	{
		game->hei++;
		line = get_next_line(fd);
		if (line)
		{
			game->str_line = ft_strjoin_without_newline(game->str_line, line);
		}
	}
	close(fd);
}

void	map_check_wall(t_game *game)
{
	int		i;

	i = 0;
	while (i < ft_strlen(game->str_line))
	{
		if (i < game->wid)
		{
			if (game->str_line[i] != '1')
				print_err("Map must be closed/surrounded by walls\n");
		}
		else if (i % game->wid == 0 || i % game->wid == game->wid - 1)
		{
			if (game->str_line[i] != '1')
				print_err("Map must be closed/surrounded by walls\n");
		}
		else if (i > ft_strlen(game->str_line) - game->wid)
		{
			if (game->str_line[i] != '1')
				print_err("Map must be closed/surrounded by walls\n");
		}
		i++;
	}
}

void	map_check_params(t_game *game)
{
	int	i;
	int	num_e;
	int	num_p;

	i = 0;
	num_e = 0;
	num_p = 0;
	game->all_col = 0;
	game->col_cnt = 0;
	while (i++ < ft_strlen(game->str_line))
	{
		if (game->str_line[i] == 'E')
			num_e++;
		else if (game->str_line[i] == 'P')
			num_p++;
		else if (game->str_line[i] == 'C')
			game->all_col++;
	}
	if (num_e == 0)
		print_err("Map must have at least one exit\n");
	if (game->all_col == 0)
		print_err("Map must have at least one collectible\n");
	if (num_p != 1)
		print_err("Map must have one starting position\n");
}

void	map_check(t_game *game)
{
	if (game->hei * game->wid != ft_strlen(game->str_line))
		print_err("Map must be rectangular.\n");
	map_check_wall(game);
	map_check_params(game);
}
