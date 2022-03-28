/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeon <youjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:23:01 by youjeon           #+#    #+#             */
/*   Updated: 2022/03/28 18:28:17 by youjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
