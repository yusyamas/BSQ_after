/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusyamas <yuppiy2000@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:43:59 by yusyamas          #+#    #+#             */
/*   Updated: 2022/12/02 13:39:04 by yusyamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	sec_horiz(t_grid *panel, int i, int j, int length)
{
	int	ni;
	int	nj;

	ni = i + length;
	nj = j + length;
	while (nj >= j)
	{
		if (!grid_out_check(panel, ni, nj))
			return (0);
		if (panel->grid[ni][nj] == 1)
			return (0);
		nj--;
	}
	return (1);
}

int	sec_vert(t_grid *panel, int i, int j, int length)
{
	int	ni;
	int	nj;

	ni = i + length;
	nj = j + length;
	while (ni >= i)
	{
		if (!grid_out_check(panel, ni, nj))
			return (0);
		if (panel->grid[ni][nj] == 1)
			return (0);
		ni--;
	}
	return (1);
}

int	square_extend_check(t_grid *panel, int place, int length)
{
	int	i;
	int	j;

	i = place / panel->x;
	j = place % panel->x;
	if (!sec_horiz(panel, i, j, length))
		return (0);
	if (!sec_vert(panel, i, j, length))
		return (0);
	return (1);
}

int	square_length(t_grid *panel, int place)
{
	int	length;

	length = 0;
	while (length <= min(panel->x, panel->y))
	{
		if (!square_extend_check(panel, place, length))
			return (length);
		length++;
	}
	return (length - 1);
}

void	square_search(t_grid *panel, t_answer *ans)
{
	int	i;
	int	j;
	int	length;

	i = 0;
	while (i < panel->y)
	{
		j = 0;
		while (j < panel->x)
		{
			if (panel->grid[i][j] == 0)
			{
				length = square_length(panel, coo_place(panel, i, j));
				if (biggest_square(ans, length, coo_place(panel, i, j)))
				{
					ans->length = length;
					ans->place = coo_place(panel, i, j);
				}
			}
			if (search_end(panel, ans, i, j))
				return ;
			j++;
		}
		i++;
	}
}
