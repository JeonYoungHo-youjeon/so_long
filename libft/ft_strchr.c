/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeon <youjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 17:36:59 by youjeon           #+#    #+#             */
/*   Updated: 2022/03/28 17:58:36 by youjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *str, int c)
{
	char	*ptr_str;
	char	to_find;

	ptr_str = (char *) str;
	to_find = (char) c;
	while (*ptr_str)
	{
		if (*ptr_str == to_find)
			return (ptr_str);
		else
			ptr_str++;
	}
	if (to_find == '\0')
		return (ptr_str);
	return (NULL);
}
