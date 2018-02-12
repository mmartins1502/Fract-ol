/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 14:13:19 by mmartins          #+#    #+#             */
/*   Updated: 2017/06/01 22:08:30 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>

static int	get_str(char *str, char **line)
{
	char	*eol;

	eol = ft_strchr(str, '\n');
	if (eol)
	{
		eol[0] = '\0';
		*line = ft_strdup(str);
		str = ft_strncpy(str, &eol[1], ft_strlen(&eol[1]) + 1);
		return (1);
	}
	if (ft_strlen(str) > 0)
	{
		*line = ft_strdup(str);
		*str = '\0';
		return (1);
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static char	*str = NULL;
	char		buffer[BUFF_SIZE + 1];
	int			ret;
	char		*tmp;

	if (!str)
		str = ft_strnew(0);
	if (fd < 0 || !str || !line || BUFF_SIZE <= 0)
		return (-1);
	while (!ft_strchr(str, '\n'))
	{
		ret = read(fd, buffer, BUFF_SIZE);
		if (ret == -1)
			return (-1);
		if (ret == 0)
			return (get_str(str, line));
		buffer[ret] = '\0';
		tmp = ft_strjoin(str, buffer);
		str = tmp;
	}
	return (get_str(str, line));
}
