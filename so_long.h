/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeon <youjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:15:01 by youjeon           #+#    #+#             */
/*   Updated: 2022/03/16 16:06:10 by youjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx/mlx.h"

typedef struct	s_img {
	void	*chara;
	void	*chest_open;
	void	*chest;
	void	*land;
	void	*rune;
	void	*rune_light;
	void	*wall;
}				t_img;

