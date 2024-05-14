/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabbiz <rlabbiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 14:12:28 by rlabbiz           #+#    #+#             */
/*   Updated: 2022/11/06 15:07:44 by rlabbiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line_bonus.h"

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
	if (*s == (char)c)
		return (s);
	return (NULL);
}

char	*get_buff(int fd, char *sub)
{
	char	*buff;
	int		i;

	buff = (char *)malloc(sizeof(char ) * BUFFER_SIZE + 1);
	if (!buff)
		return (0);
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

char	*get_line(char *buff)
{
	char	*line;
	int		i;

	i = 0;
	if (!buff[0])
		return (NULL);
	while (buff[i] && buff[i] != '\n')
		i++;
	i++;
	line = ft_substr(buff, 0, i);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*sub[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	sub[fd] = get_buff(fd, sub[fd]);
	if (!sub[fd])
		return (NULL);
	line = get_line(sub[fd]);
	sub[fd] = get_sub(sub[fd]);
	return (line);
}
