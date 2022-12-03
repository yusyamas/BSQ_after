/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusyamas <yuppiy2000@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 08:58:47 by yusyamas          #+#    #+#             */
/*   Updated: 2022/12/02 13:38:37 by yusyamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

int	max(int a, int b)
{
	if (a < b)
		return (b);
	else
		return (a);
}

int	grid_out_check(t_grid *grid, int i, int j)
{
	if (0 <= j && j < grid->x && 0 <= i && i < grid->y)
		return (1);
	else
		return (0);
}

int	coo_place(t_grid *panel, int i, int j)
{
	int	ret;

	ret = i * panel->x + j;
	return (ret);
}

int	biggest_square(t_answer *ans, int length, int place)
{
	if (length > ans->length)
		return (1);
	else if (length == ans->length && place < ans->place)
		return (1);
	return (0);
}
