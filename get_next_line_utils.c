/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapryce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:55:23 by aapryce           #+#    #+#             */
/*   Updated: 2023/09/22 12:16:46 by aapryce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(const char *str1, const char *str2)
{
	char	*arr;
	size_t	len;
	int		i;

	if (!str1 || !str2)
		return (NULL);
	i = 0;
	len = ft_strlen(str1) + ft_strlen(str2);
	arr = (char *)malloc(len + 1);
	if (!arr)
		return (NULL);
	while (*str1)
		arr[i++] = *str1++;
	while (*str2)
		arr[i++] = *str2++;
	arr[i] = '\0';
	return (arr);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return ((char *)(str + i));
		i++;
	}
	if (str[i] == (char)c)
		return ((char *)(str + i));
	return (0);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*arr;

	i = 0;
	if (!s)
		return (NULL);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	arr = (char *)malloc(len + 1);
	if (!arr)
		return (NULL);
	while (i < len)
	{
		arr[i++] = s[start++];
		if (!arr)
		{
			free(arr);
			return (NULL);
		}
	}
	arr[i] = '\0';
	return (arr);
}

char	*ft_strdup(const char *src)
{
	char	*res;
	size_t	len;

	if (!src)
		return (NULL);
	len = ft_strlen(src);
	res = (char *)malloc(len + 1);
	if (!res)
		return (NULL);
	ft_strcpy(res, src);
	return (res);
}
