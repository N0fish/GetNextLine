/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:42:24 by algultse          #+#    #+#             */
/*   Updated: 2023/11/22 16:50:43 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	// ssize_t		bytes_read;
	char		*line_to_return;
	char		c;
	int			i;
	int			flag;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line_to_return = NULL;
	i = 0;
	flag = 1;
	while (flag)
	{
		if (!i && !buf)
		{
			if ((read(fd, &c, BUFFER_SIZE)) <= 0)
				return (line_to_return);
			if (i == BUFFER_SIZE - 1 || buf[i] == '\n')
			{
				flag = 0;
				line_to_return = ft_strcat();
				i = -1;
			}
		}
		i++;
	}
	
	// while ((bytes_read = read(fd, buf, BUFFER_SIZE)) > 0) {
	// 	printf("[%.*s]", (int)bytes_read, buf);
    // }
	return (line_to_return);
}


#include <fcntl.h>
int	main()
{	
	// char	*str = "hello\n";
	int	fd = open("./test.txt", O_CREAT | O_RDONLY, 0777);
	// char	buf[100];
	// printf("read [%zd]\n", read(fd, buf, sizeof(buf)));
	get_next_line(fd);
	return (0);
}
