/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusyamas <yuppiy2000@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 01:02:17 by yusyamas          #+#    #+#             */
/*   Updated: 2022/12/02 13:38:52 by yusyamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	write_grid(t_grid *panel, char **ans)
{
	int	i;
	int	j;

	i = 0;
	while (i < panel->y)
	{
		j = 0;
		while (j <= panel->x)
		{
			write(1, &ans[i][j], 1);
			j++;
		}
		i++;
	}
}

void	decide_grid(t_grid *panel, t_answer *answer, char **ans)
{
	int	i;
	int	j;
	int	di;
	int	dj;

	i = answer->place / panel->x;
	j = answer->place % panel->x;
	di = 0;
	while (di < answer->length)
	{
		dj = 0;
		while (dj < answer->length)
		{
			ans[i + di][j + dj] = panel->rule[2];
			dj++;
		}
		di++;
	}
}

void	init_ans(t_grid *panel, char **ans)
{
	int	i;
	int	j;

	i = 0;
	while (i < panel->y)
	{
		j = 0;
		while (j <= panel->x)
		{
			if (j == panel->x)
				ans[i][j] = '\n';
			else if (panel->grid[i][j] == 0)
				ans[i][j] = panel->rule[0];
			else if (panel->grid[i][j] == 1)
				ans[i][j] = panel->rule[1];
			j++;
		}
		i++;
	}
}

void	print_grid(t_grid *panel, t_answer *answer)
{
	char	**ans;
	int		di;

	ans = malloc(sizeof(char *) * panel->y);
	di = 0;
	while (di < panel->y)
	{
		ans[di] = malloc(sizeof(char) * (panel->x + 1));
		di++;
	}
	init_ans(panel, ans);
	decide_grid(panel, answer, ans);
	write_grid(panel, ans);
	free_print_grid(panel, ans);
}
