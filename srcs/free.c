/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusyamas <yuppiy2000@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:30:19 by yusyamas          #+#    #+#             */
/*   Updated: 2022/12/02 16:13:30 by yusyamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	free_grid(t_grid *panel)
{
	int	i;

	free(panel->rule);
	if (panel->flag >= 1)
	{
		free(panel->buff_head);
		free(panel->buff_map);
	}
	if (panel->flag == 2)
	{
		i = 0;
		while (i < panel->y)
		{
			free(panel->grid[i]);
			i++;
		}
		free(panel->grid);
	}
}

void	free_print_grid(t_grid *panel, char **ans)
{
	int	i;

	i = 0;
	while (i < panel->y)
	{
		free(ans[i]);
		i++;
	}
	free(ans);
}

void	free_state(t_grid *panel, int i, int argc)
{
	free_grid(panel);
	if (i != argc - 1)
		ft_putchar('\n');
}
