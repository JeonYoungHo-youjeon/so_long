/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeon <youjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:15:33 by youjeon           #+#    #+#             */
/*   Updated: 2022/03/28 18:04:25 by youjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char *s1, char *set)
{
	int		start;
	int		end;
	char	*new_mem;
	int		i;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	i = 0;
	while (s1[start] && ft_strchr(set, s1[start]) && start < end)
		start++;
	while (i < end)
	{
		if (ft_strchr(set, s1[end - i - 1]) == 0)
			break ;
		i++;
	}
	end = end - i;
	if (start >= end)
		return (ft_strdup(""));
	new_mem = ft_substr(s1, start, end - start);
	return (new_mem);
}
