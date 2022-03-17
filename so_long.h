/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeon <youjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:15:01 by youjeon           #+#    #+#             */
/*   Updated: 2022/03/17 23:53:15 by youjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx/mlx.h"
#include "./get_next_line.h"
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>

#include <stdio.h> // 평가받기전에 삭제

typedef struct	s_img {
	void	*chara;
	void	*chest2;
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
	int		width;
	int		height;
	char	*str_line;
}				t_game;
