/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:42:24 by algultse          #+#    #+#             */
/*   Updated: 2023/11/23 14:38:35 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strdup(const char *s1)
{
	char	*dst;
	size_t	len;

	len = 0;
	while (s1[len])
		len++;
	dst = malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	len = 0;
	while (s1[len])
	{
		dst[len] = s1[len];
		len++;
	}
	dst[len] = '\0';
	return (dst);
}

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

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
		if (!*s++)
			return (0);
	return ((char *)s);
}

char	*ft_strjoin_bytes(char *line, char *buf, ssize_t bytes_read)
{
	char	*str;
	size_t	len;
	int		i;

	if (!line)
		return (buf);
	len = ft_strlen(line);
	str = malloc(sizeof(char) * ((len + bytes_read) + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (line && line[++i])
		str[i] = line[i];
	i = -1;
	while (buf && buf[++i])
		str[len + i] = buf[i];
	str[len + i] = '\0';
	free(line);
	printf("str [%s]\n", str);
	return (str);
}

int	read_line(int fd, char *buf, char **line)
{
	char	*p_line;
	ssize_t	bytes_read;

	p_line = *line;
	bytes_read = read(fd, buf, BUFFER_SIZE);
	printf("byt_red [%zd]\n", bytes_read);
	if (bytes_read == -1)
		return (1);
	if (!bytes_read)
		return (2);
	buf[bytes_read] = '\0';
	if (!p_line)
	{
		p_line = ft_strdup(buf);
		if (!p_line)
		{
			// free(p_line);
			return (1);
		}
	}
	else
	{
		p_line = ft_strjoin_bytes(p_line, buf, bytes_read);
		if (!p_line)
		{
			// free(p_line);
			return (1);
		}
	}
	*line = p_line;
	return (0);
}

void	ft_bzero(void *str, size_t len)
{
	unsigned char	*buf;

	buf = (unsigned char *)str;
	while (len--)
		buf[len] = 0;
}

void	un_get_line(char *buf, char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	while (line[i])
	{
		buf[j] = line[i];
		line[i] = '\0';
		i++;
		j++;
	}
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE];
	char		*line;
	int			flag;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_strdup(buf);
	if (!line)
	{
		// free(line);	
		return (NULL);
	}
	flag = 0;
	while (!(ft_strchr(line, '\n')) && !flag)
		flag = read_line(fd, buf, &line);
	if (flag == 1)
		return (NULL);
	ft_bzero(buf, ft_strlen(buf));
	if (!flag)
		un_get_line(buf, line);
	return (line);
}


#include <fcntl.h>
int	main()
{	
	// char	*str = "hello\n";
	int	fd = open("./test.txt", O_CREAT | O_RDONLY, 0777);
	// char	buf[100];
	// printf("read [%zd]\n", read(fd, buf, sizeof(buf)));
	printf("get [%s]\n", get_next_line(fd));
	printf("get [%s]\n", get_next_line(fd));
	printf("get [%s]\n", get_next_line(fd));
	return (0);
}
