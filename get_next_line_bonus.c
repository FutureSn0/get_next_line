/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapryce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:04:41 by aapryce           #+#    #+#             */
/*   Updated: 2023/09/26 11:33:00 by aapryce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line_bonus.h"

char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static int	ft_read(int fd, char **store)
{
	char	*buffer;
	char	*temp;
	int		bytes;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (-1);
	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes == -1)
	{
		free (buffer);
		return (-1);
	}
	buffer[bytes] = '\0';
	temp = ft_strjoin(*store, buffer);
	if (!temp)
	{
		free(buffer);
		return (-1);
	}
	free (*store);
	free (buffer);
	*store = temp;
	return (bytes);
}

static char	*ft_extract(char **store)
{
	char	*line;
	char	*temp;
	char	*next_line;

	next_line = ft_strchr(*store, '\n');
	if (next_line)
	{
		line = ft_substr(*store, 0, next_line - *store + 1);
		temp = ft_strdup(next_line + 1);
		free (*store);
		*store = temp;
	}
	else
	{
		line = ft_strdup(*store);
		free (*store);
		*store = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*store[1024];
	char		*line;
	int			bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!store[fd])
	{
		store[fd] = ft_strdup("");
		if (!store[fd])
		{
			return (NULL);
		}
	}
	bytes = 1;
	while (bytes > 0 && !ft_strchr(store[fd], '\n'))
		bytes = ft_read(fd, &store[fd]);
	if (bytes == -1 || !ft_strlen(store[fd]))
	{
		free (store[fd]);
		store[fd] = NULL;
		return (NULL);
	}
	line = ft_extract(&store[fd]);
	return (line);
}
