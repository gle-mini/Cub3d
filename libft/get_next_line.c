/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-mini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:50:28 by gle-mini          #+#    #+#             */
/*   Updated: 2023/06/26 18:08:23 by gle-mini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define BUFFER_SIZE 10

char	*my_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}


char	*my_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	c;
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (str == NULL)
	{
		//ft_putstr_fd("test3\n", 1);
		return (NULL);
	}
	i = -1;
	c = 0;
	if (s1)
		while (s1[++i] != '\0')
			str[i] = s1[i];
	while (s2[c] != '\0')
		str[i++] = s2[c++];
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (str);
}

char	*ft_read_to_static(int fd, char *static_readed)
{
	char	*buffer;
	int		read_bytes;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (read_bytes != 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		static_readed = my_strjoin(static_readed, buffer);
		if (my_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (static_readed);
}

char	*ft_get_line(char *static_readed)
{
	int		i;
	char	*s;

	i = 0;
	if (!static_readed[i])
		return (NULL);
	while (static_readed[i] && static_readed[i] != '\n')
		i++;
	s = (char *)malloc(sizeof(char) * (i + 2));
	if (!s)
		return (NULL);
	i = 0;
	while (static_readed[i] && static_readed[i] != '\n')
	{
		s[i] = static_readed[i];
		i++;
	}
	if (static_readed[i] == '\n')
	{
		s[i] = static_readed[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_remove_line(char *static_readed)
{
	int		i;
	int		c;
	char	*s;

	i = 0;
	while (static_readed[i] && static_readed[i] != '\n')
		i++;
	if (static_readed[i] == '\0')
	{
		free(static_readed);
		return (NULL);
	}
	s = (char *)malloc(sizeof(char) * (ft_strlen(static_readed) - i + 1));
	if (!s)
		return (NULL);
	i++;
	c = 0;
	while (static_readed[i])
		s[c++] = static_readed[i++];
	s[c] = '\0';
	free(static_readed);
	return (s);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*static_readed[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	static_readed[fd] = ft_read_to_static(fd, static_readed[fd]);
	if (!static_readed[fd])
		return (NULL);
	line = ft_get_line(static_readed[fd]);
	static_readed[fd] = ft_remove_line(static_readed[fd]);
	return (line);
}
