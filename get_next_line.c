/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:42:24 by algultse          #+#    #+#             */
/*   Updated: 2023/11/22 20:36:46 by algultse         ###   ########.fr       */
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
	if (dst == NULL)
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

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE];
	ssize_t		bytes_read;
	char		*line;
	int			i;
	int			flag;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	i = 0;
	flag = 1;
	while (flag)
	{
		if (!i)
		{
			bytes_read = read(fd, buf, BUFFER_SIZE);
			printf("b_r: [%zd]\n", bytes_read);
			if (bytes_read > 0)
			{
				line = ft_strdup(buf);
				return (line);
			}
			if (i == BUFFER_SIZE - 1 || buf[i] == '\n')
			{
				flag = 0;
				i = -1;
			}
		}
		i++;
	}
	
	// while ((bytes_read = read(fd, buf, BUFFER_SIZE)) > 0) {
	// 	printf("[%.*s]", (int)bytes_read, buf);
    // }
	return (line);
}


#include <fcntl.h>
int	main()
{	
	// char	*str = "hello\n";
	int	fd = open("./test.txt", O_CREAT | O_RDONLY, 0777);
	// char	buf[100];
	// printf("read [%zd]\n", read(fd, buf, sizeof(buf)));
	printf("get [%s]", get_next_line(fd));
	return (0);
}
