/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeon <youjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 17:10:38 by youjeon           #+#    #+#             */
/*   Updated: 2022/03/27 01:24:55 by youjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str == 0)
		return (0);
	while (str[i] != 0)
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	if (str == 0)
		return (0);
	if ((unsigned char)c == '\0')
		return ((char *)str);
	while (*str != '\0')
	{
		if (*str == (unsigned char)c)
			return ((char *)str);
		str++;
	}
	return (0);
}
