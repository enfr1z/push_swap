/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiedra <pdiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 21:03:15 by pdiedra           #+#    #+#             */
/*   Updated: 2019/04/17 14:21:37 by pdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_del(char **str, char **tmp)
{
	free(*tmp);
	free(*str);
	return (-1);
}

static void		*ft_my_realloc(void *str, size_t size)
{
	size_t	len;
	void	*ret;

	if (str == NULL)
		return (NULL);
	if (size == 0)
		return (str);
	len = ft_strlen((char*)str);
	ret = malloc(sizeof(str) * len + size);
	ft_bzero(ret, len + size);
	ret = ft_memcpy(ret, str, len);
	if (ret == NULL)
		return (str);
	free(str);
	return (ret);
}

static int		new_line(char **str, char **line, const int fd)
{
	char	*tmp;
	int		len;

	len = 0;
	while (str[fd][len] != '\n' && str[fd][len] != '\0')
		len++;
	if (str[fd][len] == '\n')
	{
		if (!(*line = ft_strsub(str[fd], 0, len)))
			return (-1);
		tmp = str[fd];
		if (!(str[fd] = ft_strdup(str[fd] + len + 1)))
			return (-1);
		ft_strdel(&tmp);
		if (str[fd][0] == '\0')
			ft_strdel(&str[fd]);
	}
	else if (str[fd][len] == '\0')
	{
		if (!(*line = ft_strdup(str[fd])))
			return (-1);
		ft_strdel(&str[fd]);
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char		*str[0];
	char			buf[BUFF_SIZE + 1];
	char			*tmp;
	int				ret;

	if (fd < 0 || line == NULL || BUFF_SIZE <= 0 || read(fd, buf, 0) < 0)
		return (-1);
	if (str[fd] == NULL)
	{
		str[fd] = ft_my_realloc(str[fd], fd);
		str[fd] = ft_strnew(1);
	}
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = str[fd];
		if (!(str[fd] = ft_strjoin(tmp, buf)))
			return (ft_del(&str[fd], &tmp));
		free(tmp);
		if (ft_strchr(str[fd], '\n'))
			break ;
	}
	if (ret == 0 && (str[fd] == 0 || str[fd][0] == '\0'))
		return (0);
	return (new_line(str, line, fd));
}
