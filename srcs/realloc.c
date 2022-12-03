/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusyamas <yuppiy2000@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:15:26 by yusyamas          #+#    #+#             */
/*   Updated: 2022/12/02 13:38:59 by yusyamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*my_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

unsigned int	my_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	srclen;

	srclen = my_strlen(src);
	if (srclen + 1 < size)
		my_memcpy(dest, src, srclen + 1);
	else if (size != 0)
	{
		my_memcpy(dest, src, size - 1);
		dest[size - 1] = '\0';
	}
	return (srclen);
}

char	*str_realloc(char *buff, unsigned int maxlen)
{
	char			*nxt_str;
	unsigned int	cpylen;

	nxt_str = (char *)malloc(sizeof(char) * maxlen);
	if (nxt_str == NULL)
		return (NULL);
	cpylen = my_strlcpy(nxt_str, buff, maxlen / 2);
	if (cpylen == 0)
		return (NULL);
	free(buff);
	return (nxt_str);
}

char	*str_read(int fd)
{
	unsigned int	len;
	unsigned int	maxlen;
	char			*buff;

	len = 0;
	maxlen = 16;
	buff = (char *)malloc(sizeof(char) * maxlen);
	if (buff == NULL)
		return (NULL);
	while (read(fd, &buff[len], 1) == 1)
	{
		len++;
		if (len + 1 == maxlen)
		{
			maxlen *= 2;
			buff = str_realloc(buff, maxlen);
			if (buff == NULL)
				return (NULL);
		}
	}
	buff[len] = '\0';
	return (buff);
}

char	*input_str(char *filename)
{
	int		fd;
	char	*buff;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	buff = str_read(fd);
	if (close(fd) == -1)
		return (NULL);
	return (buff);
}
