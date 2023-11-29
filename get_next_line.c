/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:42:24 by algultse          #+#    #+#             */
/*   Updated: 2023/11/29 11:06:32 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*get_line(char **save, char *buf, ssize_t bytes_read)
{
	char	*line;
	size_t	len_n;

	ft_bzero(buf, bytes_read);
	if (bytes_read < 0 || !(*save))
		return (NULL);
	while (!bytes_read && !ft_strchr(*save, '\n'))
	{
		line = ft_strdup(*save);
		if (!line)
		{
			free(*save);
			*save = NULL;
			return (NULL);
		}
	}
	len_n = 0;
	while ((*save)[len_n] != '\n')
		len_n++;
	while ((*save)[len_n] == '\n')
		len_n++;
	line = ft_substr(*save, 0, len_n);
	if (ft_strlen(*save) - len_n >= 1)
		*save = ft_substr(*save, len_n, ft_strlen(*save) - len_n);
	return (line);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*save;
	ssize_t		bytes_read;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		buf[bytes_read] = '\0';
		if (!save)
		{
			save = ft_strdup(buf);
			if (!save)
				return(NULL);
		}
		else
		{
			save = ft_strjoin(save, buf);
			if (!save)
				return(NULL);
		}
		if (ft_strchr(save, '\n'))
			break ;
	}
	line = get_line(&save, buf, bytes_read);
	if (!line)
	{
		free(save);
		return (NULL);
	}
	return (line);
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