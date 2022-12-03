/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusyamas <yuppiy2000@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 20:55:00 by yusyamas          #+#    #+#             */
/*   Updated: 2022/12/02 13:39:12 by yusyamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

unsigned int	my_strlen_line(char *str)
{
	unsigned int	length;

	length = 0;
	while (*str != '\n')
	{
		length++;
		str++;
	}
	return (length);
}

unsigned int	my_strlen(char *str)
{
	unsigned int	length;

	length = 0;
	while (*str != '\0')
	{
		length++;
		str++;
	}
	return (length);
}

unsigned int	count_digit(int num)
{
	unsigned int	digit;

	digit = 0;
	while (num != 0)
	{
		digit++;
		num /= 10;
	}
	return (digit);
}

int	my_strncmp(char *s1, char *s2, unsigned int n)
{
	int	ret;

	if (n == 0)
		return (0);
	while (n != 0)
	{
		if (*s1 != *s2)
		{
			ret = *(unsigned char *)s1 - *(unsigned char *)s2;
			return (ret);
		}
		if (*s1 == '\0')
			break ;
		s1++;
		s2++;
		n--;
	}
	return (0);
}

char	*my_to_string(int num, unsigned int len)
{
	char				*ret;
	unsigned long long	mark;
	int					digit;
	unsigned int		i;

	ret = malloc(sizeof(char) * (len + 1));
	digit = 0;
	while (len != 0)
	{
		mark = 1;
		i = 0;
		while (i < len - 1)
		{
			mark *= 10;
			i++;
		}
		ret[digit] = (num / mark) + '0';
		num %= mark;
		digit++;
		len--;
	}
	return (ret);
}
