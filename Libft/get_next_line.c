/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 11:42:25 by tarchimb          #+#    #+#             */
/*   Updated: 2021/11/26 13:25:51 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_free(char *buf, char *save)
{
	free(buf);
	if (save != NULL)
		return (save);
	return (NULL);
}

char	*ft_save(char *save, int fd)
{
	char	*buf;
	int		iread;
	char	*tmp;

	iread = 1;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (ft_strchr(save, '\n') == 0 && iread > 0)
	{
		iread = read(fd, buf, BUFFER_SIZE);
		if (iread <= 0)
			return (ft_free(buf, save));
		buf [iread] = '\0';
		tmp = save;
		save = ft_strjoin_gnl(save, buf);
		free(tmp);
		if (!save)
			return (NULL);
	}
	free(buf);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save[OPEN_MAX];
	char		*dest;
	char		*tmp;

	dest = NULL;
	if (fd < 0 || fd > OPEN_MAX)
		return (NULL);
	save[fd] = ft_save(save[fd], fd);
	if (save[fd] == NULL)
		return (NULL);
	dest = ft_substr_gnl(save[fd], 0, ft_strchr_len(save[fd], '\n'));
	tmp = save[fd];
	save[fd] = ft_substr_gnl(save[fd], ft_strchr_len(save[fd], '\n'),
			ft_strlen(save[fd]) - ft_strchr_len(save[fd], '\n'));
	if (save[fd] && !*save[fd])
	{
		free(save[fd]);
		save[fd] = NULL;
	}
	free(tmp);
	return (dest);
}
