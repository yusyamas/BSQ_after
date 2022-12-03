/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusyamas <yuppiy2000@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 22:49:37 by yusyamas          #+#    #+#             */
/*   Updated: 2022/12/02 13:38:29 by yusyamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	map_char_check(t_grid *panel)
{
	int		i;
	char	*str;

	i = 0;
	str = panel->buff_map;
	while (str[i] != '\0')
	{
		if (str[i] != '\n')
		{
			if (!(str[i] == panel->rule[0] || str[i] == panel->rule[1]))
				return (0);
		}
		i++;
	}
	return (1);
}

int	map_check(t_grid *panel)
{
	int	i;
	int	cnt;

	if (!map_char_check(panel))
		return (0);
	cnt = 0;
	i = 0;
	while (panel->buff_map[i] != '\0')
	{
		if (panel->buff_map[i] == '\n')
		{
			if (panel->x != cnt)
				return (0);
			cnt = 0;
		}
		else
			cnt++;
		i++;
	}
	return (1);
}

int	**malloc_grid(t_grid *panel)
{
	int	**ret;
	int	i;

	ret = malloc(sizeof(int *) * panel->y);
	i = 0;
	while (i < panel->y)
	{
		ret[i] = malloc(sizeof(int) * panel->x);
		i++;
	}
	return (ret);
}

int	panel_decide(t_grid *panel, char c)
{
	int	i;
	int	ret;

	i = 0;
	while (i < 3)
	{
		if (panel->rule[i] == c)
			ret = i;
		i++;
	}
	return (ret);
}

int	**init_grid(t_grid *panel)
{
	int		i;
	int		j;
	int		**ret;
	char	*c;

	i = 0;
	j = 0;
	ret = malloc_grid(panel);
	c = panel->buff_map;
	while (*c != '\0')
	{
		if (*c != '\n')
		{
			ret[i][j] = panel_decide(panel, *c);
			j++;
		}
		else
		{
			i++;
			j = 0;
		}
		c++;
	}
	return (ret);
}
