/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:42:24 by algultse          #+#    #+#             */
/*   Updated: 2023/11/29 16:38:35 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*p;
	unsigned int	i;
	size_t			s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	p = malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	i = 0;
	while (*s && len > 0)
	{
		p[i] = s[start + i];
		i++;
		len--;
	}
	p[i] = '\0';
	return (p);
}

char	*get_line(char **save, ssize_t bytes_read)
{
	char	*line;
	size_t	len_n;
	char	*tmp;

	if (bytes_read < 0 || !*save)
		return (NULL);
	if (!bytes_read && !ft_strchr(*save, '\n'))
	{
		line = ft_strdup(*save);
		if (!line)
		{
			free(*save);
			*save = NULL;
			return (NULL);
		}
		free(*save);
		*save = NULL;
		return (line);
	}
	len_n = 0;
	while ((*save)[len_n] != '\n')
		len_n++;
	while ((*save)[len_n] == '\n')
		len_n++;
	line = ft_substr(*save, 0, len_n);
	if (!line)
	{
		free(*save);
		*save = NULL;
		return (NULL);
	}
	tmp = NULL;
	if ((ft_strlen(*save) - len_n) >= 1)
	{
		tmp = ft_substr(*save, len_n, ft_strlen(*save) - len_n);
		if (!*tmp)
		{
			free(*save);
			*save = NULL;
			return (NULL);
		}
	}
	free(*save);
	*save = NULL;
	*save = tmp;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*buf;
	ssize_t		bytes_read;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tmp = NULL;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		buf[bytes_read] = '\0';
		if (bytes_read != 0)
		{
			if (!save)
				tmp = ft_strdup(buf);
			else
			{
				tmp = ft_strjoin(save, buf);
				free(save);
				save = NULL;
			}
			save = tmp;
			if (ft_strchr(save, '\n'))
				break ;
		}
	}
	free(buf);
	buf = NULL;
	return (get_line(&save, bytes_read));
}	

/*
#include <stdio.h>
#include <fcntl.h>
int	main()
{
	char *res;
	int	fd = open("./get_next_line.h", O_RDONLY);
	// printf("1, %s", get_next_line(fd));
	// printf("2, %s", get_next_line(fd));
	// printf("3, %s", get_next_line(fd));


	while ((res = get_next_line(fd))) {
		printf("%s", res);
	}
	close(fd);
	return (0);
}
*/