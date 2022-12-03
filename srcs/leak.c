/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leak.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusyamas <yuppiy2000@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 23:44:12 by yusyamas          #+#    #+#             */
/*   Updated: 2022/12/02 13:37:48 by yusyamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leak.h"

t_mem	g_mem_info[N];

void	leak_detect_init(void)
{
	int	i;

	i = 0;
	while (i < N)
	{
		g_mem_info[i].ptr = NULL;
		g_mem_info[i].size = 0;
		g_mem_info[i].file = NULL;
		g_mem_info[i].line = 0;
		i++;
	}
}

void	*leak_detelc_malloc(size_t size, const char *file, unsigned int line)
{
	int		i;
	void	*ptr;

	i = 0;
	ptr = NULL;
	ptr = malloc(size);
	if (ptr == NULL)
		return (NULL);
	while (i < N)
	{
		if (g_mem_info[i].ptr == NULL)
		{
			g_mem_info[i].ptr = ptr;
			g_mem_info[i].size = size;
			g_mem_info[i].file = file;
			g_mem_info[i].line = line;
			break ;
		}
		i++;
	}
	return (ptr);
}

void	leak_detect_free(void *ptr)
{
	int	i;

	i = 0;
	while (i < N)
	{
		if (g_mem_info[i].ptr == ptr)
		{
			g_mem_info[i].ptr = NULL;
			g_mem_info[i].size = 0;
			g_mem_info[i].file = NULL;
			g_mem_info[i].line = 0;
			break ;
		}
		i++;
	}
	free(ptr);
}

void	leak_detect_check(void)
{
	int	i;

	i = 0;
	while (i < N)
	{
		if (g_mem_info[i].ptr != NULL)
		{
			printf("メモリリークを検出!!!!!\n");
			printf(" アドレス:%p\n", g_mem_info[i].ptr);
			printf(" サイズ:%u\n", (unsigned int)g_mem_info[i].size);
			printf(" 場所:%s:%u\n", g_mem_info[i].file, g_mem_info[i].line);
			printf("\n");
		}
		i++;
	}
}
