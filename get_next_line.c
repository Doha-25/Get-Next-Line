/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbani-ya <dbani-ya@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 12:20:19 by dbani-ya          #+#    #+#             */
/*   Updated: 2026/02/08 11:56:45 by dbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_line(char *stash)
{
	int		i;
	char	*line;

	i = 0;
	if (!stash || !stash[0])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*save_rest(char *stash)
{
	int			i;
	int			j;
	char		*rest;

	i = 0;
	j = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	rest = malloc(ft_strlen(stash) - i);
	if (!rest)
		return (free(stash), NULL);
	i++;
	while (stash[i])
		rest[j++] = stash[i++];
	rest[j] = '\0';
	free(stash);
	return (rest);
}

static char	*fill_stash(int fd, char *stash)
{
	int		bytes;
	char	*buffer;
	char	*tmp;

	if (!stash)
		stash = ft_strdup("");
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(stash), NULL);
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			return (free(buffer), free(stash), NULL);
		if (bytes == 0)
			break ;
		buffer[bytes] = '\0';
		tmp = stash;
		stash = ft_strjoin(tmp, buffer);
		free(tmp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (free(buffer), stash);
}

char	*get_next_line(int fd)
{
	static char		*stash;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = fill_stash(fd, stash);
	if (!stash)
		return (NULL);
	if (!*stash)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	line = get_line(stash);
	if (!line)
		return (free(stash), stash = NULL, NULL);
	stash = save_rest(stash);
	return (line);
}
