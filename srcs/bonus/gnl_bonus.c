/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymassiou <ymassiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:06:52 by ymassiou          #+#    #+#             */
/*   Updated: 2024/01/29 10:17:59 by ymassiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static char	*set_line(char *save)
{
	ssize_t	i;
	char	*result;

	i = 0;
	if (save == NULL)
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\n')
		i++;
	result = ft_substr(save, 0, i);
	return (result);
}

static char	*prepare_next(char *save)
{
	ssize_t	i;
	char	*result;

	i = 0;
	if (save == NULL)
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\n')
		i++;
	result = ft_strdup(save + i);
	free(save);
	return (result);
}

static char	*fill_the_line(char *save, char *buffer, int fd)
{
	ssize_t	rbytes;
	char	*tmp;

	rbytes = 1;
	while (!ft_strchr(save, '\n') && rbytes)
	{
		rbytes = read(fd, buffer, 10);
		if (rbytes == -1)
		{
			free(buffer);
			free(save);
			return (NULL);
		}
		buffer[rbytes] = '\0';
		tmp = save;
		save = ft_strjoin(save, buffer);
		free(tmp);
	}
	free(buffer);
	if (save && save[0] == '\0')
	{
		free(save);
		return (NULL);
	}
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;
	char		*buffer;

	if (fd < 0 || fd > OPEN_MAX)
		return (NULL);
	buffer = malloc(11);
	if (buffer == NULL)
		return (NULL);
	save = fill_the_line(save, buffer, fd);
	line = set_line(save);
	save = prepare_next(save);
	return (line);
}
