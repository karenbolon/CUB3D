/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:39:09 by kbolon            #+#    #+#             */
/*   Updated: 2023/12/07 10:44:05 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"	

char	*ft_get_line(int fd, char *line, char *tmp)
{
	int		chars_read;
	char	*c_temp;

	chars_read = 1;
	while (chars_read != '\0')
	{
		chars_read = read(fd, line, BUFFER_SIZE);
		if (chars_read == -1)
			return (0);
		else if (chars_read == 0)
			break ;
		line[chars_read] = '\0';
		if (!tmp)
			tmp = ft_strdup("");
		c_temp = tmp;
		tmp = ft_strjoin(c_temp, line);
		free(c_temp);
		c_temp = NULL;
		if (ft_strchr (line, '\n'))
			break ;
	}
	return (tmp);
}

char	*new_line(char *line)
{
	size_t	i;
	char	*tmp;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0' || line[1] == '\0')
		return (0);
	tmp = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (*tmp == '\0')
	{
		free(tmp);
		tmp = NULL;
	}
	line[i + 1] = '\0';
	return (tmp);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*tmp;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	line = ft_get_line(fd, buffer, tmp);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	tmp = new_line(line);
	return (line);
}
