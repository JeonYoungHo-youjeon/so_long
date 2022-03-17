/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeon <youjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:14:58 by youjeon           #+#    #+#             */
/*   Updated: 2022/03/18 00:07:57 by youjeon          ###   ########.fr       */
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
	while (i < len - 1 && *src)
	{
		if (*src != '\n')
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
	new_mem = malloc(s1_len + s2_len + 1);
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
	rt.chest2 = mlx_xpm_file_to_image(mlx, "./images/chest2.xpm", &wid, &hei);
	rt.rune = mlx_xpm_file_to_image(mlx, "./images/rune.xpm", &wid, &hei);
	rt.rune2 = mlx_xpm_file_to_image(mlx, "./images/rune2.xpm", &wid, &hei);
	return (rt);
}

t_game	map_read(char *filename, t_game game)
{
	int		fd;
	char	*line;
	int		index;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	game.height = 1;
	game.width = ft_strlen(line);
	game.str_line = ft_strdup(line);
	while (line)
	{
		game.height++;
		index = 0;
		line = get_next_line(fd);
		game.str_line = ft_strjoin(game.str_line, line);

	printf("%s", line);	
	}
	printf("\n%s \n", game.str_line);	
	return (game);
}

int	main(int ac, char *av[])
{
	t_game	game;

	game.mlx = mlx_init();
	game.img = img_init(game.mlx);
	write(1,"test\n",5);
	game = map_read(av[1], game);
	//game.win = mlx_new_window(game.mlx, 500, 500, "my_mlx");
	//mlx_loop(game.mlx);
	return (0);
}
