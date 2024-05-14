/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:49:03 by rlabbiz           #+#    #+#             */
/*   Updated: 2022/11/08 18:20:15 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int c)
{
	char	*s;

	s = (char *)str;
	while (*s)
	{
		if (*s == (char)c)
			return (s);
		s++;
	}
	return (NULL);
}

char	*get_buff(int fd, char *sub)
{
	char	*buff;
	int		i;

	buff = (char *)malloc(sizeof(char ) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	i = 1;
	while (i > 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
			break ;
		buff[i] = '\0';
		sub = ft_strjoin(sub, buff);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	free(buff);
	return (sub);
}

char	*get_line(char *buff)
{
	char	*line;
	int		i;

	i = 0;
	if (!buff[0])
		return (NULL);
	while (buff[i] && buff[i] != '\n')
		i++;
	line = ft_substr(buff, 0, i + 1);
	return (line);
}

char	*get_sub(char *buff)
{
	char	*sub;
	int		i;

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (!buff[i])
	{
		free(buff);
		return (NULL);
	}
	i++;
	sub = ft_substr(buff, i, ft_strlen(buff) - i);
	free(buff);
	return (sub);
}

char	*get_next_line(int fd)
{
	static char	*sub;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	sub = get_buff(fd, sub);
	if (!sub)
		return (NULL);
	line = get_line(sub);
	sub = get_sub(sub);
	return (line);
}
