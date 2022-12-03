/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusyamas <yuppiy2000@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 11:30:22 by yusyamas          #+#    #+#             */
/*   Updated: 2022/12/02 16:01:58 by yusyamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	count_col(t_grid *panel)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (panel->buff_map[i] != '\0')
	{
		if (panel->buff_map[i] == '\n')
			cnt++;
		i++;
	}
	return (cnt);
}

int	rule_check_3(t_grid *panel)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (!(32 <= panel->rule[i] && panel->rule[i] <= 126))
			return (0);
		i++;
	}
	if (panel->rule[0] == panel->rule[1])
		return (0);
	if (panel->rule[1] == panel->rule[2])
		return (0);
	if (panel->rule[2] == panel->rule[0])
		return (0);
	return (1);
}

int	rule_check(t_grid *panel)
{
	unsigned int	i;
	unsigned int	len;
	char			*str_y;

	len = count_digit(panel->y);
	if (len + 3 != my_strlen(panel->buff_head))
		return (0);
	str_y = my_to_string(panel->y, len);
	if (my_strncmp(panel->buff_head, str_y, len))
		return (0);
	free(str_y);
	i = my_strlcpy(panel->rule, &panel->buff_head[len], 4);
	(void)i;
	if (!rule_check_3(panel))
		return (0);
	return (1);
}

int	square_format_check(t_grid *panel)
{
	if (my_strlen(panel->buff_map) == 0)
		return (0);
	panel->y = count_col(panel);
	panel->x = my_strlen_line(panel->buff_map);
	if (!rule_check(panel))
		return (0);
	if (!map_check(panel))
		return (0);
	panel->flag = 2;
	return (1);
}
