/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeon <youjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:15:01 by youjeon           #+#    #+#             */
/*   Updated: 2022/03/26 23:39:54 by youjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./mlx/mlx.h"
# include "./get_next_line.h"
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>

#include <stdio.h> // 평가받기전에 삭제

# define X_EVENT_KEY_PRESS			2
# define X_EVENT_KEY_RELEASE		3

# define X_EVENT_KEY_EXIT		17
# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

typedef struct	s_img {
	void	*chara;
	void	*chest;
	void	*land;
	void	*rune;
	void	*rune2;
	void	*wall;
}				t_img;

typedef struct	s_game
{
	void	*mlx;
	void	*win;
	t_img	img;
	int		wid;
	int		hei;
	char	*str_line;
	int		all_col;
	int		col_cnt;
	int		walk_cnt;
}				t_game;
