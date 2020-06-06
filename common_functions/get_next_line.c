/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 03:35:25 by gbaud             #+#    #+#             */
/*   Updated: 2020/06/06 10:36:13 by gbaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		contain(char *str, char c)
{
	int i;

	if (!(str))
		return (0);
	i = 0;
	while (str[i])
		if (c == str[i++])
			return (i);
	return (0);
}

int		check_save(int fd, char **line, char *save[4096])
{
	char *tmp;

	if (save[fd])
	{
		if (contain(save[fd], '\n'))
		{
			if (!(*line = ft_strfjoin(*line,
					ft_strfdup(save[fd], contain(save[fd], '\n') - 1, 0), 2)))
				return (-1);
			if (!(tmp = ft_strfdup(&(save[fd][contain(save[fd], '\n')]),
					-1, 0)))
				return (-1);
			free(save[fd]);
			save[fd] = NULL;
			save[fd] = tmp;
			return (1);
		}
		else
		{
			if (!(*line = ft_strfjoin(*line, save[fd], 2)))
				return (-1);
		}
	}
	return (0);
}

int		readed_n(int fd, char **line, char *save[4096], char *buffer)
{
	*line = ft_strfjoin(*line,
			ft_strfdup(buffer, contain(buffer, '\n') - 1, 0), 2);
	if ((&buffer[contain(buffer, '\n')])[0] != '\0')
		save[fd] = ft_strfdup(&buffer[contain(buffer, '\n')], -1, 0);
	return (1);
}

int		readed_zero(char **line, char *buffer)
{
	*line = ft_strfjoin(*line, buffer, 1);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*save[4096];
	char		buffer[BUFFER_SIZE + 1];
	int			r;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	if (!(*line = ft_strfdup("", -1, 0)))
		return (-1);
	ft_bzero(buffer, BUFFER_SIZE + 1);
	if ((r = check_save(fd, line, save)) != 0)
		return (r);
	r = read(fd, buffer, BUFFER_SIZE);
	while (r > 0 && !contain(buffer, '\n'))
	{
		*line = ft_strfjoin(*line, buffer, 1);
		ft_bzero(buffer, BUFFER_SIZE + 1);
		r = read(fd, buffer, BUFFER_SIZE);
	}
	if (contain(buffer, '\n'))
		return (readed_n(fd, line, save, buffer));
	if (r == 0)
		return (readed_zero(line, buffer));
	free(save[fd]);
	save[fd] = NULL;
	return (-1);
}
