/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeon <youjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:14:58 by youjeon           #+#    #+#             */
/*   Updated: 2022/03/26 16:08:02 by youjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_err(char *message)
{
	write(2, "Error\n", 6);
	write(2, message, ft_strlen(message));
	exit(1);
}

char	*ft_strdup(char *s)
{
	char	*new_mem;
	int		size;
	int		i;

	new_mem = NULL;
	size = ft_strlen(s);
	i = 0;
	new_mem = malloc(size + 1);
	if (!(new_mem))
		return (NULL);
	while (s[i] && s[i] != '\n')
	{
		new_mem[i] = s[i];
		i++;
	}
	new_mem[i] = '\0';
	return (new_mem);
}

size_t	ft_strlcpy(char *dst, char *src, size_t len)
{
	size_t	src_len;
	size_t	i;

	src_len = 0;
	i = 0;
	while (src[src_len])
		src_len++;
	if (len == 0)
	{
		return (src_len);
	}
	while (i < len - 1 && *src && *src != '\n')
	{
		*dst = *src;
		dst++;
		src++;
		i++;
	}
	*dst = '\0';
	return (src_len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_mem;
	size_t	s1_len;
	size_t	s2_len;

	new_mem = NULL;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	else if (s1 == NULL)
		return (ft_strdup(s2));
	else if (s2 == NULL)
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_mem = malloc(s1_len + s2_len);
	if (!(new_mem))
		return (NULL);
	ft_strlcpy(new_mem, s1, s1_len + 1);
	ft_strlcpy(new_mem + s1_len, s2, s2_len + 1);
	return (new_mem);
}

t_img	img_init(void *mlx)
{
	t_img	rt;
	int		wid;
	int		hei;

	rt.land = mlx_xpm_file_to_image(mlx, "./images/land.xpm", &wid, &hei);
	rt.wall = mlx_xpm_file_to_image(mlx, "./images/wall.xpm", &wid, &hei);
	rt.chara = mlx_xpm_file_to_image(mlx, "./images/chara.xpm", &wid, &hei);
	rt.chest = mlx_xpm_file_to_image(mlx, "./images/chest.xpm", &wid, &hei);
	rt.rune = mlx_xpm_file_to_image(mlx, "./images/rune.xpm", &wid, &hei);
	return (rt);
}

void	map_read(char *filename, t_game *game)
{
	int		fd;
	char	*line;
	int		index;

	fd = open(filename, O_RDONLY);
	if (fd <= 0)
		print_err("File open fail.\n");
	line = get_next_line(fd);
	game->height = 0;
	game->width = ft_strlen(line) - 1;
	game->str_line = ft_strdup(line);
	while (line)
	{
		game->height++;
		index = 0;
		line = get_next_line(fd);
		game->str_line = ft_strjoin(game->str_line, line);
	}
	printf("%s \n", game->str_line);
}

void	put_img(t_game *g, int w, int h)
{
	if (g->str_line[h * g->width + w] == '1')
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.wall, w * 64, h * 64);
	}
	else if (g->str_line[h * g->width + w] == 'C')
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.chest, w * 64, h * 64);
	}
	else if (g->str_line[h * g->width + w] == 'P')
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.chara, w * 64, h * 64);
	}
	else if (g->str_line[h * g->width + w] == 'E')
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.rune, w * 64, h * 64);
	}
	else
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.land, w * 64, h * 64);
	}
}

void	setting_img(t_game *game)
{
	int		hei;
	int		wid;

	hei = 0;
	while (hei < game->height)
	{
		wid = 0;
		while (wid < game->width)
		{
			put_img(game, wid, hei);
			wid++;
		}
		hei++;
	}
}

void	map_check_wall(t_game *game)
{
	int		i;

	i = 0;
	while (i < ft_strlen(game->str_line))
	{
		if (i < game->width)
		{
			if (game->str_line[i] != '1')
				print_err("Map must be closed/surrounded by walls");
		}
		else if (i % game->width == 0 || i % game->width == game->width - 1)
		{
			if (game->str_line[i] != '1')
				print_err("Map must be closed/surrounded by walls");
		}
		else if (i > ft_strlen(game->str_line) - game->width)
		{
			if (game->str_line[i] != '1')
				print_err("Map must be closed/surrounded by walls");
		}
		i++;
	}
}

void	map_check_params(t_game *game)
{
	int	i;
	int	num_e;
	int	num_p;
	int	num_c;

	i = 0;
	num_e = 0;
	num_p = 0;
	num_c = 0;
	while (i++ < ft_strlen(game->str_line))
	{
		if (game->str_line[i] == 'E')
			num_e++;
		else if (game->str_line[i] == 'P')
			num_p++;
		else if (game->str_line[i] == 'C')
			num_c++;
	}
	if (num_e == 0)
		print_err("Map must have at least one exit");
	if (num_c == 0)
		print_err("Map must have at least one collectible");
	if (num_p != 1)
		print_err("Map must have one starting position");
}

void	map_check(t_game *game)
{
	if (game->height * game->width != ft_strlen(game->str_line))
		print_err("Map must be rectangular.\n");
	map_check_wall(game);
	map_check_params(game);
}

void	game_init(t_game *g, char *map)
{
	g->mlx = mlx_init();
	g->img = img_init(g->mlx);
	map_read(map, g);
	map_check(g);
	g->win = mlx_new_window(g->mlx, g->width * 64, g->height * 64, "so_long");
	setting_img(g);
}

int	main(int ac, char *av[])
{
	t_game	*game;

	if (ac != 2)
		print_err("Map is missing.\n");
	game = malloc(sizeof(t_game));
	game_init(game, av[1]);
	mlx_loop(game->mlx);
	return (0);
}
