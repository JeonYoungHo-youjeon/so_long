/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeon <youjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 14:40:22 by youjeon           #+#    #+#             */
/*   Updated: 2022/03/28 17:59:46 by youjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	while (s[i])
	{
		new_mem[i] = s[i];
		i++;
	}
	new_mem[i] = '\0';
	return (new_mem);
}
