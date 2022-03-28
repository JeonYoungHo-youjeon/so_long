/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeon <youjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 17:47:43 by youjeon           #+#    #+#             */
/*   Updated: 2022/03/28 18:05:05 by youjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char *s, int start, int len)
{
	char	*new_mem;

	new_mem = NULL;
	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (len > ft_strlen(s))
		len = ft_strlen(s) + 1;
	new_mem = malloc(len + 1);
	if (!(new_mem))
		return (NULL);
	ft_strlcpy(new_mem, s + start, len + 1);
	return (new_mem);
}
