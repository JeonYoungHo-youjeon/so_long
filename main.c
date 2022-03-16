/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeon <youjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:14:58 by youjeon           #+#    #+#             */
/*   Updated: 2022/03/16 16:12:43 by youjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	img_init(void *mlx)
{
	t_img	rt;
	int		img_width;
	int 	img_height;

	rt.land = mlx_xpm_file_to_image(mlx, "./images/land.xpm", &img_width, &img_height);
	rt.wall = mlx_xpm_file_to_image(mlx, "./images/wall.xpm", &img_width, &img_height);
	rt.chara = mlx_xpm_file_to_image(mlx, "./images/chara.xpm", &img_width, &img_height);
	rt.chest = mlx_xpm_file_to_image(mlx, "./images/chest.xpm", &img_width, &img_height);
	rt.chest_open = mlx_xpm_file_to_image(mlx, "./images/chest_open.xpm", &img_width, &img_height);
	rt.rune = mlx_xpm_file_to_image(mlx, "./images/rune.xpm", &img_width, &img_height);
	rt.rune_light = mlx_xpm_file_to_image(mlx, "./images/rune_light.xpm", &img_width, &img_height);

	return (rt);
}

int main()
{
		void	*mlx;
		void	*win;
		t_img	img;

		int		img_width;
		int 	img_height;

		mlx = mlx_init();
		img = img_init(mlx);
		win = mlx_new_window(mlx, 500, 500, "my_mlx");
		
		
		// mlx_put_image_to_window(mlx, win, img7, 128, 64);
		mlx_loop(mlx);
		return (0);
}
