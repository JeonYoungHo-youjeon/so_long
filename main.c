/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeon <youjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:14:58 by youjeon           #+#    #+#             */
/*   Updated: 2022/03/27 01:25:27 by youjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	ft_strlcpy(char *dst, char *src, int len)
{
	int	src_len;
	int	i;

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
	free(s1);
	free(s2);
	return (new_mem);
}

void	print_err(char *message)
{
	write(2, "Error\n", 6);
	write(2, message, ft_strlen(message));
	exit(1);
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
	rt.rune2 = mlx_xpm_file_to_image(mlx, "./images/rune2.xpm", &wid, &hei);
	return (rt);
}

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
	game->str_line = ft_strdup(line);
	free(line);
	while (line)
	{
		game->hei++;
		line = get_next_line(fd);
		if (line)
		{
			game->str_line = ft_strjoin(game->str_line, line);
		}
	}
	close(fd);
}

void	put_img(t_game *g, int w, int h)
{
	if (g->str_line[h * g->wid + w] == '1')
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.wall, w * 64, h * 64);
	}
	else if (g->str_line[h * g->wid + w] == 'C')
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.chest, w * 64, h * 64);
	}
	else if (g->str_line[h * g->wid + w] == 'P')
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.chara, w * 64, h * 64);
	}
	else if (g->str_line[h * g->wid + w] == 'E' && g->all_col == g->col_cnt)
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.rune2, w * 64, h * 64);
	}
	else if (g->str_line[h * g->wid + w] == 'E')
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
	while (hei < game->hei)
	{
		wid = 0;
		while (wid < game->wid)
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
		if (i < game->wid)
		{
			if (game->str_line[i] != '1')
				print_err("Map must be closed/surrounded by walls");
		}
		else if (i % game->wid == 0 || i % game->wid == game->wid - 1)
		{
			if (game->str_line[i] != '1')
				print_err("Map must be closed/surrounded by walls");
		}
		else if (i > ft_strlen(game->str_line) - game->wid)
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
		print_err("Map must have at least one exit");
	if (game->all_col == 0)
		print_err("Map must have at least one collectible");
	if (num_p != 1)
		print_err("Map must have one starting position");
}

void	map_check(t_game *game)
{
	if (game->hei * game->wid != ft_strlen(game->str_line))
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
	g->win = mlx_new_window(g->mlx, g->wid * 64, g->hei * 64, "so_long");
	setting_img(g);
}

int	exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

int	clear_game(t_game *game)
{
	game->walk_cnt++;
	printf("%s %d%s\n", "Congratulations! You have", game->walk_cnt, "steps.");
	exit(0);
}

void	move_w(t_game *g)
{
	int	i;

	i = 0;
	while (i++ < ft_strlen(g->str_line))
	{
		if (g->str_line[i] == 'P')
			break ;
	}
	if (g->str_line[i - g->wid] == 'C')
		g->col_cnt++;
	if (g->str_line[i - g->wid] == 'E' && g->all_col == g->col_cnt)
		clear_game(g);
	else if (g->str_line[i - g->wid] != '1' && g->str_line[i - g->wid] != 'E')
	{
		g->str_line[i] = '0';
		g->str_line[i - g->wid] = 'P';
		g->walk_cnt++;
		printf("%d\n", g->walk_cnt);
		setting_img(g);
	}
}

void	move_a(t_game *g)
{
	int	i;

	i = 0;
	while (i++ < ft_strlen(g->str_line))
	{
		if (g->str_line[i] == 'P')
			break ;
	}
	if (g->str_line[i - 1] == 'C')
		g->col_cnt++;
	if (g->str_line[i - 1] == 'E' && g->all_col == g->col_cnt)
		clear_game(g);
	else if (g->str_line[i - 1] != '1' && g->str_line[i - 1] != 'E')
	{
		g->str_line[i] = '0';
		g->str_line[i - 1] = 'P';
		g->walk_cnt++;
		printf("%d\n", g->walk_cnt);
		setting_img(g);
	}
}

void	move_s(t_game *g)
{
	int	i;

	i = 0;
	while (i++ < ft_strlen(g->str_line))
	{
		if (g->str_line[i] == 'P')
			break ;
	}
	if (g->str_line[i + g->wid] == 'C')
		g->col_cnt++;
	if (g->str_line[i + g->wid] == 'E' && g->all_col == g->col_cnt)
		clear_game(g);
	else if (g->str_line[i + g->wid] != '1' && g->str_line[i + g->wid] != 'E')
	{
		g->str_line[i] = '0';
		g->str_line[i + g->wid] = 'P';
		g->walk_cnt++;
		printf("%d\n", g->walk_cnt);
		setting_img(g);
	}
}

void	move_d(t_game *g)
{
	int	i;

	i = 0;
	while (i++ < ft_strlen(g->str_line))
	{
		if (g->str_line[i] == 'P')
			break ;
	}
	if (g->str_line[i + 1] == 'C')
		g->col_cnt++;
	if (g->str_line[i + 1] == 'E' && g->all_col == g->col_cnt)
		clear_game(g);
	else if (g->str_line[i + 1] != '1' && g->str_line[i + 1] != 'E')
	{
		g->str_line[i] = '0';
		g->str_line[i + 1] = 'P';
		g->walk_cnt++;
		printf("%d\n", g->walk_cnt);
		setting_img(g);
	}
}

int	press_key(int key_code, t_game *game)
{
	if (key_code == KEY_ESC)
		exit_game(game);
	if (key_code == KEY_W)
		move_w(game);
	if (key_code == KEY_A)
		move_a(game);
	if (key_code == KEY_S)
		move_s(game);
	if (key_code == KEY_D)
		move_d(game);
	return (0);
}

int	main(int ac, char *av[])
{
	t_game	*game;

	if (ac != 2)
		print_err("Map is missing.\n");
	game = malloc(sizeof(t_game));
	game_init(game, av[1]);
	mlx_hook(game->win, X_EVENT_KEY_PRESS, 0, &press_key, game);
	mlx_hook(game->win, X_EVENT_KEY_EXIT, 0, &exit_game, game);
	mlx_loop(game->mlx);
	return (0);
}
