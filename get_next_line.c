/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapryce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:51:26 by aapryce           #+#    #+#             */
/*   Updated: 2023/05/23 13:50:03 by aapryce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"

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
	char	buffer[BUFFER_SIZE + 1];
	char	*temp;
	int		bytes;

	bytes = read(fd, buffer, BUFFER_SIZE - 1);
	if (bytes == -1)
		return (-1);
	buffer[bytes] = '\0';
	temp = ft_strjoin(*store, buffer);
	free (*store);
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
	static char	*store = NULL;
	char		*line;
	int			bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!store)
		store = ft_strdup("");
	bytes = 1;
	while (bytes > 0 && !ft_strchr(store, '\n'))
		bytes = ft_read(fd, &store);
	if (bytes == -1 || !ft_strlen(store))
	{
		free (store);
		return (NULL);
	}
	line = ft_extract(&store);
	return (line);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*line;
	int	fd;

	fd = open("test.txt", O_RDONLY);

	line = get_next_line(fd);
	printf("%s", line);
	free (line);

	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free (line);
	}

	close(fd);
	return (0);
}
*/
