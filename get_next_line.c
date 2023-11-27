/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:42:24 by algultse          #+#    #+#             */
/*   Updated: 2023/11/26 19:35:07 by algultse         ###   ########.fr       */
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

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
		if (!*s++)
			return (0);
	return ((char *)s);
}

void	ft_bzero(void *str, size_t len)
{
	unsigned char	*buf;

	buf = (unsigned char *)str;
	while (len--)
		buf[len] = 0;
}

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (*(src + i))
		i++;
	if (!dstsize)
		return (i);
	while (dstsize && *src)
	{
		*dest++ = *src++;
		dstsize--;
	}
	*dest = '\0';
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s_dest;
	char	*p_dest;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	s_dest = malloc(sizeof(char) * (len + 1));
	if (!s_dest)
		return (NULL);
	p_dest = s_dest;
	while (*s1)
		*s_dest++ = *s1++;
	while (*s2)
		*s_dest++ = *s2++;
	*s_dest = '\0';
	return (p_dest);
}

char	*buf_line_op(char *tmp, char *line, char *buf, size_t *len_buf_n)
{
	free(line);
	if (!tmp)
		return (NULL);
	while (buf[*len_buf_n] && buf[*len_buf_n] != '\n')
		(*len_buf_n)++;
	if (buf[*len_buf_n] == '\n')
		(*len_buf_n)++;
	line = malloc(sizeof(char) * (*len_buf_n + 1));
	if (!line)
	{
		free(tmp);
		return (NULL);
	}
	ft_strlcpy(line, buf, *len_buf_n);
	return (line);
}

char	*update_buf_n_line(char *buf, char *line)
{
	char	*tmp;
	int		i;
	size_t	len;
	size_t	len_buf_n;
	
	len_buf_n = 0;
	tmp = ft_strdup(line);
	line = buf_line_op(tmp, line, buf, &len_buf_n);
	if (!line)
		return (NULL);
	line = ft_strjoin(tmp, line);
	free(tmp);
	if (!line)
		return (NULL);
	i = 0;
	len = ft_strlen(buf);
	while((len_buf_n + i) < len)
	{
		buf[i] = buf[len_buf_n + i];
		i++;
	}
	buf[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_strdup("");
	if (!line || !update_buf_n_line(buf, line))
		return (NULL);
	if (ft_strchr(line, '\n'))
		return (line);
	bytes_read = 1;
	while (bytes_read > 0) 
	{
		ft_bzero(buf, BUFFER_SIZE);
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		line = update_buf_n_line(buf, line);
		if (!line)
			return (NULL);
		if (!bytes_read || ft_strchr(line, '\n'))
			return (line);
	}
	return (line);
}


	

#include <fcntl.h>
int	main()
{	
	// char	*str = "hello\n";
	int	fd = open("./get_next_line.h", O_RDONLY);
	// char	buf[100];
	// printf("read [%zd]\n", read(fd, buf, sizeof(buf)));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));	
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));	
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	return (0);
}
