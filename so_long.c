/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeon <youjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:14:58 by youjeon           #+#    #+#             */
/*   Updated: 2022/03/28 18:27:58 by youjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_err(char *message)
{
	write(2, "Error\n", 6);
	write(2, message, ft_strlen(message));
	exit(1);
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
