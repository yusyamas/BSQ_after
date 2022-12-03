/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusyamas <yuppiy2000@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 00:45:23 by yusyamas          #+#    #+#             */
/*   Updated: 2022/12/02 19:05:23 by yusyamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	search_end(t_grid *panel, t_answer *ans, int i, int j)
{
	int	len;

	len = 0;
	len = max(len, min(panel->y - i - 1, panel->x));
	len = max(len, min(panel->y - i, panel->x - j - 1));
	if (ans->length >= len)
		return (1);
	else
		return (0);
}

int	format_check_newline(char *buff)
{
	int	ret;

	ret = 0;
	while (*buff != '\0')
	{
		if (*buff == '\n')
			ret++;
		buff++;
	}
	return (ret);
}
